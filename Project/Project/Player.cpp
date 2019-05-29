#include "Player.h"



Player::Player()
{
}

void Player::Crouch(bool DoIt)
{
	IsCrouching = DoIt;
}

bool Player::IsThisCrouching()
{
	return IsCrouching;
}

/*
void Player::AddPlayer()
{
	if ()

}
*/

Player::~Player()
{
}
