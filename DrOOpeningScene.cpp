#include "stdafx.h"
#include "DrOOpeningScene.h"
#include "TextManager.h"
#include "Image.h"

HRESULT DrOOpeningScene::Init()
{
    mBackground = IMG_MGR->FindImage(eImageTag::Background);
    mDialogue = IMG_MGR->FindImage(eImageTag::Dialogue);
    mOBaksa = IMG_MGR->FindImage(eImageTag::DoctorOBig);
    mPageCursor = IMG_MGR->FindImage(eImageTag::WhiteCursor);
    
    mElapsedCnt = 0.0f;
    mScriptCnt = 0;

    return S_OK;
}

void DrOOpeningScene::Update()
{
    mElapsedCnt += DELTA_TIME;
    if (mElapsedCnt < 0.5f)
    {
        mBlinkCursor = true;
    }
    else
    {
        mBlinkCursor = false;
    }
    if (mElapsedCnt > 1)
    {
        mElapsedCnt = 0.0f;
    }

    if (Input::GetButtonDown('Z'))
    {
        ++mScriptCnt;
    }
    if (mScriptCnt >= TXT_MGR->mDrOScript.size())
    {
        SCENE_MGR->ChangeScene(eSceneTag::Home2ndScene);
    }

}

void DrOOpeningScene::Render(HDC hdc)
{
    SetTextColor(hdc, RGB(0, 0, 0));
    SetBkColor(hdc, RGB(248, 248, 248));
    HFONT hFont = CreateFont(36, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
        18, TEXT("PokemonGSC"));
    HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

    mBackground->Render(hdc);
    mDialogue->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
    mOBaksa->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2 - 50);
    if (mBlinkCursor == true)
    {
        mPageCursor->Render(hdc, WIN_SIZE_X - 41, WIN_SIZE_Y - 10);
    }
   
    char ch[100];
    strcpy_s(ch, TXT_MGR->mDrOScript[mScriptCnt].c_str());
    sprintf_s(mText, ch);
    RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
    DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);

    SelectObject(hdc, hOldFont);
    DeleteObject(hFont);
}

void DrOOpeningScene::Release()
{
}
