#include "stdafx.h"
#include "Config.h"
#include "Jiwoo.h"
#include "Image.h" 
#include "MenuManager.h"
#include "Collider.h"
#include "RandomManager.h"
#include "PokemonManager.h"

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

    mBarometerPos.x = WIN_SIZE_X / 2 - 32;
    mBarometerPos.y = WIN_SIZE_Y / 2;

    mJumpWeight = 350.0f;
    mJumpHeight = WIN_SIZE_Y / 2 - 32;

    mbNeedRevise = false;
    mbControlSwitch = true;
    mbMenuSwitch = false;
    mbControl = true;
    mbCoolTime = true;

    mElapsedCount = 0.0f;
    mCoolTimeCnt = 0.0f;

    mMoveSpeed = 300;
    CAM_MGR->mObjectPos = { 0,0 };
    mOneTileTime = 0.5f;



    return S_OK;
}

void Jiwoo::Update()
{ 
    if (mbMenuSwitch == true)
    {
        mMenu->Update();
    }

    mElapsedCount += DELTA_TIME;
    mCoolTimeCnt += DELTA_TIME;
    if (mCoolTimeCnt > 3.0f)
    {
        mbCoolTime = false;
    }

  
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
                if (CheckJump() == true)
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

    //// 점프
    //if (mbJump == true)
    //{
    //    Jump();

    //    if (mPos.y >= mBarometerPos.y)
    //    {
    //        mPos.y = WIN_SIZE_Y / 2;
    //        mbJump = false;
    //    }
    //}
    // 
    // 보간
    if (mbNeedRevise == true)
    {
        if (mbJump == true)
        {
            CAM_MGR->MovePos(mDestPos, mOneTileTime * 2, mState);
        }
        else
        {
            CAM_MGR->MovePos(mDestPos, mOneTileTime, mState);
        }
        
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
       // mState == eDir::Idle;
        mframeX = 0;
    }

    // 포켓몬 발견
    if (CheckGrass() == true && mbCoolTime == false)
    {
        if (RandomManager::PercentMaker(2000) == true)
        {
            switch (RandomManager::RandomPeeker(0, 5))
            {
            case 0:
                POKE_MGR->mTempPokemon = POKE_MGR->FactoryFunc(ePokemon::Bcane);
                POKE_MGR->RegistDogam(POKE_MGR->mTempPokemon);
                break;
            case 1:
                POKE_MGR->mTempPokemon = POKE_MGR->FactoryFunc(ePokemon::Caterpie);
                POKE_MGR->RegistDogam(POKE_MGR->mTempPokemon);
                break;
            case 2:
                POKE_MGR->mTempPokemon = POKE_MGR->FactoryFunc(ePokemon::Chicorita);
                POKE_MGR->RegistDogam(POKE_MGR->mTempPokemon);
                break;
            case 3:
                POKE_MGR->mTempPokemon = POKE_MGR->FactoryFunc(ePokemon::Ggorat);
                POKE_MGR->RegistDogam(POKE_MGR->mTempPokemon);
                break;
            case 4:
                POKE_MGR->mTempPokemon = POKE_MGR->FactoryFunc(ePokemon::Pika);
                POKE_MGR->RegistDogam(POKE_MGR->mTempPokemon);
                break;
            case 5:
                POKE_MGR->mTempPokemon = POKE_MGR->FactoryFunc(ePokemon::Riaco);
                POKE_MGR->RegistDogam(POKE_MGR->mTempPokemon);
                break;
            default:
                break;
            }
            mbDetected = true;
            mbCoolTime = true;
            mCoolTimeCnt = 0.0f;
        }
    }

    if (mbDetected == true && mElapsedCount > 0.5f)
    {
        // 배틀씬 전환
        POINT tempPos = CAM_MGR->GetCamPos();
        tempPos.x += 50;
        tempPos.y += 50;
        CAM_MGR->SetWarfPos(tempPos);
        SCENE_MGR->ChangeScene(eSceneTag::BattleScene);
        mbDetected = false;
    }


    // 메뉴 진입
    if (Input::GetButton(VK_RETURN))
    {
        mbMenuSwitch = true;
        mbControlSwitch = false;
    }
    if (Input::GetButton('Z') && mMenu->mMenuCnt == 6)
    {
        mbMenuSwitch = false;
        mbControlSwitch = true;

        mMenu->mbMenuCon = true;
        mMenu->mbDogam = false;
        mMenu->mbPokemon = false;
        mMenu->mbGear = false;
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
    mShadow->Render(hdc, mBarometerPos.x, mBarometerPos.y + 5);

    if (mbMenuSwitch == true)
    {
        mMenu->Render(hdc);
    }
}



void Jiwoo::Jump()
{
    mElapsedCount += DELTA_TIME;

    if (mPos.y >= mBarometerPos.y - 32)
    {
        mPos.y = mBarometerPos.y - mElapsedCount / 0.02f;
    }
    else if (mPos.y <= mBarometerPos.y - 32)
    {
        mPos.y = mBarometerPos.y - 32 + mElapsedCount / 0.04f;
    }

}

void Jiwoo::Release()
{
    SAFE_RELEASE(mCollider);
    SAFE_RELEASE(mMenu);

}