#pragma once
#include <FireLight.h>
#include "MovementSystem.h"
#include "MoveComponent.h"
#include "InputBarMoverSystem.h"
#include "InputBarMoverComponent.h"
class Match : public Scene
{
public:
	Match();
	~Match();
	void Init();
	void Update();
	void Close();
private:
	EntityHandler *racket1;
	EntityHandler *racket2;
	EntityHandler *ball;

	
	float ballSpeed = 10;
	glm::vec3 ballDir = glm::vec3(-.25f, .75f, 0);
	
	float racketSpeed = 75;

	//void CollisionWithWalls();
	//void CollisionWithRackets();
	//bool IsInsideRect(glm::vec3 pos, glm::vec3 rectSize, glm::vec3 rectPos);
	
	/*
public:

	Sprite *racket1;
	Sprite *racket2;
	Sprite *ball;
	

private:
	*/
};

