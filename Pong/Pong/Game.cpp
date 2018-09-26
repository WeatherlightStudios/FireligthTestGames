#include "Game.h"


Game::Game()
{
}

void Game::Init() {
	glClearColor(0, 0, 0, 1);
	SceneManager::AddScene(&_scene, "Match Scene");
	SceneManager::changeCurrentSceneTo("Match Scene");
}


Game::~Game()
{
}
