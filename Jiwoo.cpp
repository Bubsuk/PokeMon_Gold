#include "stdafx.h"
#include "Config.h"
#include "Jiwoo.h"
#include "Image.h" 
#include "Collider.h"
#include "MenuManager.h"

HRESULT Jiwoo::Init()
{
    mImageRunRL = IMG_MGR->FindImage(eImageTag::Jiwoo_moveRL);
    mImageRunUD = IMG_MGR->FindImage(eImageTag::Jiwoo_moveUD);
    mShadow = IMG_MGR->FindImage(eImageTag::Shadow);

    if (mImageRunRL == nullptr || mImageRunUD == nullptr)
    {
        return E_FAIL;
    }

    mMenu = new MenuManager;
    mMenu->Init();

    mAnimPlay = false;

    mState = eDir::Idle;

    mPos.x = WIN_SIZE_X / 2 - 32;
    mPos.y = WIN_SIZE_Y / 2;

    mJumpWeight = 350.0f;
    mJumpHeight = WIN_SIZE_Y / 2 - 32;

    mbControlSwitch = true;
    mbMenuSwitch = false;
    mbControl = true;
    mMoveSpeed = 300;
    CAM_MGR->mObjectPos = { 0,0 };
    mOneTileTime = 0.3f;


    return S_OK;
}

void Jiwoo::Update()
{ 
    mElapsedCount += DELTA_TIME;
    mJumpCnt += 10.0f * DELTA_TIME;
   
    if (mbControl == true && mbJump == false && mbMenuSwitch == false)
    {
        if (Input::GetButton(VK_DOWN))
        {
            mState = eDir::Down;
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
                if (CheckJump(mState) == true)
                {
                    mbJump = true;
                    mDestPos.y = SetLimit(mState) + TILE_SIZE;
                }
                else
                {
                    mDestPos.y = SetLimit(mState);
                }
            }
           
        }
        if (Input::GetButtonUp(VK_DOWN))
        {
            mbControl = true;
            if (CAM_MGR->mObjectPos.y % TILE_SIZE == 0)
            {
                mbNeedRevise = false;
            }
            else mbNeedRevise = true;
        }
        if (Input::GetButton(VK_UP))
        {
            mState = eDir::Up;
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
                mDestPos.y = SetLimit(mState);
            }
        }
        if (Input::GetButtonUp(VK_UP))
        {
            mbControl = true;
            if (CAM_MGR->mObjectPos.y % TILE_SIZE == 0)
            {
                mbNeedRevise = false;
            }
            else mbNeedRevise = true;
        }
        if (Input::GetButton(VK_LEFT))
        {
            mState = eDir::Left;
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
                mDestPos.x = SetLimit(mState);
                
            }
        }
        if (Input::GetButtonUp(VK_LEFT))
        {
            mbControl = true;
            if (CAM_MGR->mObjectPos.x % TILE_SIZE == 0)
            {
                mbNeedRevise = false;
            }
            else mbNeedRevise = true;
        }
        if (Input::GetButton(VK_RIGHT))
        {
            mState = eDir::Right;
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
                mDestPos.x = SetLimit(mState);
            }
        }
        if (Input::GetButtonUp(VK_RIGHT))
        {
            mbControl = true;
            if (CAM_MGR->mObjectPos.x % TILE_SIZE == 0)
            {
                mbNeedRevise = false;
            }
            else mbNeedRevise = true;
        }
    }

    // 점프
    if (mbJump == true)
    {
        mPos.y = (1000 * mJumpCnt * mJumpCnt);
        mDestPos.y = mDestPos.y + TILE_SIZE;
        if (mPos.y >= WIN_SIZE_Y / 2)
        {
            mPos.y = WIN_SIZE_Y / 2;
            mJumpCnt = 0;
            mbJump = false;
        }
        
    }
    // 보간
    if (mbNeedRevise == true)
    {
        if (mbJump == true)
        {
            CAM_MGR->MovePos(mDestPos, mOneTileTime * 2, mState);
        }
        CAM_MGR->MovePos(mDestPos, mOneTileTime, mState);
        CAM_MGR->mObjectPos = CAM_MGR->GetCamPos();

        if (mState == eDir::Right && CAM_MGR->mObjectPos.x <= mDestPos.x)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
        if (mState == eDir::Left && CAM_MGR->mObjectPos.x >= mDestPos.x)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
        else if (mState == eDir::Up && CAM_MGR->mObjectPos.y >= mDestPos.y)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
        else if (mState == eDir::Down && CAM_MGR->mObjectPos.y <= mDestPos.y)
        {
            mbNeedRevise = false;
            mbControl = true;
        }
    }
    
    // Animation
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


    // 메뉴 진입
    if (Input::GetButton(VK_RETURN))
    {
        mMenu->mMenuCnt = 0;
        mbMenuSwitch = true;
        mbControlSwitch = false;
    }
    if (Input::GetButton('X'))
    {
        mbMenuSwitch = false;
        mbControlSwitch = true;
    }

    mMenu->Update();

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
    mShadow->Render(hdc, mPos.x, mPos.y + 5);

    if (mbMenuSwitch == true)
    {
        mMenu->Render(hdc);
    }
}


void Jiwoo::Release()
{
    GameObject::Release();
}
