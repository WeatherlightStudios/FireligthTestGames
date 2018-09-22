#include "RacketAISystem.h"
#include <iostream>

RacketAISystem::RacketAISystem()
{
}


void RacketAISystem::Init()
{
	std::cout << "Init di RacketAISystem" << std::endl;
	registerComponent<Transform>();
	registerComponent<RacketAIComp>();
}

void RacketAISystem::Update(std::vector<BaseComponent*> components)
{
	Transform* transform = (Transform*)components[0];
	RacketAIComp* AI = (RacketAIComp*)components[1];
	//std::cout << AI->ballpos.y << std::endl;
}

RacketAISystem::~RacketAISystem()
{
}
