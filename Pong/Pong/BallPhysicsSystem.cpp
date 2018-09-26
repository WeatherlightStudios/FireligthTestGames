#include "BallPhysicsSystem.h"



void BallPhysicsSystem::Init()
{
	registerComponent<Transform>();	//transform racchetta
	registerComponent<BallPhysicsComponent>();	//componente stesso
}

void BallPhysicsSystem::Update(std::vector<BaseComponent*> components)
{
	auto transform = (Transform*)components[0];
	auto physics = (BallPhysicsComponent*)components[1];
	
	MoveComponent* ballMovement = physics->ballMovement;
	glm::vec3 ballPos = physics->ballTransform->position;
	auto ballDir = ballMovement->dir;
	auto ballSpeed = ballMovement->speed;
	int ballRadius = physics->ballRadius;
	
	auto racketPos = transform->position;
	glm::vec2 racketHalfSize = physics->racketHalfSize;
	auto racketDir = physics->moveDir;
	auto racketSpeed = physics->racketSpeed;
	
	int divs = physics->divisions;

	int speedDivs = 10;
	float dividedSpeed = ballSpeed / (float)speedDivs;

	for (int i = 0; i <= speedDivs; i++) {
		float currentSpeed = dividedSpeed * i;

		auto collidedInfo = CheckCollision(ballPos + ballDir * currentSpeed * (float)Time::GetDeltaTime(), ballRadius, racketPos + *racketDir * (float)racketSpeed * (float)Time::GetDeltaTime(), racketHalfSize, divs);
	
		bool collided = std::get<0>(collidedInfo);
		if (collided) {
		
			ballSpeed *= 1.15;
			//std::cout << "speed: " << ballSpeed << std::endl;
			//std::cout << "collision at index: " << i << std::endl;
			int collisionIndex = std::get<1>(collidedInfo);
			//std::cout << "collided at side: " << collisionIndex << std::endl;

			//std::cout << transform->position.x << " " << transform->position.y << std::endl;
			if (collisionIndex == 0) {
				//right side
				ballDir.x *= -1;
				ballPos.x = racketPos.x + ballRadius + racketHalfSize.x;
			}
			else if (collisionIndex == 3) {
				//left side
				ballDir.x *= -1;
				ballPos.x = racketPos.x - ballRadius - racketHalfSize.x;
			}
			else if (collisionIndex == 1) {
				//bottom side
				ballDir.y *= -1;
				ballPos.y = racketPos.y - ballRadius - racketHalfSize.y;
			}
			else if (collisionIndex == 2) {
				//top side
				ballDir.y *= -1;
				ballPos.y = racketPos.y + ballRadius + racketHalfSize.y;
			}

			ballMovement->dir = ballDir;
			physics->ballTransform->position = ballPos;
			ballMovement->speed = ballSpeed;

			break;
		}
	}
}



std::tuple<bool, int> BallPhysicsSystem::CheckCollision(glm::vec3 ballPos, float ballRadius, glm::vec3 racketPos, glm::vec2 racketHalfSize, int divs)
{
	glm::vec3 cornerTL = racketPos + glm::vec3(-racketHalfSize.x, +racketHalfSize.y, 0);
	glm::vec3 cornerTR = racketPos + glm::vec3(+racketHalfSize.x, +racketHalfSize.y, 0);
	glm::vec3 cornerBL = racketPos + glm::vec3(-racketHalfSize.x, -racketHalfSize.y, 0);
	glm::vec3 cornerBR = racketPos + glm::vec3(+racketHalfSize.x, -racketHalfSize.y, 0);

	float horStep = racketHalfSize.x / divs * 2;
	float verStep = racketHalfSize.y / divs * 2;
	
	for (int i = 0; i <= divs; i++) {
		glm::vec3 pointPos = cornerBR + glm::vec3(0, verStep * i, 0);
		auto dist = glm::distance(pointPos, ballPos);
		if (dist < ballRadius) {
			//std::cout <<"dist: " << dist << std::endl;
			return std::make_tuple(true, 0);
		}
	}

	for (int i = 0; i <= divs; i++) {
		glm::vec3 pointPos = cornerBL + glm::vec3(horStep * i, 0, 0);
		if (glm::distance(pointPos, ballPos) < ballRadius) {
			return std::make_tuple(true, 1);
		}
	}

	for (int i = 0; i <= divs; i++) {
		glm::vec3 pointPos = cornerTL + glm::vec3(horStep * i, 0, 0);
		if (glm::distance(pointPos, ballPos) < ballRadius) {
			return std::make_tuple(true, 2);
		}
	}
	
	for (int i = 0; i <= divs; i++) {
		glm::vec3 pointPos = cornerBL + glm::vec3(0, verStep * i, 0);
		if (glm::distance(pointPos, ballPos) < ballRadius) {
			return std::make_tuple(true, 3);
		}
	}

	return std::make_tuple(false, 0);
}

BallPhysicsSystem::BallPhysicsSystem()
{
}


BallPhysicsSystem::~BallPhysicsSystem()
{
}
