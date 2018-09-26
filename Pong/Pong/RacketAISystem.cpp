#include "RacketAISystem.h"
#include <iostream>

RacketAISystem::RacketAISystem()
{
}


void RacketAISystem::Init()
{
	//std::cout << "Init di RacketAISystem" << std::endl;
	registerComponent<Transform>();
	registerComponent<RacketAIComp>();
}

void RacketAISystem::Update(std::vector<BaseComponent*> components)
{
	Transform* transform = (Transform*)components[0];
	RacketAIComp* AI = (RacketAIComp*)components[1];


	if (AI->ballpos.y == transform->position.y)
		AI->moveDir = glm::vec3(0, 0, 0);
	if (AI->ballpos.y < transform->position.y)
		AI->moveDir = glm::vec3(0, -1, 0);
	if (AI->ballpos.y > transform->position.y)
		AI->moveDir = glm::vec3(0, 1, 0);

	transform->position = glm::vec3(transform->position.x, AI->ballpos.y, 0);


	//std::cout << AI->ballpos.y << std::endl;
}

RacketAISystem::~RacketAISystem()
{
}
