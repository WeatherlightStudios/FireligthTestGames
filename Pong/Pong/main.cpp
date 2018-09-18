#include <FireLight.h>
#include "Game.h"
#include <memory.h>
int main() {
	
	std::unique_ptr<Game> Pong(new Game);
	Pong->set_window_dimension(800, 600);
	Pong->set_windiw_name("Pong");
	Pong->Start();
	return 0;
}