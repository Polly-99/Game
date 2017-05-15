#include "TPlayer.h"

TPlayer::TPlayer(float x, float y, float hSpeed, float vSpeed, std::string const & filename)
: TSubject(x, y, hSpeed, vSpeed, filename)
{
	SetSpeed(hSpeed);
}

void TPlayer::MoveBack()
{
	SetW(-1 * abs(GetSpeed()));
}

void TPlayer::MoveFront()
{
	SetW(abs(GetSpeed()));
}

void TPlayer::MoveLeft()
{
	SetH(-1 * abs(GetSpeed()));
}

void TPlayer::MoveRight()
{
	SetH(abs(GetSpeed()));
}

void TPlayer::Update()
{
	TSubject::Update();
	SetH(0.f);
	SetW(0.f);
}