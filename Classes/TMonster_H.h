#pragma once
#include "TSubject.h"

class Monster_H
	: public TSubject
{
	bool ind = true;

public:
	Monster_H();

	Monster_H(float x, float y, float Speed, const std::string & fileName);

	virtual ~Monster_H() = default;

	virtual void Update() override;

	bool GetInd();

	void MoveLeft();

	void MoveRight();

	void ChangeInd();
};