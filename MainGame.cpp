#include "stdafx.h"
#include "Config.h"
#include "MainGame.h"
#include "Image.h"
#include "CommonFunction.h"
#include "TestScene.h"
#include "MapScene.h"
#include "OpeningScene.h"
#include "CityScene.h"

//#define TILETOOL

HRESULT MainGame::Init()
{
	Input::Init(g_hWnd);
	Timer::Init();
	IMG_MGR->Init();
	SCENE_MGR->Init();

	SCENE_MGR->AddScene(eSceneTag::TestScene, new TestScene);
	SCENE_MGR->AddScene(eSceneTag::MapToolScene, new MapScene);
	SCENE_MGR->AddScene(eSceneTag::OpeningScene, new OpeningScene);
	SCENE_MGR->AddScene(eSceneTag::CityScene, new CityScene);

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
	SCENE_MGR->ChangeScene(eSceneTag::TestScene);
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


//LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	switch (iMessage)
//	{
//	case WM_SIZE:
//		SetWindowSize(WIN_START_POS_X, WIN_START_POS_Y, WIN_SIZE_X, WIN_SIZE_Y);
//		break;
//	case WM_LBUTTONDOWN:
//		clickedMousePosX = LOWORD(lParam);
//		clickedMousePosY = HIWORD(lParam);
//		break;
//	case WM_LBUTTONUP:
//		break;
//	case WM_RBUTTONDOWN:
//		break;
//	case WM_MOUSEMOVE:
//		Input::GetMousePosition().x = LOWORD(lParam);
//		Input::GetMousePosition().y = HIWORD(lParam);
//		break;
//	}
//	return DefWindowProc(hWnd, iMessage, wParam, lParam);
//}
