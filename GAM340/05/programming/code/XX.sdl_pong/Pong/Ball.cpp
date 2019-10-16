#include "Ball.h"

void Ball::init()
{
	w = h = 10;
	posX = 400;posY = 300;

	ServeTo(Player::Side_Left);
}

void Ball::Move()
{	
	if(((posY + dy) < 100) || ((posY +dy) > 590))
	{
		dy = -dy;
	}

	posX += dx;
	posY += dy;
}

void Ball::PlayerReturns()
{
	dx = -dx;
	posX += dx;
	posY += dy;
}

Player::Side Ball::IsGoingTo()
{
	if(dx > 0)	return Player::Side_Right;

	return Player::Side_Left;
}


bool Ball::IsOutOfBounds()
{
	return (((posX + dx) < 0) || ((posX +dx) > 800));
}

Player::Side Ball::OutOfBoundsSide()
{
	if(posX <= 0)	return Player::Side_Left;
	if(posX >= 600)	return Player::Side_Right;

	return Player::Side_Undefined;
}

void Ball::ServeTo(Player::Side serveTo)
{
	if(serveTo == Player::Side_Left)
	{
		dx = -5;
		dy = -5;
	}

	if(serveTo == Player::Side_Right)
	{
		dx =  5;
		dy = -5;
	}	

	dx /= 1;
	dy /= 1;
}