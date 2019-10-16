#pragma once
#include "Object.h"
#include "Player.h"

class Ball : public Object
{
public:
	void virtual init();
	void virtual Move();
	
	void PlayerReturns();
	bool IsOutOfBounds();
	Player::Side OutOfBoundsSide();
	Player::Side IsGoingTo();

	void ServeTo(Player::Side serveTo);
private:
	float dx,dy;
};