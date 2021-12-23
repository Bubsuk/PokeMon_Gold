#include "stdafx.h"
#include "Config.h"
#include "MainGame.h"
#include "Image.h"
#include "CommonFunction.h"
#include "TestScene.h"
#include "MapScene.h"
#include "OpeningScene.h"
#include "CityScene.h"
#include "Home1stScene.h"
#include "Home2ndScene.h"
#include "CenterScene.h"
#include "MartScene.h"
#include "GymScene.h"
#include "DrOLabScene.h"
#include "BattleScene.h"


// #define TILETOOL

HRESULT MainGame::Init()
{
	Input::Init(g_hWnd);
	Timer::Init();
	IMG_MGR->Init();
	SCENE_MGR->Init();

	SCENE_MGR->AddScene(eSceneTag::TestScene, new TestScene);
	SCENE_MGR->AddScene(eSceneTag::MapToolScene, new MapScene);
	SCENE_MGR->AddScene(eSceneTag::OpeningScene, new OpeningScene);
	SCENE_MGR->AddScene(eSceneTag::Home1stScene, new Home1stScene);
	SCENE_MGR->AddScene(eSceneTag::Home2ndScene, new Home2ndScene);
	SCENE_MGR->AddScene(eSceneTag::CityScene, new CityScene);
	SCENE_MGR->AddScene(eSceneTag::CenterScene, new CenterScene);
	SCENE_MGR->AddScene(eSceneTag::MartScene, new MartScene);
	SCENE_MGR->AddScene(eSceneTag::GymScene, new GymScene);
	SCENE_MGR->AddScene(eSceneTag::DrOScene, new DrOLabScene);
	SCENE_MGR->AddScene(eSceneTag::BattleScene, new BattleScene);
	

	// 타이머 셋팅
	mousePosX = 0;
	mousePosY = 0;
	clickedMousePosX = 0;
	clickedMousePosY = 0;

	// 백버퍼 맥스사이즈 다시보기
	backBuffer = new Image();

#ifdef TILETOOL
	SCENE_MGR->ChangeScene(eSceneTag::MapToolScene);
	POINT g_maxSize = {TILE_MAP_TOOL_X, TILE_MAP_TOOL_Y};

#else
	SCENE_MGR->ChangeScene(eSceneTag::DrOScene);
	POINT g_maxSize = { WIN_SIZE_X, WIN_SIZE_Y };

#endif

	SetWindowSize(40, 40, g_maxSize.x, g_maxSize.y);
	backBuffer->Init("Image/mapImage.bmp", g_maxSize.x, g_maxSize.y);

	return S_OK;
}

void MainGame::Update()
{
	SCENE_MGR->Update();
}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = backBuffer->GetMemDC();
	PatBlt(hBackBufferDC, 0, 0, backBuffer->GetWidth(), backBuffer->GetHeight(), WHITENESS);

	SCENE_MGR->Render(hBackBufferDC);

	backBuffer->Render(hdc);
}

void MainGame::Release()
{
	SAFE_RELEASE(backBuffer);

	SCENE_MGR->Release();
	SCENE_MGR->ReleaseSingleton();

	IMG_MGR->Release();
	IMG_MGR->ReleaseSingleton();

	KillTimer(g_hWnd, 0);
}
