#include "stdafx.h"
#include "Config.h"
#include "MainGame.h"
#include "Image.h"
#include "CommonFunction.h"
#include "Jiwoo.h"
#include "PokemonManager.h"
#include "MapManager.h"


 //#define TILETOOL

HRESULT MainGame::Init()
{
	Input::Init(g_hWnd);
	Timer::Init();
	IMG_MGR->Init();
	SCENE_MGR->Init();
	TXT_MGR->Init();
	ITEM_MGR->Init();
	CON_MGR->Init();
	POKE_MGR->Init();
	

	// 타이머 셋팅
	mousePosX = 0;
	mousePosY = 0;
	clickedMousePosX = 0;
	clickedMousePosY = 0;

	// 백버퍼 맥스사이즈 다시보기
	backBuffer = new Image();
	//AddFontResource("gsc.ttf");

	//LOGFONT lf = {};
	//lf.lfHeight = -MulDiv(15, GetDeviceCaps(backBuffer->GetMemDC(), LOGPIXELSY), 72);
	//lf.lfWeight = FW_NORMAL;
	//strcpy_s(lf.lfFaceName, TEXT("PokemonGSC"));
	//font = CreateFontIndirect(&lf);
	
	/*font = CreateFont(50, 0, 0, 0, 400, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
		18, TEXT("PokemonGSC"));
	oldFont = (HFONT)SelectObject(backBuffer->GetMemDC(), font);*/
	
	// oldFont는 보관해두고
	// Release() 에서 font = (HFONT)SelectObject(backBuffer->GetMemDC(), oldFont);
	// DeleteObject(font);
#ifdef TILETOOL
	SCENE_MGR->ChangeScene(eSceneTag::MapToolScene);
	POINT g_maxSize = {TILE_MAP_TOOL_X, TILE_MAP_TOOL_Y};

#else
	SCENE_MGR->ChangeScene(eSceneTag::CenterScene);
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
	SetTextColor(backBuffer->GetMemDC(), RGB(0, 0, 0));
	SetBkColor(hdc, RGB(248, 248, 248));
	SetBkMode(hdc, TRANSPARENT);
	font = CreateFont(40, 0, 0, 0, 700, 0, 0, 0, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
		DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));
	oldFont = (HFONT)SelectObject(backBuffer->GetMemDC(), font);
	
	HDC hBackBufferDC = backBuffer->GetMemDC();
	PatBlt(hBackBufferDC, 0, 0, backBuffer->GetWidth(), backBuffer->GetHeight(), WHITENESS);

	SCENE_MGR->Render(hBackBufferDC);
	SelectObject(backBuffer->GetMemDC(), oldFont);
	DeleteObject(font);
	backBuffer->Render(hdc);
	
}

void MainGame::Release()
{
	SAFE_RELEASE(backBuffer);

	SCENE_MGR->Release();
	SCENE_MGR->ReleaseSingleton();

	IMG_MGR->Release();
	IMG_MGR->ReleaseSingleton();

	TXT_MGR->ReleaseSingleton();

	CON_MGR->Release();
	CON_MGR->ReleaseSingleton();

	ITEM_MGR->ReleaseSingleton();

	POKE_MGR->Release();
	POKE_MGR->ReleaseSingleton();

	MAP_MGR->ReleaseSingleton();

	KillTimer(g_hWnd, 0);
}
