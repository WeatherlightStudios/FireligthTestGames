#pragma once
#include <FireLight.h>

struct MoveComponent : public Component<MoveComponent> {
	MoveComponent(float speed, glm::vec3 dir) : 
		speed(speed), dir(dir) {}

	float speed;
	glm::vec3 dir;
};