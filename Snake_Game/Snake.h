#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

const float scl = 20.0f;

class Snake : public sf::RectangleShape
{
	

	float x;
	float y;
	float xspeed = 1.0;
	float yspeed = 0.0;
	sf::Color color = {0, 100, 0};


public:

	void initVariable(sf::VideoMode vm);
	void initColor();


	Snake();
	//Snake(sf::VideoMode vm);
	virtual ~Snake();

	
};

