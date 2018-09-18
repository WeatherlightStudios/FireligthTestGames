#pragma once
#include <FireLight.h>
struct RacketAIComp : public Component<RacketAIComp>{

	RacketAIComp(float barHeight, float speed) :
		barHeight(barHeight), speed(speed){}

	float barHeight;
	float speed;
	glm::vec3 ballpos;
};