#include "stdafx.h"
#include "MapScene.h"
#include "MapEditor.h"


HRESULT MapScene::Init()
{
    mMapEditor = new MapEditor;
    mMapEditor->Init();

    if (mMapEditor == nullptr)
    {
        cout << "문제가 있음" << '\n';
        return E_FAIL;
    }

    return S_OK;
}

void MapScene::Update()
{
    mMapEditor->Update();
}

void MapScene::Render(HDC hdc)
{
    mMapEditor->Render(hdc);
}

void MapScene::Release()
{
    SAFE_RELEASE(mMapEditor);
}
