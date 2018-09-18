#include "InputBarMoverSystem.h"



InputBarMoverSystem::InputBarMoverSystem()
{
}

void InputBarMoverSystem::Init() {
	registerComponent<Transform>();
	registerComponent<InputBarMoverComponent>();
}


void InputBarMoverSystem::Update(std::vector<BaseComponent*> components) {
	Transform* transform = (Transform*)components[0];
	InputBarMoverComponent* mover = (InputBarMoverComponent*)components[1];

	glm::vec3 pos = transform->position;
	glm::vec3 dir = glm::vec3(0, 0, 0);
	float speed = mover->speed;

	if (Window::isKeyDown(GLFW_KEY_W)) {
		dir += glm::vec3(0, 1, 0);
	}
	if (Window::isKeyDown(GLFW_KEY_S)) {
		dir += glm::vec3(0, -1, 0);
	}

	pos += dir * speed * (float)Time::GetDeltaTime();

	glm::vec2 scale = transform->scale;
	if (pos.y + scale.y > Window::getHeight()/ 2.0f) {
		pos.y = Window::getHeight()/2.0f;
	}
	transform->position = pos;
}

InputBarMoverSystem::~InputBarMoverSystem()
{
}
