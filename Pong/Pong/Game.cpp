#include "Game.h"


Game::Game()
{
}

void Game::Init() {
	glClearColor(0, 0, 0, 1);
	SceneManager::add_scene(&_scene, "Match Scene");
	SceneManager::change_current_scene_to("Match Scene");
}


Game::~Game()
{
}
