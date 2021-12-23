#include "stdafx.h"
#include "Enum.h"
#include "Collider.h"
#include "Config.h"
#include "MapManager.h"


int Collider::SetLimit(eDir dir)
{
	mPlayer.left = 256 - CAM_MGR->GetCamPos().x;
	mPlayer.right = 320 - CAM_MGR->GetCamPos().x;
	mPlayer.top = 256 - CAM_MGR->GetCamPos().y;
	mPlayer.bottom = 320 - CAM_MGR->GetCamPos().y;

	switch (dir)
	{
	case eDir::Up:
	{
		int indexUpX = (288 - CAM_MGR->GetCamPos().x) / TILE_SIZE;
		int indexUpY = (224 - CAM_MGR->GetCamPos().y) / TILE_SIZE;

		if (mPlayer.top <= MAP_MGR->GetTileInfo()[indexUpY * TILE_COUNT_X + indexUpX].Rc.bottom &&
			(MAP_MGR->GetTileInfo()[indexUpY * TILE_COUNT_X + indexUpX].Terrain == eTerrain::Close
			|| MAP_MGR->GetTileInfo()[indexUpY * TILE_COUNT_X + indexUpX].Terrain == eTerrain::BottomBlock))
		{
			return CAM_MGR->mObjectPos.y = 256 - MAP_MGR->GetTileInfo()[indexUpY * TILE_COUNT_X + indexUpX].Rc.bottom;
		}
		else return CAM_MGR->mObjectPos.y + TILE_SIZE - (TILE_SIZE + (CAM_MGR->mObjectPos.y % TILE_SIZE));
		break;
	}
	case eDir::Down:
	{
		int indexDoX = (288 - CAM_MGR->GetCamPos().x) / TILE_SIZE;
		int indexDoY = (352 - CAM_MGR->GetCamPos().y) / TILE_SIZE;
		
		if (mPlayer.bottom >= MAP_MGR->GetTileInfo()[indexDoY * TILE_COUNT_X + indexDoX].Rc.top	&&
			MAP_MGR->GetTileInfo()[indexDoY * TILE_COUNT_X + indexDoX].Terrain == eTerrain::Close)
		{
			return CAM_MGR->mObjectPos.y = 310 - MAP_MGR->GetTileInfo()[indexDoY * TILE_COUNT_X + indexDoX].Rc.top;
		}
		else return CAM_MGR->mObjectPos.y - TILE_SIZE - (CAM_MGR->mObjectPos.y % TILE_SIZE);
		break;
	}
	case eDir::Left:
	{
		int indexLeX = (224 - CAM_MGR->GetCamPos().x) / TILE_SIZE;
		int indexLeY = (288 - CAM_MGR->GetCamPos().y) / TILE_SIZE;

		if (mPlayer.left <= MAP_MGR->GetTileInfo()[indexLeY * TILE_COUNT_X + indexLeX].Rc.right &&
			(MAP_MGR->GetTileInfo()[indexLeY * TILE_COUNT_X + indexLeX].Terrain == eTerrain::Close
				|| MAP_MGR->GetTileInfo()[indexLeY * TILE_COUNT_X + indexLeX].Terrain == eTerrain::RightBlock))
		{
			return CAM_MGR->mObjectPos.x = 256 - MAP_MGR->GetTileInfo()[indexLeY * TILE_COUNT_X + indexLeX].Rc.right;
		}
		else return CAM_MGR->mObjectPos.x + TILE_SIZE - (TILE_SIZE + (CAM_MGR->mObjectPos.x % TILE_SIZE));
		break;
	}
	case eDir::Right:
	{
		int indexRiX = (352 - CAM_MGR->GetCamPos().x) / TILE_SIZE;
		int indexRiY = (288 - CAM_MGR->GetCamPos().y) / TILE_SIZE;

		if (mPlayer.right >= MAP_MGR->GetTileInfo()[indexRiY * TILE_COUNT_X + indexRiX].Rc.left &&
			(MAP_MGR->GetTileInfo()[indexRiY * TILE_COUNT_X + indexRiX].Terrain == eTerrain::Close
			|| MAP_MGR->GetTileInfo()[indexRiY * TILE_COUNT_X + indexRiX].Terrain == eTerrain::LeftBlock))
		{
			return CAM_MGR->mObjectPos.x = 320 - MAP_MGR->GetTileInfo()[indexRiY * TILE_COUNT_X + indexRiX].Rc.left;
		}
		else return CAM_MGR->mObjectPos.x - TILE_SIZE - (CAM_MGR->mObjectPos.x % TILE_SIZE);
		break;
	}
	}
	
}

bool Collider::CheckJump()
{

	int jumpPointX = 288 - CAM_MGR->GetCamPos().x;
	int jumpPointY = 288 - CAM_MGR->GetCamPos().y;

	int curIndexX = (288 - CAM_MGR->GetCamPos().x) / TILE_SIZE;
	int curIndexY = (288 - CAM_MGR->GetCamPos().y) / TILE_SIZE;

	if (MAP_MGR->GetTileInfo()[curIndexY * TILE_COUNT_X + curIndexX].Terrain == eTerrain::BottomBlock
		&& MAP_MGR->GetTileInfo()[curIndexY * TILE_COUNT_X + curIndexX].Rc.bottom -40 >= jumpPointY)
	{
		return true;
	}
	else if (MAP_MGR->GetTileInfo()[curIndexY * TILE_COUNT_X + curIndexX].Terrain == eTerrain::LeftBlock
		&& MAP_MGR->GetTileInfo()[curIndexY * TILE_COUNT_X + curIndexX].Rc.right == jumpPointX)
	{
		return true;
	}
	else if (MAP_MGR->GetTileInfo()[curIndexY * TILE_COUNT_X + curIndexX].Terrain == eTerrain::RightBlock
		&& MAP_MGR->GetTileInfo()[curIndexY * TILE_COUNT_X + curIndexX].Rc.left == jumpPointX)
	{
		return true;
	}
	else return false;
}
