#include "Player.h"
#include <assert.h>


void Player::init()
{
	w = 10;
	h = 60;

	posX = 0;
	posY = 220;

	speed = 10;
}

void Player::MoveUp()
{
    delta -= speed;
}

void Player::MoveDown()
{
    delta += speed;
}

void Player::Move()
{
	assert(mySide != Side_Undefined);


	if(( posY + delta > 100) && ((posY + delta) < (600 - h )))
	{
		posY += delta;
	}
}

void Player::SetSide(Side eSide)
{
	mySide = eSide;

	if(mySide == Side_Left)
	{
		posX = 30;
	}

	if(mySide == Side_Right)
	{
		posX = 760;
	}
}
