#include "Player.h"

Player::Player()
{
	ID_number = ++ID_number_counter;
}

Player::~Player()
{

}

unsigned Player::ID_number_counter = 0;

unsigned Player::GetID()
{
	return ID_number;
}

