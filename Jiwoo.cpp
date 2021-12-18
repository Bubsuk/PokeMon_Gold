#include "stdafx.h"
#include "Config.h"
#include "Jiwoo.h"
#include "Image.h"
#include <vector>

HRESULT Jiwoo::Init()
{
    mImageRunRL = IMG_MGR->FindImage(eImageTag::Jiwoo_moveRL);
    mImageRunUD = IMG_MGR->FindImage(eImageTag::Jiwoo_moveUD);

    if (mImageRunRL == nullptr || mImageRunUD == nullptr)
    {
        return E_FAIL;
    }

    mAnimPlay = false;

    mPos.x = WIN_SIZE_X / 2 - 32;
    mPos.y = WIN_SIZE_Y / 2;

    mState = eDir::Idle;


    return S_OK;
}

void Jiwoo::Update()
{
    mElapsedCount += DELTA_TIME;

    if (Input::GetButtonDown(VK_DOWN))
    {
        mState = eDir::Down;
        mAnimPlay = true;
    }
    else if (Input::GetButton(VK_UP))
    {
        mState = eDir::Up;
        mAnimPlay = true;
    }
    else if (Input::GetButton(VK_LEFT))
    {
        mState = eDir::Left;
        mAnimPlay = true;
    }
    else if (Input::GetButton(VK_RIGHT))
    {
        mState = eDir::Right;
        mAnimPlay = true;
    }

   
    if (mAnimPlay == true)
    {
        switch (mState)
        {
        case eDir::Down:
            if (mElapsedCount >= mFlipAnimTime)
            {
                ++mframeX;
                mElapsedCount = 0.0f;
            }
            if (mframeX == 4)
            {
                mframeX = 1;
            }
            break;
        case eDir::Up:
            if (mElapsedCount >= mFlipAnimTime)
            {
                ++mframeX;
                mElapsedCount = 0.0f;
            }
            if (mframeX == 5)
            {
                mframeX = 1;
            }
            break;
        case eDir::Right:
            if (mElapsedCount >= mFlipAnimTime)
            {
                ++mframeX;
                mElapsedCount = 0.0f;
            }
            if (mframeX == 3)
            {
                mframeX = 1;
            }
            break;
        case eDir::Left:
            if (mElapsedCount >= mFlipAnimTime)
            {
                ++mframeX;
                mElapsedCount = 0.0f;
            }
            if (mframeX == 3)
            {
                mframeX = 1;
            }
            break;
        default:
            break;
        }
    }
    
    if (Input::GetButtonUp(VK_DOWN) || Input::GetButtonUp(VK_UP)
        || Input::GetButtonUp(VK_LEFT) || Input::GetButtonUp(VK_RIGHT))
    {
        mAnimPlay = false;
        mState == eDir::Idle;
        mframeX = 0;
    }
    
}

void Jiwoo::Render(HDC hdc)
{
    
    switch (mState)
    {
    case eDir::Idle:
        mImageRunUD->Render(hdc, mPos.x, mPos.y, mframeX, mframeY);
        break;
    case eDir::Up:
        mImageRunUD->Render(hdc, mPos.x, mPos.y, mframeX, mframeY + 1);
        break;
    case eDir::Down:
        mImageRunUD->Render(hdc, mPos.x, mPos.y, mframeX, mframeY);
        break;
    case eDir::Right:
        mImageRunRL->Render(hdc, mPos.x, mPos.y, mframeX, mframeY);
        break;
    case eDir::Left:
        mImageRunRL->Render(hdc, mPos.x, mPos.y, mframeX, mframeY + 1);
        break;
    }
    
}


void Jiwoo::Release()
{
    GameObject::Release();
}
