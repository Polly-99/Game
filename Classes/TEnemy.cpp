#include "TEnemy.h"

Monster_V::Monster_V(float x, float y, float speed, const std::string & fileName)
: TSubject(x, y, 0.f, speed, fileName)
{
	SetSpeed(speed);
}

bool Monster_V::GetInd()
{
	return ind;
}

void Monster_V::ChangeInd()
{
	if (ind == true)
		ind = false;
	else
		ind = true;
}

void Monster_V::MoveFront()
{
	SetW(abs(GetSpeed()));
}

void Monster_V::MoveBack()
{
	SetW(-1 * abs(GetSpeed()));
}

void Monster_V::Update()
{
	TSubject::Update();
}
