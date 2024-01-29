#include "Snake.h"

void Snake::initVariable(sf::VideoMode vm)
{
	this->x = rand() % vm.width;
	this->y = rand() % vm.height;

	this->initColor();

}

void Snake::initColor()
{
	this->setFillColor(color);
	this->setPosition(sf::Vector2f(x, y));
	this->setSize(sf::Vector2f(scl * 2, scl * 2));
}



Snake::Snake()
{
	
}

Snake::~Snake()
{

}
