#pragma once
#include "Snake.h"

class Food : public sf::CircleShape
{
	sf::Color Cherry = { 237, 35, 46, 255 }, Gold_Yellow = { 255, 215, 0, 255 }, Lime = { 153, 204, 0, 255 }, Elblue = { 0, 191, 255, 255 };

	float point;

public:
	
	void Foodinit();
	const float givePoint() const;
	
};

