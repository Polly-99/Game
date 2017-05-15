#include "HelloWorldScene.h"
#include "TObject.h"

TObject::TObject()
{}

TObject::TObject(float x, float y, const std::string & fileName)
: X(x)
, Y(y)
{
	Sprite = cocos2d::Sprite::create(fileName);
	Sprite->setPosition(X, Y);
}

TObject& TObject::operator = (const TObject& rhs)
{
	X = rhs.X;
	Y = rhs.Y;
	Sprite = rhs.Sprite;
	Sprite->setPosition(X, Y);
	return *this;
}

cocos2d::Sprite * TObject::GetSpritePtr()
{
	return Sprite;
}

float TObject::GetX()
{
	return X;
}

float TObject::GetY()
{
	return Y;
}

void TObject::SetX(float x)
{
	X = x;
}

void TObject::SetY(float y)
{
	Y = y;
}
