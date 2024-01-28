#include "Snake.h"

void Snake::initVariable(sf::VideoMode vm)
{
	this->x = rand() % vm.width;
	this->y = rand() % vm.height;


	this->setFillColor(sf::Color::White);
	this->setPosition(sf::Vector2f(x, y));
	this->setSize(sf::Vector2f(30.0f, 30.0f));
}



Snake::Snake()
{
	
}

Snake::~Snake()
{

}
