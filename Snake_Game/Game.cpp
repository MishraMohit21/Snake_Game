#include "Game.h"


// Initializaers

void Game::initVar()
{
	this->windowSize = { 800, 800 };
	this->endgame = false;

}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(this->windowSize, "Snake Game", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	
}

void Game::initwalls()
{
	Walls[0].setFillColor(sf::Color(221, 221, 221, 255));
	Walls[1].setFillColor(sf::Color(221, 221, 221, 255));
	Walls[2].setFillColor(sf::Color(221, 221, 221, 255));
	Walls[3].setFillColor(sf::Color(221, 221, 221, 255));

	Walls[0].setPosition(sf::Vector2f(0.0f, 0.0f));
	Walls[1].setPosition(sf::Vector2f(0.0f, 0.0f));
	Walls[2].setPosition(sf::Vector2f(0.0f, 785.0f));
	Walls[3].setPosition(sf::Vector2f(785.0f, 0.0f));

	Walls[0].setSize(sf::Vector2f(800.0f, 15.0f));
	Walls[1].setSize(sf::Vector2f(15.0f, 800.0f));
	Walls[2].setSize(sf::Vector2f(800.0f, 15.0f));
	Walls[3].setSize(sf::Vector2f(15.0f, 800.0f));

	this->PlaceFood();

}

void Game::initSnake()
{
	this->snake.initVariable(this->windowSize);
	this->Snake_Body.push_back(snake);
}



void Game::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::Up)
			{
				if (!(this->Verticalpressed))
				{
					this->speed.x = 0;
					this->speed.y = -0.05;
					this->Verticalpressed = true;
					this->Horizontalpressed = false;
				}
			}
			else if (this->ev.key.code == sf::Keyboard::Down)
			{
				if (!(this->Verticalpressed))
				{
					this->speed.x = 0;
					this->speed.y = 0.075;
					this->Verticalpressed = true;
					this->Horizontalpressed = false;
				}
			}
			else if (this->ev.key.code == sf::Keyboard::Right)
			{
				if (!(this->Horizontalpressed))
				{
					this->speed.x = 0.05;
					this->speed.y = 0;
					this->Verticalpressed = false;
					this->Horizontalpressed = true;
				}
			}
			else if (this->ev.key.code == sf::Keyboard::Left)
			{
				if (!(this->Horizontalpressed))
				{
					this->speed.x = -0.05;
					this->speed.y = 0;
					this->Verticalpressed = false;
					this->Horizontalpressed = true;
				}
			}
		}
	}
}

void Game::PlaceFood()
{
	food.Foodinit();
	float x = static_cast<float>(16 + rand() % (784 - 16 + 1));
	float y = static_cast<float>(16 + rand() % (784 - 16 + 1));

	food.setPosition(x, y);

	std::cout << food.getPosition().x << " " << food.getPosition().y << "\n" ;
}

void Game::addSnakeTail()
{

}

Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initwalls();
	this->initSnake();
}

Game::~Game()
{
	//delete this->snake;
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::EndGame() const
{
	return !this->endgame;
}

void Game::hitWall()
{
	for (auto& wall : Walls)
	{
		if (wall.getGlobalBounds().contains(this->Snake_Body[Snake_Body.size() - 1].getPosition())) 
		{
			std::cout << "You hit a wall Sorry\n";
			endgame = true;
		}
	}
}

void Game::update()
{
	this->pollEvent();

	if (this->endgame == false)
	{
		this->updateFood();
		this->updateSnake();
		this->hitWall();
	}

}

void Game::updateSnake()
{
	this->Snake_Body[Snake_Body.size() - 1].setPosition(sf::Vector2f(Snake_Body[Snake_Body.size() - 1].getPosition() + speed));
	for (int i = 0; i < this->Snake_Body.size(); i++)
	{
		if (this->Snake_Body.size() > 1)
		{
			this->Snake_Body[i].setPosition(this->Snake_Body[i + 1].getPosition());
		}
	}
}

void Game::updateFood()
{
	if (Snake_Body[Snake_Body.size() - 1].getGlobalBounds().contains(food.getPosition()))
	this->PlaceFood();
}

void Game::render()
{
	this->window->clear();

	this->renderWall();
	this->renderFood();
	this->renerSnake();

	this->window->display();

}

void Game::renerSnake()
{
	for (auto& temp : this->Snake_Body)
	{
		this->window->draw(temp);
	}
}

void Game::renderWall()
{
	for (auto& wall : Walls)
	{
		this->window->draw(wall);
	}
}

void Game::renderFood()
{
	this->window->draw(this->food);
}
