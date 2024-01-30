#include "Game.h"


// Initializaers

void Game::initVar()
{
	this->windowSize = { 600, 600 };
	this->endgame = false;
	this->Point = 0;
	this->total = 0;

	this->printPoint.setFont(this->font);
	this->printPoint.setCharacterSize(36);
	this->printPoint.setString("None");
	this->printPoint.setFillColor(sf::Color(189, 179, 222));
	this->printPoint.setPosition(sf::Vector2f(16, 16));
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(this->windowSize, "Snake Game", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	this->window->setFramerateLimit(5);
}

void Game::initwalls()
{
	Walls[0].setFillColor(sf::Color(221, 221, 221, 255));
	Walls[1].setFillColor(sf::Color(221, 221, 221, 255));
	Walls[2].setFillColor(sf::Color(221, 221, 221, 255));
	Walls[3].setFillColor(sf::Color(221, 221, 221, 255));

	Walls[0].setPosition(sf::Vector2f(0.0f, 0.0f));
	Walls[1].setPosition(sf::Vector2f(0.0f, 0.0f));
	Walls[2].setPosition(sf::Vector2f(0.0f, this->windowSize.height - 15));
	Walls[3].setPosition(sf::Vector2f(this->windowSize.width - 15, 0.0f));

	Walls[0].setSize(sf::Vector2f(this->windowSize.width, 15.0f));
	Walls[1].setSize(sf::Vector2f(15.0f, this->windowSize.height));
	Walls[2].setSize(sf::Vector2f(this->windowSize.width, 15.0f));
	Walls[3].setSize(sf::Vector2f(15.0f, this->windowSize.height));

	this->PlaceFood();

}

void Game::initSnake()
{
	this->snake.initVariable(this->windowSize);

	this->Snake_Body.push_back(snake);
}

void Game::initFont()
{
	if (!this->font.loadFromFile("Font/Orbitron/Orbitron-Bold.ttf"))
		std::cout << "ERROR::GAME::INITFONT::Failed to load font\n";
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
			else if (this->ev.key.code == sf::Keyboard::Up || this->ev.key.code == sf::Keyboard::W)
			{
				if (!(this->Verticalpressed))
				{
					this->speed.x = 0;
					this->speed.y = -1;
					this->Verticalpressed = true;
					this->Horizontalpressed = false;
				}
			}
			else if (this->ev.key.code == sf::Keyboard::Down || this->ev.key.code == sf::Keyboard::S)
			{
				if (!(this->Verticalpressed))
				{
					this->speed.x = 0;
					this->speed.y = 1;
					this->Verticalpressed = true;
					this->Horizontalpressed = false;
				}
			}
			else if (this->ev.key.code == sf::Keyboard::Right || this->ev.key.code == sf::Keyboard::D)
			{
				if (!(this->Horizontalpressed))
				{
					this->speed.x = 1;
					this->speed.y = 0;
					this->Verticalpressed = false;
					this->Horizontalpressed = true;
				}
			}
			else if (this->ev.key.code == sf::Keyboard::Left || this->ev.key.code == sf::Keyboard::A)
			{
				if (!(this->Horizontalpressed))
				{
					this->speed.x = -1;
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
	float x = static_cast<float>(16 + rand() % ((this->windowSize.width - 50) - 16 + 1));
	float y = static_cast<float>(16 + rand() % (this->windowSize.height - 66 + 1));

	food.setPosition(x, y);

	//std::cout << food.getPosition().x << " " << food.getPosition().y << "\n" ;
}

void Game::addSnakeTail()
{
	Snake sn;
	sn.initColor();
	this->Snake_Body.push_back(sn);
	//std::cout << this->Snake_Body.size();

	for (int i = 0; i < this->Snake_Body.size(); i++)
	{
		std::cout << "Position of " << i << "  : " << this->Snake_Body[i].getPosition().x << " " << this->Snake_Body[i].getPosition().y << "\n";

	}
}

Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initwalls();
	this->initSnake();
	this->initFont();
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
		if (wall.getGlobalBounds().contains(this->Snake_Body[0].getPosition())) 
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
		this->updateText();
		this->hitWall();
	}

}

void Game::updateSnake()
{
	/*for (int i = 0; i < this->Snake_Body.size(); i++)
	{
		this->Snake_Body[i].setPosition(sf::Vector2f(Snake_Body[i].getPosition() + speed *  scl));
	}*/
	float mult = 1.0f;

	for (int i = total; i > 0; i--)
	{
		Snake_Body[i].setPosition(this->Snake_Body[i - 1].getPosition().x - scl * speed.x * mult , this->Snake_Body[i - 1].getPosition().y - scl * speed.y * mult);
	}
	this->Snake_Body[0].setPosition(sf::Vector2f(Snake_Body[0].getPosition() + speed * scl));


	for (int i = 1; i < this->Snake_Body.size(); i++)
	{
		if (this->Snake_Body[i].getGlobalBounds().contains(this->Snake_Body[0].getPosition()))
			this->endgame = true;
	}
	
	//this->Snake_Body[this->total - 1].setPosition
}

void Game::updateFood()
{
	if (Snake_Body[0].getGlobalBounds().contains(food.getPosition()))
	{
		Point += food.givePoint();
		this->PlaceFood();
		this->addSnakeTail();
		this->total++;
		//std::cout << "Point: " << this->Point << "\n";
	}
}

void Game::updateText()
{
	std::stringstream ss;
	
	ss << "Points: " << this->Point;

	this->printPoint.setString(ss.str());
}

void Game::render()
{
	this->window->clear();

	this->renderWall();
	this->renderFood();
	this->renerSnake();
	this->renderText(*window);

	this->window->display();

}

void Game::renerSnake()
{
	for (int i = 0; i < this->Snake_Body.size(); i++)
	{
		this->window->draw(this->Snake_Body[i]);
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

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->printPoint);
}
