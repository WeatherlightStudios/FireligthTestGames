#pragma once
#include <FireLight.h>
#include "MoveComponent.h"
#include "BallPhysicsComponent.h"
class BallPhysicsSystem : public System
{
public:

	void Init();
	void Update(std::vector<BaseComponent*> components);

	std::tuple<bool,int> CheckCollision(glm::vec3 ballPos, float ballRadius, glm::vec3 racketPos, glm::vec2 racketSize, int divs);

	BallPhysicsSystem();
	~BallPhysicsSystem();
};

