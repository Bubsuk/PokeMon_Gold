#pragma once
#include "GameEntity.h"

class Image;
class GameObject : public GameEntity
{
protected:
	Image* mImage = nullptr;

	POINT mPos = {};
	eDir mDir = eDir::Idle;
	//const POINTFLOAT DIR_VALUE[4] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

public:
	GameObject();
	~GameObject();

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	
	POINT GetPosition() { return mPos; }
	void SetPosition(POINT pos) { mPos = pos; }
	eDir GetDirection() { return mDir; }
	void SetDirection(eDir dir) { mDir = dir; }

};