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

    mbControl = true;
    mMoveSpeed = 600;
    mMovePixel = { 0,0 };
    mOneTileTime = 0.3f;


    return S_OK;
}

void Jiwoo::Update()
{
    if (Input::GetButtonUp(VK_DOWN) || Input::GetButtonUp(VK_UP)
        || Input::GetButtonUp(VK_LEFT) || Input::GetButtonUp(VK_RIGHT))
    {
        mAnimPlay = false;
        mDir == eDir::Idle;
        mframeX = 0;
    }
    
    if (mbControl == true)
    {
        if (Input::GetButton(VK_DOWN))
        {
            mDir = eDir::Down;
            mMovePixel.y -= mMoveSpeed * DELTA_TIME;
            CAM_MGR->SetPos(mMovePixel);

            mAnimPlay = true;
            mbNeedRevise = false;

            if (mMovePixel.y <= -TILE_SIZE * TILE_COUNT_Y + TILE_SIZE *9)
            {
                mMovePixel.y = -TILE_SIZE * TILE_COUNT_Y + TILE_SIZE * 9;
                mDestPos.y = -TILE_SIZE * TILE_COUNT_Y + TILE_SIZE * 9;
            }
            else
            {
                mDestPos.y = mMovePixel.y - TILE_SIZE - (mMovePixel.y % TILE_SIZE);
            }

        }
        if (Input::GetButtonUp(VK_DOWN))
        {
            mbControl = false;
            mbNeedRevise = true;
        }
        if (Input::GetButton(VK_UP))
        {
            mDir = eDir::Up;
            mMovePixel.y += mMoveSpeed * DELTA_TIME;
            CAM_MGR->SetPos(mMovePixel);

            mAnimPlay = true;
            mbNeedRevise = false;

            if (mMovePixel.y >= 0)
            {
                mDestPos.y = 0;
                mMovePixel.y = 0;
            }
            else
            {
                mDestPos.y = mMovePixel.y + TILE_SIZE - (TILE_SIZE + (mMovePixel.y % TILE_SIZE));
            }
        }
        if (Input::GetButtonUp(VK_UP))
        {
            mbNeedRevise = true;
            mbControl = false;
        }
        if (Input::GetButton(VK_LEFT))
        {
            mDir = eDir::Left;
            mMovePixel.x += mMoveSpeed * DELTA_TIME;
            CAM_MGR->SetPos(mMovePixel);

            mAnimPlay = true;
            mbNeedRevise = false;

            if (mMovePixel.x >= 0)
            {
                mDestPos.x = 0;
                mMovePixel.x = 0;
            }
            else
            {
                mDestPos.x = mMovePixel.x + TILE_SIZE - (TILE_SIZE + (mMovePixel.x % TILE_SIZE));
            }
        }
        if (Input::GetButtonUp(VK_LEFT))
        {
            mbNeedRevise = true;
            mbControl = false;
        }
        if (Input::GetButton(VK_RIGHT))
        {
            mDir = eDir::Right;
            mMovePixel.x -= mMoveSpeed * DELTA_TIME;
            CAM_MGR->SetPos(mMovePixel);

            mAnimPlay = true;
            mbNeedRevise = false;

            if (mMovePixel.x <= -TILE_SIZE * TILE_COUNT_X + TILE_SIZE * 10)
            {
                mMovePixel.x = -TILE_SIZE * TILE_COUNT_X + TILE_SIZE * 10;
                mDestPos.x = -TILE_SIZE * TILE_COUNT_X + TILE_SIZE * 10;
            }
            else
            {
                mDestPos.x = mMovePixel.x - TILE_SIZE - (mMovePixel.x % TILE_SIZE);
            }
        }
        if (Input::GetButtonUp(VK_RIGHT))
        {
            mbNeedRevise = true;
            mbControl = false;
        }
    }
    // º¸°£
    if (mbNeedRevise == true)
    {
        CAM_MGR->MovePos(mDestPos, mOneTileTime, mDir);
        mMovePixel = CAM_MGR->GetCamPos();

        if (mDir == eDir::Right && mMovePixel.x <= mDestPos.x)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
        if (mDir == eDir::Left && mMovePixel.x >= mDestPos.x)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
        else if (mDir == eDir::Up && mMovePixel.y >= mDestPos.y)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
        else if (mDir == eDir::Down && mMovePixel.y <= mDestPos.y)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
    }
    
    // Animation

    mElapsedCount += DELTA_TIME;

    if (mAnimPlay == true)
    {
        switch (mDir)
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

}

void Jiwoo::Render(HDC hdc)
{
    
    switch (mDir)
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
