#include "stdafx.h"
#include "Config.h"
#include "SceneManager.h"
#include "GameEntity.h"

GameEntity* SceneManager::currScene = nullptr; // 이전 씬
GameEntity* SceneManager::readyScene = nullptr; // 지금 쓰는 씬
GameEntity* SceneManager::loadingScene = nullptr;

DWORD CALLBACK LoadingThread(LPVOID pvParam)
{
	// 레디씬을 초기화한다.
	SceneManager::readyScene->Init();
	SceneManager::currScene = SceneManager::readyScene;

	SceneManager::loadingScene->Release();
	SceneManager::loadingScene = nullptr;
	SceneManager::readyScene = nullptr;


	return 0;
}

void SceneManager::Init()
{
}

void SceneManager::Release()
{
	if (currScene) { currScene->Release(); }

	for (map<eSceneTag, GameEntity*>::iterator it = mapScenes.begin(); it != mapScenes.end();)
	{
		SAFE_DELETE(it->second);
		it = mapScenes.erase(it);
	}
	mapScenes.clear();
}

void SceneManager::Update()
{
	if (currScene)
		currScene->Update();
}

void SceneManager::Render(HDC hdc)
{
	if (currScene)
		currScene->Render(hdc);
}

void SceneManager::AddScene(eSceneTag tag, GameEntity* scene)
{
	if (scene == nullptr)	return;

	if (mapScenes.find(tag) != mapScenes.end())
	{
		return;
	}

	mapScenes.insert(pair<eSceneTag, GameEntity*>(tag, scene));

}

void SceneManager::AddLoadingScene(eSceneTag tag, GameEntity* scene)
{
	if (scene == nullptr)	return;

	if (mapLoadingScenes.find(tag) != mapLoadingScenes.end())
	{
		return;
	}

	mapLoadingScenes.insert(pair<eSceneTag, GameEntity*>(tag, scene));
}

void SceneManager::SetSceneData(string key, int val)
{
	mapSceneData[key] = val;
}

int SceneManager::GetSceneData(string key)
{
	return mapSceneData[key];
}

// 사용하는 함수
HRESULT SceneManager::ChangeScene(eSceneTag tag)
{
	map<eSceneTag, GameEntity*>::iterator it = mapScenes.find(tag);

	if (it == mapScenes.end())
		return E_FAIL;

	if (SUCCEEDED((it->second)->Init()))
	{
		if (currScene)
			currScene->Release();

		currScene = it->second;

		return S_OK;
	}

	return E_FAIL;
}

HRESULT SceneManager::ChangeScene(eSceneTag tag, eSceneTag loadingSceneName)
{
	map<eSceneTag, GameEntity*>::iterator it = mapScenes.find(tag);

	if (it == mapScenes.end())
		return E_FAIL;

	// 로딩씬 확인
	map<eSceneTag, GameEntity*>::iterator itLoading = mapLoadingScenes.find(loadingSceneName);
	if (itLoading == mapLoadingScenes.end())
	{
		return ChangeScene(tag);
	}

	// 로딩씬 있을 때
	if (SUCCEEDED((itLoading->second)->Init()))
	{
		if (currScene)
			currScene->Release();

		readyScene = it->second;
		loadingScene = itLoading->second;

		currScene = loadingScene;

		// 멀티쓰레드 처리
		DWORD loadThread;
		HANDLE hThread = CreateThread(NULL, 0,
			LoadingThread/*실행 시킬 함수포인터(함수이름)*/,
			NULL /*실행 시킬 함수에 들어갈 매개변수*/,
			0, &loadThread);

		CloseHandle(hThread);

		return S_OK;
	}

	return E_FAIL;
}
