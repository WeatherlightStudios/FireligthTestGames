#pragma once
#include <FireLight.h>
struct InputBarMoverComponent : public Component<InputBarMoverComponent>
{

	InputBarMoverComponent(float speed):
	speed(speed) { }

	float speed;
};