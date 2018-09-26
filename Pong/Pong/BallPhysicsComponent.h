#pragma once
#include <FireLight.h>
#include "InputBarMoverComponent.h"
struct BallPhysicsComponent : public Component<BallPhysicsComponent>
{
	BallPhysicsComponent(Transform* ballTransform, MoveComponent* ballMovement, int divs, glm::vec3* moveDir, int racketSpeed)
		:ballTransform(ballTransform), ballMovement(ballMovement), divisions(divs), moveDir(moveDir), racketSpeed(racketSpeed){}

	Transform* ballTransform;
	MoveComponent* ballMovement;
	int divisions;
	glm::vec2 racketHalfSize = glm::vec2(4.5f, 24) * 2.0f;
	int ballRadius = 15;
	glm::vec3* moveDir;
	int racketSpeed;
};