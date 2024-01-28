#pragma once

#include "Food.h"


class Game
{
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode windowSize;

	Snake snake;
	std::vector<Snake> Snake_Body;
	sf::RectangleShape Walls[4];

	Food food;

	void initVar();
	void initWindow();
	void initwalls();
	void initSnake();


	void pollEvent();
	
	// Logic

	bool endgame;
	sf::Vector2f speed = { 0.0f, 0.0f };
	bool Verticalpressed, Horizontalpressed;

	void PlaceFood();
	void addSnakeTail();

public:

	Game();
	virtual ~Game();

	// Running 
	const bool running() const;
	const bool EndGame() const;

	void hitWall();

	// Updaates

	void update();
	void updateSnake();
	void updateFood();

	// Render

	void render();
	void renerSnake();
	void renderWall();
	void renderFood();

};

