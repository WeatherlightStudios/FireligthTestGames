#include "MovementSystem.h"
#include <iostream>


MovementSystem::MovementSystem()
{
}

void MovementSystem::Init() {
	registerComponent<MoveComponent>();
	registerComponent<Transform>();
}

void MovementSystem::Update(std::vector<BaseComponent*> components) {
	MoveComponent* moveComp = (MoveComponent*)components[0];
	Transform* transform = (Transform*)components[1];

	glm::vec3 pos = transform->position;
	glm::vec3 dir = moveComp->dir;
	float speed = moveComp->speed;

	pos += dir * speed * (float)Time::GetDeltaTime();
	transform->position = pos;
}

MovementSystem::~MovementSystem()
{
}
