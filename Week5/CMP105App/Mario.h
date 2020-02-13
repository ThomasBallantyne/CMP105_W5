#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"	
class Mario: public GameObject
{
public:
	Mario();
	~Mario();

	void update(float dt) override;
	void setFlipped(bool dir);
	bool moving;
	bool crouching;
	sf::Vector2f coord;
	float speed;
	float distance;

protected:
	Animation walk;
	Animation swim;
	Animation crouch;
};

