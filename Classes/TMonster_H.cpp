#include "TMonster_H.h"

Monster_H::Monster_H(float x, float y, float speed, const std::string & fileName)
: TSubject(x, y, speed, 0.f, fileName)
{
	SetSpeed(speed);
}

bool Monster_H::GetInd()
{
	return ind;
}

void Monster_H::ChangeInd()
{
	if (ind == true)
		ind = false;
	else
		ind = true;
}

void Monster_H::MoveLeft()
{
	SetH(-1 * abs(GetSpeed()));
}

void Monster_H::MoveRight()
{
	SetH(abs(GetSpeed()));
}

void Monster_H::Update()
{
	TSubject::Update();
}
