#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Zombie: public GameObject
{
public:
	Zombie();
	~Zombie();

	void update(float dt) override;
	void setFlipped(bool dir);
	bool moving;
	sf::Vector2f coord;
	float speed;
	float distance;


protected:
	Animation walk;

};

