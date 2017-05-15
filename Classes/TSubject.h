#pragma once 
#include "cocos2d.h"

class TSubject
{
	float X;
	float Y;
	float SpeedV;
	float SpeedH;
	float Speed;
	cocos2d::Sprite* Sprite;
public:
	TSubject();

	TSubject(float x, float y, float hSpeed, float vSpeed, const std::string & fileName);

	virtual ~TSubject() = default;

	virtual void Update();

	cocos2d::Sprite * GetSpritePtr();

	float GetX();

	float GetY();

	float GetW();

	float GetH();

	float GetSpeed();

	void SetX(float x);

	void SetY(float y);

	void SetW(float v);

	void SetH(float h);

	void SetSpeed(float speed);
};
