#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <ctime>
#include <vector>

class Snake : public sf::RectangleShape
{
	float x;
	float y;
	float xspeed = 1.0;
	float yspeed = 0.0;

public:

	void initVariable(sf::VideoMode vm);



	Snake();
	//Snake(sf::VideoMode vm);
	virtual ~Snake();

	
};

