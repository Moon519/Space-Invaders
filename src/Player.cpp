#include "Player.h"

Player::Player()
{
	type = ObjectTypes::Player;

	transform.setX(93);
	transform.setY(97);

	spawn();
	numberOfSprite = 4;
	currentSprite = 0;
	animDuration = 50;
	lifePoints = START_LP;
	loadSprites();
}

Player::Player(int speed)
{
	type = ObjectTypes::Player;
	transform.SetXSpeed(speed);
	transform.SetYSpeed(speed);
	spawn();
	numberOfSprite = 4;
	currentSprite = 0;
	animDuration = 50;
	lifePoints = START_LP;

	loadSprites();
	loadSpriteSize();
}

Player::~Player(void)
{
}

void Player::loadSprites()
{
	sprite = new int[numberOfSprite];
	sprite[0] = 1;
	sprite[1] = 2;
	sprite[2] = 3;
	sprite[3] = 4;
}

void Player::forward()
{
	movingForward = true;
	movingBackward = false;
}

void Player::backward()
{
	movingForward = false;
	movingBackward = true;
}

bool Player::isMovingForward() const
{
	return movingForward;
}

bool Player::isMovingBackward() const
{
	return movingBackward;
}

void Player::stop()
{
	movingBackward = movingForward = false;
}

ReactionTypes Player::reactToCollision(GameObject* hitObject)
{
	ReactionTypes ret;
	switch (hitObject->getObjectType())
	{
	case ObjectTypes::Enemy:
		// currently re spawning the player into the start position
		if ((--lifePoints) <= 0)
			ret = ReactionTypes::Destroy;
		else
			ret = ReactionTypes::Nothing;
		spawn();
		break;
	default:
		ret = ReactionTypes::Nothing;
		break;
	}
	return ret;
}

unsigned int Player::getLifePoints() const
{
	return lifePoints;
}

void Player::spawn()
{
	transform.setX(X_SPAWN);
	transform.setY(Y_SPAWN);
}

void Player::resetLifePoints()
{
	lifePoints = START_LP;
}