#include "HelloWorldScene.h"
#include "TSubject.h"

TSubject::TSubject()
{ }

TSubject::TSubject(float x, float y, float hSpeed, float vSpeed, const std::string & fileName)
: X(x)
, Y(y)
, SpeedV(vSpeed)
, SpeedH(hSpeed)
, Speed(0.f)
{
	Sprite = cocos2d::Sprite::create(fileName);
}

void TSubject::Update()
{
	SetY(GetY() + SpeedV);
	SetX(GetX() + SpeedH);

	if (this->GetSpritePtr())
		this->GetSpritePtr()->setPosition(GetX(), GetY());
}

cocos2d::Sprite * TSubject::GetSpritePtr()
{
	return Sprite;
}

float TSubject::GetX()
{
	return X;
}

float TSubject::GetY()
{
	return Y;
}

float TSubject::GetW()
{
	return SpeedV;
}

float TSubject::GetH()
{
	return SpeedH;
}

float TSubject::GetSpeed()
{
	return Speed;
}

void TSubject::SetX(float x)
{
	X = x;
}

void TSubject::SetY(float y)
{
	Y = y;
}

void TSubject::SetW(float v)
{
	SpeedV = v;
}

void TSubject::SetH(float h)
{
	SpeedH = h;
}

void TSubject::SetSpeed(float speed)
{
	Speed = speed;
}