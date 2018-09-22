#include "MovementSystem.h"
#include <iostream>


MovementSystem::MovementSystem()
{
}

void MovementSystem::Init() {
	std::cout << "Init di MovementSystem" << std::endl;
	registerComponent<MoveComponent>();
	registerComponent<Transform>();
}

void MovementSystem::Update(std::vector<BaseComponent*> components) {
	MoveComponent* moveComp = (MoveComponent*)components[0];
	//se è disattivato non ha senso andare avanti
	if (!moveComp->enabled) {
		return;
	}

	std::cout << "updated" << std::endl;

	Transform* transform = (Transform*)components[1];

	glm::vec3 pos = transform->position;
	glm::vec3 dir = moveComp->dir;
	float speed = moveComp->speed;

	pos += dir * speed * (float)Time::GetDeltaTime();

	float ballRadius = moveComp->ballRadius;
	glm::vec2 scale = transform->scale;

	if (pos.y + scale.y * ballRadius > Window::getHeight() / 2.0f) {
		dir.y *= -1;
		moveComp->dir = dir;
	}

	if (pos.y - scale.y * ballRadius < -Window::getHeight() / 2.0f) {
		dir.y *= -1;
		moveComp->dir = dir;
	}

	transform->position = pos;
}

MovementSystem::~MovementSystem()
{
}
