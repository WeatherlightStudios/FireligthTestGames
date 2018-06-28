#pragma once
#include <FireLight.h>
#include "Match.h"
class Game : public App
{
public:
	Game();
	void Init();
	~Game();
private:
	Match _scene;
};

