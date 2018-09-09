#pragma once
#include <FireLight.h>
class Match : public Scene
{
public:
	Match();
	void Init();
	void Update();
	void Close();

	Sprite *racket1;
	Sprite *racket2;
	Sprite *ball;
	
	float speed = 150;
	float ballSpeed = 100;
	glm::vec3 ballDir = glm::vec3(-.25f, .75f, 0);
	~Match();

private:
	void CollisionWithWalls();
	void CollisionWithRackets();
	bool IsInsideRect(glm::vec3 pos, glm::vec3 rectSize, glm::vec3 rectPos);
};

