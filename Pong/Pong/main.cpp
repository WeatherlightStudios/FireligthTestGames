#include <FireLight.h>
#include "Game.h"
#include <memory.h>
int main() {
	
	std::unique_ptr<Game> Pong(new Game);
	Pong->setWindowDimension(800, 600);
	Pong->setWindowName("Pong");
	Pong->Start();
	return 0;
}