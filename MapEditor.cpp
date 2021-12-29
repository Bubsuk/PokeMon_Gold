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
		cout << "SmapleTile �ε� ����" << '\n';
		return E_FAIL;
	}

	// �׸����� ��ü(1Ÿ�ϴ� 64�ȼ�)
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
	

	// ������ ��� ���ÿ���(1Ÿ�ϴ� 40�ȼ�)
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

			// Ÿ�Ϻ� �Ӽ� ����
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

	// ���ÿ��� ũ��(1Ÿ�ϴ� 40�ȼ�)
	mSampleArea.left = TILE_MAP_TOOL_X - mSampleTileImage->GetWidth();
	mSampleArea.top = 0;
	mSampleArea.right = TILE_MAP_TOOL_X;
	mSampleArea.bottom = mSampleTileImage->GetHeight();

	// �׸����� ũ��(1Ÿ�ϴ� 64�ȼ�)
	mDrawArea.left = 0;
	mDrawArea.top = 0;
	mDrawArea.right = TILE_SIZE * 15; // 960
	mDrawArea.bottom = TILE_SIZE * 15; //960
	
	return S_OK;
}

void MapEditor::Update()
{
		
	// ���� �κ�
	if (Input::GetButton(VK_CONTROL) && Input::GetButtonDown('S'))
	{
			cout << "���� �� ���ϸ� : ";
			cin >> mSaveIndex;
			cout << "\"" << mSaveIndex << "\"" << "�� ����˴ϴ�" << '\n';
			SaveMap(mSaveIndex);

	}
	if (Input::GetButton(VK_LSHIFT))
	{
		if (Input::GetButtonDown('S'))
		{
			cout << "�ҷ� �� ���ϸ� : ";
			cin >> mSaveIndex;
			cout << "\"" << mSaveIndex << "\"" << "�� �ҷ��ɴϴ�" << '\n';
			LoadMap(mSaveIndex);
		}
	}


	// �巡�� ����
	if (Input::GetButtonDown(VK_LBUTTON))
	{
		if (PtInRect(&(mSampleArea), Input::GetMousePosition()))
		{
			mbIsClick = true;
			// ���ÿ��� Ŭ�� ������ǥ
			mClickStart.x = (Input::GetMousePosition().x - mSampleArea.left) / SAMPLE_TILE_SIZE;
			mClickStart.y = Input::GetMousePosition().y / SAMPLE_TILE_SIZE;
			// Ŭ�� �巡�� ���� ���۰� 1�� ����
			mClickArea.x = 1;
			mClickArea.y = 1;
		}
	}
	// �巡�� ��
	if (Input::GetButtonUp(VK_LBUTTON))
	{
		if (PtInRect(&(mSampleArea), Input::GetMousePosition()) && mbIsClick == true)
		{
			// Ŭ�� ����� ��ǥ
			mCLickEnd = POINT{ (Input::GetMousePosition().x - mSampleArea.left) / SAMPLE_TILE_SIZE, (Input::GetMousePosition().y - mSampleArea.top) / SAMPLE_TILE_SIZE };
			// �巡�� ���� ��ǥ
			mClickArea.x = fabs(mClickStart.x -  mCLickEnd.x);
			mClickArea.y= fabs(mClickStart.y - mCLickEnd.y);
		}
		mbIsClick = false;
	}

	// �׸��� ���� Ÿ������ ������Ʈ
	if (Input::GetButton(VK_LBUTTON))
	{
		if (PtInRect(&(mDrawArea), Input::GetMousePosition()))
		{
			// �׸��� ���� �� ��ǥ
			POINT clickPos
				= { (Input::GetMousePosition().x - CAM_MGR->GetCamPos().x) / TILE_SIZE,
				(Input::GetMousePosition().y - CAM_MGR->GetCamPos().y) / TILE_SIZE };
			
			for (int i = 0; i <= mClickArea.y; ++i)
			{
				for (int j = 0; j <= mClickArea.x; ++j)
				{
					// Ŭ�� ��ǥ�� ���������� ������ �Ѿ ��� ����ó��
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

	// �׸��� ���� ǥ��
	Rectangle(hdc, 0, 0, SAMPLE_TILE_COUNT_X * TILE_SIZE, SAMPLE_TILE_COUNT_X * TILE_SIZE);

	//Ÿ�� �׸���
	
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

	// ��ü ���� ����
	mSampleTileImage->Render(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth() + mSampleTileImage->GetWidth() / 2,
		mSampleTileImage->GetWidth() / 2);

	// ���� Ÿ�� ǥ�ÿ���
	for (int i = 0; i <= mClickArea.y ; ++i)
	{
		for (int j = 0; j <= mClickArea.x; ++j)
		{
			mSampleTileImage->Render(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth() + mSampleTileImage->GetWidth() / 2 + j * SAMPLE_TILE_SIZE,
				mSampleTileImage->GetHeight() + mSampleTileImage->GetFrameHeight() / 2 + 50 + i * SAMPLE_TILE_SIZE,
				mClickStart.x + j, mClickStart.y + i);
		}
	}

	// �׽�Ʈ ����(��Ʈ��)
	mTestJiwoo->Render(hdc);
	 
	hFont = CreateFont(15, 0, 0, 0, 400, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
		18, TEXT("PokemonGSC"));
	HFONT oldFont = (HFONT)SelectObject(hdc, hFont);
	// ����Ÿ�ϳѹ�
	wsprintf(mSampleText, "���� Ÿ�� �ε��� : %d", mClickStart.y * SAMPLE_TILE_COUNT_X + mClickStart.x);
	TextOut(hdc, TILE_MAP_TOOL_X - mSampleTileImage->GetWidth(), mSampleTileImage->GetHeight() + 120, mSampleText, strlen(mSampleText));

	// ���� Ÿ�� �Ӽ� ǥ��
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
		MessageBox(g_hWnd, "�� ������ ���忡 �����߽��ϴ�.", "����", MB_OK);
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
		MessageBox(g_hWnd, "�� ������ �ε忡 �����߽��ϴ�.", "����", MB_OK);
	}

	CloseHandle(hFile);
}
