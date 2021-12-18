#include "stdafx.h"
#include "IngameMap.h"
//#include "MapEditor.h"
#include "CameraManager.h"
#include "Image.h"
#include "CommonFunction.h"
#include "Jiwoo.h"
#include <cmath>
#include <map>

HRESULT IngameMap::Init()
{
	mDrawTileImage = IMG_MGR->FindImage(eImageTag::DrawTile);
	mBackground = IMG_MGR->FindImage(eImageTag::Background);

	mbControl = true;

	mTestJiwoo = new Jiwoo;
	mTestJiwoo->Init();

	mMoveSpeed = 600;
	mMovePixel = { 0,0 };

	mOneTileTime = 0.3f;

	// 그릴영역 전체(1타일당 64픽셀)
	for (int i = 0; i < TILE_COUNT_Y; ++i)
	{
		for (int j = 0; j < TILE_COUNT_X; ++j)
		{
			SetRect(&(mTileInfo[i * TILE_COUNT_X + j].Rc),
				j * TILE_SIZE + CAM_MGR->GetCamPos().x,
				i * TILE_SIZE + CAM_MGR->GetCamPos().y,
				TILE_SIZE + j * TILE_SIZE + CAM_MGR->GetCamPos().x,
				TILE_SIZE + i * TILE_SIZE + CAM_MGR->GetCamPos().y);

			mTileInfo[i * TILE_COUNT_X + j].TilePos.x = 11;
			mTileInfo[i * TILE_COUNT_X + j].TilePos.y = 2;

			mTileInfo[i * TILE_COUNT_X + j].Terrain = eTerrain::Close;
		}
	}



	// 그릴영역 크기(1타일당 64픽셀)
	mDrawArea.left = 0;
	mDrawArea.top = 0;
	mDrawArea.right = TILE_SIZE * 15; // 960
	mDrawArea.bottom = TILE_SIZE * 15; //960

	return S_OK;
}

void IngameMap::Update()
{

	SAFE_UPDATE(mTestJiwoo);

}

void IngameMap::Render(HDC hdc)
{
	mBackground->Render(hdc);

	//타일 그리기

	for (int i = 0; i < TILE_COUNT_Y; ++i)
	{
		for (int j = 0; j < TILE_COUNT_X; ++j)
		{

			if (mTileInfo[i * TILE_COUNT_X + j].Rc.right + CAM_MGR->GetCamPos().x <= (SAMPLE_TILE_COUNT_X)*TILE_SIZE
				&& mTileInfo[i * TILE_COUNT_X + j].Rc.bottom + CAM_MGR->GetCamPos().y <= (SAMPLE_TILE_COUNT_Y)*TILE_SIZE)
			{
				Rectangle(hdc, j * TILE_SIZE + CAM_MGR->GetCamPos().x,
					i * TILE_SIZE + +CAM_MGR->GetCamPos().y,
					TILE_SIZE + j * TILE_SIZE + CAM_MGR->GetCamPos().x,
					TILE_SIZE + i * TILE_SIZE + CAM_MGR->GetCamPos().y);

				mDrawTileImage->Render(hdc,
					mTileInfo[i * TILE_COUNT_X + j].Rc.left + TILE_SIZE / 2 + CAM_MGR->GetCamPos().x,
					mTileInfo[i * TILE_COUNT_X + j].Rc.top + TILE_SIZE / 2 + CAM_MGR->GetCamPos().y,
					mTileInfo[i * TILE_COUNT_X + j].TilePos.x,
					mTileInfo[i * TILE_COUNT_X + j].TilePos.y);

				//cout << (int)mTileInfo[0].Terrain << endl;

				Rectangle(hdc, (SAMPLE_TILE_COUNT_X - 1) * TILE_SIZE, 0, SAMPLE_TILE_COUNT_X * TILE_SIZE, SAMPLE_TILE_COUNT_Y * TILE_SIZE);
				Rectangle(hdc, 0, (SAMPLE_TILE_COUNT_Y - 1) * TILE_SIZE, SAMPLE_TILE_COUNT_X * TILE_SIZE, SAMPLE_TILE_COUNT_Y * TILE_SIZE);
			}

		}
	}


	// 테스트 지우
	mTestJiwoo->Render(hdc);
}

void IngameMap::Release()
{
	SAFE_RELEASE(mTestJiwoo);
}

void IngameMap::LoadMap(string index)
{
	string loadFileName = "Save/saveMapData_" + index;
	loadFileName += ".map";
	DWORD mapSaveTileInfo = sizeof(TagTile) * TILE_COUNT_X * TILE_COUNT_Y;

	HANDLE hFile = CreateFile(loadFileName.c_str(),
		GENERIC_READ,
		0, NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	DWORD readByte;
	if (ReadFile(hFile, mTileInfo, mapSaveTileInfo,
		&readByte, NULL) == false)
	{
		MessageBox(g_hWnd, "맵 데이터 로드에 실패했습니다.", "에러", MB_OK);
	}

	CloseHandle(hFile);
}
