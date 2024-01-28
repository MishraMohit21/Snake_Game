#include "Game.h"

int main() {

	std::cout << " ----------------- ";
	std::srand(static_cast<unsigned>(time(NULL)));
	
	Game snake;

	while (snake.running() && snake.EndGame())
	{
		snake.update();

		snake.render();
	}

	return 0;
}