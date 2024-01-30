#include "Snake.h"

void Snake::initVariable(sf::VideoMode vm)
{
	this->x = 16 + rand() % ((vm.width - 50) - 16 + 1);
	this->y = 16 + rand() % ((vm.height - 50) - 16 + 1);

	this->initColor();

}

void Snake::initColor()
{
	this->setFillColor(color);
	this->setPosition(sf::Vector2f(x, y));
	this->setSize(sf::Vector2f(scl * 2, scl * 2));
	//this->setRadius(scl);
}



Snake::Snake()
{
	
}

Snake::~Snake()
{

}
