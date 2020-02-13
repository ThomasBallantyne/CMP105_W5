#include "Zombie.h"

Zombie::Zombie() 
{
	walk.addFrame(sf::IntRect(0,0,55,108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(0.1f);
	coord = sf::Vector2f(100, 100);
	speed = 100;
	moving = false;
	walk.reset();
	setTextureRect(walk.getCurrentFrame());
}

Zombie::~Zombie() 
{
	
}

void Zombie::setFlipped(bool dir)
{
	walk.setFlipped(dir);
}

void Zombie::update(float dt)
{
	if (moving)
	{
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
}
