#include "Level.h"
#include "Zombie.h"
#include "Mario.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(zombie.coord);
	zombie.setTexture(&zombTexture);
	marioTexture.loadFromFile("gfx/marioSheetT.png");
	mario.setSize(sf::Vector2f(15, 21));
	mario.setPosition(mario.coord);
	mario.setTexture(&marioTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//Zombie

	zombie.distance = zombie.speed * dt;
	zombie.moving = false;

	if (input->isKeyDown(sf::Keyboard::D))
	{
		zombie.setFlipped(false);
		zombie.moving = true;
		zombie.move(sf::Vector2f(zombie.distance, 0));
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		zombie.setFlipped(true);
		zombie.moving = true;
		zombie.move(sf::Vector2f(-zombie.distance, 0));
	}

	//Mario

	mario.distance = mario.speed * dt;
	mario.moving = false;
	mario.crouching = false;

	if (input->isKeyDown(sf::Keyboard::LControl))
	{
		mario.crouching = true;
	}
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		mario.setFlipped(false);
		mario.moving = true;
		mario.move(sf::Vector2f(mario.distance, 0));
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		mario.setFlipped(true);
		mario.moving = true;
		mario.move(sf::Vector2f(-mario.distance, 0));
	}
}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie);
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}