#include "stdafx.h"
#include "Config.h"
#include "Jiwoo.h"
#include "Image.h" 
#include "Collider.h"

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
    //if ()
    //{
    //    mTileIn = 

    //}

    mState = eDir::Idle;

    mbControl = true;
    mMoveSpeed = 600;
    CAM_MGR->mObjectPos = { 0,0 };
    mOneTileTime = 0.3f;


    return S_OK;
}

void Jiwoo::Update()
{
  
    
    if (mbControl == true)
    {
        if (Input::GetButton(VK_DOWN))
        {
            mDir = eDir::Down;
            CAM_MGR->mObjectPos.y -= mMoveSpeed * DELTA_TIME;
            mAnimPlay = true;
            mbNeedRevise = false;

            if (CAM_MGR->mObjectPos.y <= -TILE_SIZE * TILE_COUNT_Y + TILE_SIZE *9)
            {
                CAM_MGR->mObjectPos.y = -TILE_SIZE * TILE_COUNT_Y + TILE_SIZE * 9;
                mDestPos.y = -TILE_SIZE * TILE_COUNT_Y + TILE_SIZE * 9;
            }
            else
            {
                mDestPos.y = CAM_MGR->mObjectPos.y - TILE_SIZE - (CAM_MGR->mObjectPos.y % TILE_SIZE);
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
            CAM_MGR->mObjectPos.y += mMoveSpeed * DELTA_TIME;
            mAnimPlay = true;
            mbNeedRevise = false;

            

            if (CAM_MGR->mObjectPos.y >= 0)
            {
                mDestPos.y = 0;
                CAM_MGR->mObjectPos.y = 0;
            }
            else
            {
                mDestPos.y = CAM_MGR->mObjectPos.y + TILE_SIZE - (TILE_SIZE + (CAM_MGR->mObjectPos.y % TILE_SIZE));
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
            CAM_MGR->mObjectPos.x += mMoveSpeed * DELTA_TIME;

            mAnimPlay = true;
            mbNeedRevise = false;

            if (CAM_MGR->mObjectPos.x >= 0)
            {
                mDestPos.x = 0;
                CAM_MGR->mObjectPos.x = 0;
            }
            else
            {
                mDestPos.x = CAM_MGR->mObjectPos.x + TILE_SIZE - (TILE_SIZE + (CAM_MGR->mObjectPos.x % TILE_SIZE));
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
            CAM_MGR->mObjectPos.x -= mMoveSpeed * DELTA_TIME;

            mAnimPlay = true;
            mbNeedRevise = false;

            if (CAM_MGR->mObjectPos.x <= -TILE_SIZE * TILE_COUNT_X + TILE_SIZE * 10)
            {
                CAM_MGR->mObjectPos.x = -TILE_SIZE * TILE_COUNT_X + TILE_SIZE * 10;
                mDestPos.x = -TILE_SIZE * TILE_COUNT_X + TILE_SIZE * 10;
            }
            else
            {
                mDestPos.x = CAM_MGR->mObjectPos.x - TILE_SIZE - (CAM_MGR->mObjectPos.x % TILE_SIZE);
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
        CAM_MGR->mObjectPos = CAM_MGR->GetCamPos();

        if (mDir == eDir::Right && CAM_MGR->mObjectPos.x <= mDestPos.x)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
        if (mDir == eDir::Left && CAM_MGR->mObjectPos.x >= mDestPos.x)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
        else if (mDir == eDir::Up && CAM_MGR->mObjectPos.y >= mDestPos.y)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
        else if (mDir == eDir::Down && CAM_MGR->mObjectPos.y <= mDestPos.y)
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

    if (Input::GetButtonUp(VK_DOWN) || Input::GetButtonUp(VK_UP)
        || Input::GetButtonUp(VK_LEFT) || Input::GetButtonUp(VK_RIGHT))
    {
        mAnimPlay = false;
        mDir == eDir::Idle;
        mframeX = 0;
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
