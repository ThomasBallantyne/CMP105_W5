#include "Mario.h"

Mario::Mario()
{
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(15, 21, 16, 20));
	swim.addFrame(sf::IntRect(30, 21, 16, 20));

	crouch.addFrame(sf::IntRect(0, 42, 16, 20));
	crouch.addFrame(sf::IntRect(15, 42, 16, 20));
	crouch.addFrame(sf::IntRect(30, 42, 16, 20));

	walk.setFrameSpeed(0.1f);
	crouch.setFrameSpeed(0.1f);
	swim.setFrameSpeed(0.1f);
	coord = sf::Vector2f(100, 100);
	speed = 100;
	moving = false;

	walk.reset();
	setTextureRect(walk.getCurrentFrame());
}

Mario::~Mario()
{

}

void Mario::setFlipped(bool dir)
{
	walk.setFlipped(dir);
}

void Mario::update(float dt)
{
	if (moving)
	{
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	else if (crouching)
	{
		crouch.animate(dt);
		setTextureRect(crouch.getCurrentFrame());
	}
}