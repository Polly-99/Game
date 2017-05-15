#pragma once
#include "TSubject.h"

class Monster_V
	: public TSubject
{
	bool ind = true;

public:
	Monster_V();

	Monster_V(float x, float y, float Speed, const std::string & fileName);

	virtual ~Monster_V() = default;

	virtual void Update() override;

	bool GetInd();

	void MoveFront();

	void MoveBack();

	void ChangeInd();
};