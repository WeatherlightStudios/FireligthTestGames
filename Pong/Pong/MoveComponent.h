#pragma once
#include <FireLight.h>

struct MoveComponent : public Component<MoveComponent> {
	MoveComponent(float speed, glm::vec3 dir, float ballRadius, bool enabled) : 
		speed(speed), dir(dir), ballRadius(ballRadius), enabled(enabled) {}

	float speed;
	glm::vec3 dir;
	float ballRadius;
	bool enabled;
};