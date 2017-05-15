#pragma once
#include "TSubject.h"

class TPlayer
	: public TSubject
{
public:

	TPlayer(float x, float y, float hSpeed, float vSpeed, std::string const & filename);

	~TPlayer() = default;

	void MoveLeft();

	void MoveRight();

	void MoveBack();

	void MoveFront();

	virtual void Update() override;
};