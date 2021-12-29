#include "stdafx.h"
#include "MapEditor.h"
#include "CameraManager.h"
#include "Image.h"
#include "CommonFunction.h"
#include "Jiwoo.h"
#include "Enum.h"
#include <cmath>
#include <map>

HRESULT MapEditor::Init()
{
	//AddFontResource("gsc.ttf");

	

	mSampleTileImage = IMG_MGR->FindImage(eImageTag::SampleTile);
	mDrawTileImage = IMG_MGR->FindImage(eImageTag::DrawTile);
	mBackground = IMG_MGR->FindImage(eImageTag::Background);

	mbControl = true;

	mTestJiwoo = new Jiwoo;
	mTestJiwoo->Init();
	
	if (mSampleTileImage == nullptr)
	{
		cout << "SmapleTile 로드 실패" << '\n';
		return E_FAIL;
	}

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
	

	// 오른쪽 상단 샘플영역(1타일당 40픽셀)
	for (int i = 0; i < SAMPLE_TILE_COUNT_Y; ++i)
	{
		for (int j = 0; j < SAMPLE_TILE_COUNT_X; ++j)
		{
			SetRect(&(mSampleTileInfo[i * SAMPLE_TILE_COUNT_X + j].Rc),
				TILE_MAP_TOOL_X - mSampleTileImage->GetWidth() + j * SAMPLE_TILE_SIZE,
				i * SAMPLE_TILE_SIZE,
				TILE_MAP_TOOL_X - mSampleTileImage->GetWidth() + j * SAMPLE_TILE_SIZE + SAMPLE_TILE_SIZE,
				i * SAMPLE_TILE_SIZE + SAMPLE_TILE_SIZE);

			mSampleTileInfo[i * SAMPLE_TILE_COUNT_X + j].TilePos.x = j;
			mSampleTileInfo[i * SAMPLE_TILE_COUNT_X + j].TilePos.y = i;

			// 타일별 속성 지정
			if ((0 <= (i * SAMPLE_TILE_COUNT_X + j) && (i * SAMPLE_TILE_COUNT_X + j) <= 7) || (i * SAMPLE_TILE_COUNT_X + j) == 9
				|| (50 <= (i * SAMPLE_TILE_COUNT_X + j)
				&& (i * SAMPLE_TILE_COUNT_X + j) <= 52) || (i * SAMPLE_TILE_COUNT_X + j) == 58 || (i * SAMPLE_TILE_COUNT_X + j) == 77
				|| (i * SAMPLE_TILE_COUNT_X + j) == 78 || (i * SAMPLE_TILE_COUNT_X + j) == 80 || (i * SAMPLE_TILE_COUNT_X + j) == 158
				|| (i * SAMPLE_TILE_COUNT_X + j) == 159 || (i * SAMPLE_TILE_COUNT_X + j) == 160 
				|| (176 <= (i * SAMPLE_TILE_COUNT_X + j) && (i * SAMPLE_TILE_COUNT_X + j) <= 178)
				|| (191 <= (i * SAMPLE_TILE_COUNT_X + j) && (i * SAMPLE_TILE_COUNT_X + j) <= 193) || (206 <= (i * SAMPLE_TILE_COUNT_X + j)
				&& (i * SAMPLE_TILE_COUNT_X + j) <= 208) || (i * SAMPLE_TILE_COUNT_X + j) == 211 || (i * SAMPLE_TILE_COUNT_X + j) == 202 
				|| (i * SAMPLE_TILE_COUNT_X + j) == 203)
			{
				mSampleTileInfo[i * SAMPLE_TILE_COUNT_X + j].Terrain = eTerrain::Open;
			}
			else if ((i * SAMPLE_TILE_COUNT_X + j) == 8) 
			{
				mSampleTileInfo[i * SAMPLE_TILE_COUNT_X + j].Terrain = eTerrain::Grass;
			}
			else if ((21 <= (i * SAMPLE_TILE_COUNT_X + j) && (i * SAMPLE_TILE_COUNT_X + j) <= 25 || (i * SAMPLE_TILE_COUNT_X + j) == 112
					|| (i * SAMPLE_TILE_COUNT_X + j) == 162))
			{
				mSampleTileInfo[i * SAMPLE_TILE_COUNT_X + j].Terrain = eTerrain::Door;
			}
			else if ((i * SAMPLE_TILE_COUNT_X + j) == 16 || (i * SAMPLE_TILE_COUNT_X + j) == 17)
			{
				mSampleTileInfo[i * SAMPLE_TILE_COUNT_X + j].Terrain = eTerrain::BottomBlock;
			}
			else if ((i * SAMPLE_TILE_COUNT_X + j) == 18)
			{
				mSampleTileInfo[i * SAMPLE_TILE_COUNT_X + j].Terrain = eTerrain::RightBlock;
			}
			else if ((i * SAMPLE_TILE_COUNT_X + j) == 15)
			{
				mSampleTileInfo[i * SAMPLE_TILE_COUNT_X + j].Terrain = eTerrain::LeftBlock;
			}
			else
			{
				mSampleTileInfo[i * SAMPLE_TILE_COUNT_X + j].Terrain = eTerrain::Close;
			}

		}
	}

	// 샘플영역 크기(1타일당 40픽셀)
	mSampleArea.left = TILE_MAP_TOOL_X - mSampleTileImage->GetWidth();
	mSampleArea.top = 0;
	mSampleArea.right = TILE_MAP_TOOL_X;
	mSampleArea.bottom = mSampleTileImage->GetHeight();

	// 그릴영역 크기(1타일당 64픽셀)
	mDrawArea.left = 0;
	mDrawArea.top = 0;
	mDrawArea.right = TILE_SIZE * 15; // 960
	mDrawArea.bottom = TILE_SIZE * 15; //960
	
	return S_OK;
}

void MapEditor::Update()
{
		
	// 저장 부분
	if (Input::GetButton(VK_CONTROL) && Input::GetButtonDown('S'))
	{
			cout << "저장 할 파일명 : ";
			cin >> mSaveIndex;
			cout << "\"" << mSaveIndex << "\"" << "에 저장됩니다" << '\n';
			SaveMap(mSaveIndex);

	}
	if (Input::GetButton(VK_LSHIFT))
	{
		if (Input::GetButtonDown('S'))
		{
			cout << "불러 올 파일명 : ";
			cin >> mSaveIndex;
			cout << "\"" << mSaveIndex << "\"" << "을 불러옵니다" << '\n';
			LoadMap(mSaveIndex);
		}
	}


	// 드래그 시작
	if (Input::GetButtonDown(VK_LBUTTON))
	{
		if (PtInRect(&(mSampleArea), Input::GetMousePosition()))
		{
			mbIsClick = true;
			// 샘플영역 클릭 시작좌표
			mClickStart.x = (Input::GetMousePosition().x - mSampleArea.left) / SAMPLE_TILE_SIZE;
			mClickStart.y = Input::GetMousePosition().y / SAMPLE_TILE_SIZE;
			// 클릭 드래그 영역 시작값 1로 설정
			mClickArea.x = 1;
			mClickArea.y = 1;
		}
	}
	// 드래그 끝
	if (Input::GetButtonUp(VK_LBUTTON))
	{
		if (PtInRect(&(mSampleArea), Input::GetMousePosition()) && mbIsClick == true)
		{
			// 클릭 종료시 좌표
			mCLickEnd = POINT{ (Input::GetMousePosition().x - mSampleArea.left) / SAMPLE_TILE_SIZE, (Input::GetMousePosition().y - mSampleArea.top) / SAMPLE_TILE_SIZE };
			// 드래그 영역 좌표
			mClickArea.x = fabs(mClickStart.x -  mCLickEnd.x);
			mClickArea.y= fabs(mClickStart.y - mCLickEnd.y);
		}
		mbIsClick = false;
	}

	// 그리는 영역 타일정보 업데이트
	if (Input::GetButton(VK_LBUTTON))
	{
		if (PtInRect(&(mDrawArea), Input::GetMousePosition()))
		{
			// 그리는 영역 내 좌표
			POINT clickPos
				= { (Input::GetMousePosition().x - CAM_MGR->GetCamPos().x) / TILE_SIZE,
				(Input::GetMousePosition().y - CAM_MGR->GetCamPos().y) / TILE_SIZE };
			
			for (int i = 0; i <= mClickArea.y; ++i)
			{
				for (int j = 0; j <= mClickArea.x; ++j)
				{
					// 클릭 좌표가 오른쪽으로 범위가 넘어갈 경우 예외처리
					if ((clickPos.x + j + 1) > (mDrawArea.right + CAM_MGR->GetCamPos().x / TILE_SIZE)) break;

					mTileInfo[(clickPos.y + i) * TILE_COUNT_X + (clickPos.x + j)].TilePos.x = mClickStart.x + j;
					mTileInfo[(clickPos.y + i) * TILE_COUNT_X + (clickPos.x + j)].TilePos.y = mClickStart.y + i;
					mTileInfo[(clickPos.y + i) * TILE_COUNT_X + (clickPos.x + j)].Terrain =
						mSampleTileInfo[(mClickStart.y + i) * SAMPLE_TILE_COUNT_X + (mClickStart.x + j)].Terrain;
				}
			}
		}
	}

	SAFE_UPDATE(mTestJiwoo);
}

void MapEditor::Render(HDC hdc)
{
	
	mBackground->Render(hdc);

	// 그리는 영역 표시
	Rectangle(hdc, 0, 0, SAMPLE_TILE_COUNT_X * TILE_SIZE, SAMPLE_TILE_COUNT_X * TILE_SIZE);

	//타일 그리기
	
	for (int i = 0; i < TILE_COUNT_Y; ++i)
	{
		for (int j = 0; j < TILE_COUNT_X; ++j)
		{
			
			if (mTileInfo[i * TILE_COUNT_X + j].Rc.right + CAM_MGR->GetCamPos().x <= (SAMPLE_TILE_COUNT_X) * TILE_SIZE
				&& mTileInfo[i * TILE_COUNT_X + j].Rc.bottom + CAM_MGR->GetCamPos().y <= (SAMPLE_TILE_COUNT_Y) * TILE_SIZE)
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

			

				Rectangle(hdc, (SAMPLE_TILE_COUNT_X - 1) * TILE_SIZE, 0, SAMPLE_TILE_COUNT_X * TILE_SIZE, SAMPLE_TILE_COUNT_Y * TILE_SIZE);
				Rectangle(hdc, 0, (SAMPLE_TILE_COUNT_Y - 1) * TILE_SIZE, SAMPLE_TILE_COUNT_X * TILE_SIZE, SAMPLE_TILE_COUNT_Y * TILE_SIZE);
			}
			
		}
	}

	// 전체 샘플 영역
	mSampleTileImage->Render(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth() + mSampleTileImage->GetWidth() / 2,
		mSampleTileImage->GetWidth() / 2);

	// 선택 타일 표시영역
	for (int i = 0; i <= mClickArea.y ; ++i)
	{
		for (int j = 0; j <= mClickArea.x; ++j)
		{
			mSampleTileImage->Render(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth() + mSampleTileImage->GetWidth() / 2 + j * SAMPLE_TILE_SIZE,
				mSampleTileImage->GetHeight() + mSampleTileImage->GetFrameHeight() / 2 + 50 + i * SAMPLE_TILE_SIZE,
				mClickStart.x + j, mClickStart.y + i);
		}
	}

	// 테스트 지우(컨트롤)
	mTestJiwoo->Render(hdc);
	 
	hFont = CreateFont(15, 0, 0, 0, 400, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
		18, TEXT("PokemonGSC"));
	HFONT oldFont = (HFONT)SelectObject(hdc, hFont);
	// 샘플타일넘버
	wsprintf(mSampleText, "샘플 타일 인덱스 : %d", mClickStart.y * SAMPLE_TILE_COUNT_X + mClickStart.x);
	TextOut(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth(), mSampleTileImage->GetHeight() + 120, mSampleText, strlen(mSampleText));

	// 선택 타일 속성 표기
	wsprintf(mSampleText, "Tile Terrain : %d", (int)mSampleTileInfo[mClickStart.y * SAMPLE_TILE_COUNT_X + mClickStart.x].Terrain);
	TextOut(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth(), mSampleTileImage->GetHeight() + 150, mSampleText, strlen(mSampleText));

	wsprintf(mSampleText, "Open = 0");
	TextOut(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth(), mSampleTileImage->GetHeight() + 180, mSampleText, strlen(mSampleText));
	wsprintf(mSampleText, "Grass = 1");
	TextOut(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth(), mSampleTileImage->GetHeight() + 200, mSampleText, strlen(mSampleText));
	wsprintf(mSampleText, "Close = 2");
	TextOut(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth(), mSampleTileImage->GetHeight() + 220, mSampleText, strlen(mSampleText));
	wsprintf(mSampleText, "Door = 3");
	TextOut(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth(), mSampleTileImage->GetHeight() + 240, mSampleText, strlen(mSampleText));
	wsprintf(mSampleText, "BottomBlock = 4");
	TextOut(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth(), mSampleTileImage->GetHeight() + 260, mSampleText, strlen(mSampleText));
	wsprintf(mSampleText, "RightBlock = 5");
	TextOut(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth(), mSampleTileImage->GetHeight() + 280, mSampleText, strlen(mSampleText));
	wsprintf(mSampleText, "LeftBlock = 6");
	TextOut(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth(), mSampleTileImage->GetHeight() + 300, mSampleText, strlen(mSampleText));

	SelectObject(hdc, oldFont);
	DeleteObject(hFont);
}

void MapEditor::Release()
{
	SAFE_RELEASE(mTestJiwoo);	
}

void MapEditor::SaveMap(string index)
{
	string saveFileName = "Save/saveMapData_" + index + ".map";


	HANDLE hFile = CreateFile(saveFileName.c_str(),
		GENERIC_WRITE,
		NULL, NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	DWORD mapSaveTileInfo = sizeof(TagTile) * TILE_COUNT_X * TILE_COUNT_Y;

	DWORD writtenByte;
	if (WriteFile(hFile,
		mTileInfo,
		mapSaveTileInfo,
		&writtenByte,
		NULL) == false)
	{
		MessageBox(g_hWnd, "맵 데이터 저장에 실패했습니다.", "에러", MB_OK);
	}

	CloseHandle(hFile);
}

void MapEditor::LoadMap(string index)
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
