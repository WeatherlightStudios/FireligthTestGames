#pragma once
#include <FireLight.h>
struct InputBarMoverComponent : public Component<InputBarMoverComponent>
{

	InputBarMoverComponent(float speed, float barHeight):
	speed(speed), barHeight(barHeight) { }

	float speed;
	float barHeight;
};