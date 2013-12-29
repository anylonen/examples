
#include "player.h"

Player::Player()
{
    _health = 0;
}

Player::~Player()
{

}

void Player::setHealth(int health)
{
    _health = health;
}

int Player::getHealth()
{
    return _health;
}

