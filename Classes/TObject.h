#pragma once 
#include "cocos2d.h"

class HelloWorld;

class TObject
{
	float X;
	float Y;
	cocos2d::Sprite* Sprite;

public:
	TObject();

	TObject(float x, float y, const std::string & fileName);

	virtual ~TObject() = default;

	TObject& operator =(const TObject&);

	cocos2d::Sprite * GetSpritePtr();

	float GetX();

	float GetY();

	void SetX(float x);

	void SetY(float y);
};
