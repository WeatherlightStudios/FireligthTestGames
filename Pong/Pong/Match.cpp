#include "Match.h"



Match::Match()
{

}


/*
	auto var1 = Resource::Shader("resources/Shaders/2D_shader.vert", "resources/Shaders/2D_shader.frag", NULL,"sha_Basic2D");
	auto var2 = Resource::Texture("resources/Sprites/Pong_White.png", true, "PongSprite");

	racket1 = new Sprite(var2, var1, 2, 1, 1, 0);
	racket2 = new Sprite(var2, var1, 2, 1, 1, 0);
	ball = new Sprite(var2, var1, 2, 1, 0, 0);

	racket1->translate(glm::vec3(1,0,0));
	racket2->translate(glm::vec3(-1,0,0));

	this->add_object(*racket1);
	this->add_object(*racket2);
	this->add_object(*ball);
*/

void Match::Init() {
	
	//get texture
	auto text = Resource::LoadTexture("resources/Sprites/Pong_White.png", true, "PongSprite");
	//get shader
	//auto shad = Resource::LoadShader("resources/Shaders/2D_shader.vert", "resources/Shaders/2D_shader.frag", NULL,"sha_Basic2D");
	//added custom game system to world
	World::addGameSystem(new MovementSystem());
	World::addGameSystem(new InputBarMoverSystem());
	World::addGameSystem(new RacketAISystem());

	///BALL///
	//created empty entity from world
	ball = World::CreateEntity();

	//added component transform with initialyzation (vec3 position, float angle, vec2 scale)
	ball->add_Component<Transform>(glm::vec3(0, 0, 0), 0 , glm::vec2(2, 2));
	//added component custom with initialyzation
	ball->add_Component<MoveComponent>(ballSpeed, ballDir, ballRadius, true);
	//added component sprite(texture, shader, x and y divisions in texture, x and y offset in texture
	//,x and y pixel size of the sprite (will get automatically calculated)
	//N.B. add first Sprite then MeshRenderer
	//ball->add_Component<Sprite>(text, shad, 2 , 1, 0, 0, 64/2, 64/1);
	ball->add_Component<MeshRender>();


	racket1 = World::CreateEntity();

	racket1->add_Component<Transform>(glm::vec3(-200, 0, 0), 0, glm::vec2(2, 2));
	racket1->add_Component<InputBarMoverComponent>(racketSpeed, barHeight);
	//racket1->add_Component<Sprite>(text, shad, 2, 1, 1, 0, 64 / 2, 64 / 1);
	racket1->add_Component<MeshRender>();

	racket2 = World::CreateEntity();

	racket2->add_Component<Transform>(glm::vec3(200, 0, 0), 0, glm::vec2(2, 2));
	/*
	*/
	/*
	racket2->add_Component<RacketAIComp>(racketSpeed, barHeight);
	racket2->add_Component<Sprite>(text, shad, 2, 1, 1, 0, 64 / 2, 64 / 1);
	racket2->add_Component<MeshRender>();
	*/
}


void Match::Update() {
	
	//racket2->getComponent<RacketAIComp>()->ballpos = ball->getComponent<Transform>()->position;

	/*

	//Player Racket Movement
	if (Window::isKeyDown(GLFW_KEY_W)) {
		racket2->translate(0, speed * Time::GetDeltaTime(), 0);
	}
	if (Window::isKeyDown(GLFW_KEY_S)) {
		racket2->translate(0, -speed * Time::GetDeltaTime(), 0);
		//ball->set_local_position(ball->local_position() + glm::vec3(0, -ballSpeed*Time::GetDeltaTime(), 0));
	}

	ball->translate(glm::normalize(ballDir) * ballSpeed*(float)Time::GetDeltaTime());

	Match::CollisionWithWalls();
	Match::CollisionWithRackets();
	
	if (ball->local_position().x >= 400) {
		//player scored
	}
	if (ball->local_position().x <= -400) {
		//AI scored
	}
	*/
	
}
/*
void Match::CollisionWithRackets() {
	glm::vec3 ballNextPos = ball->local_position() + glm::normalize(ballDir)*ballSpeed;

	if (Match::IsInsideRect(ball->local_position(), racket2->local_scale(), racket2->local_position())) {
		ballDir.x *= -1;
	}
}

bool Match::IsInsideRect(glm::vec3 pos, glm::vec3 rectSize, glm::vec3 rectPos) {
	if (pos.x <= rectSize.x + rectPos.x && pos.x >= rectPos.x - rectSize.x) {
		//sono dentro la fascia verticale
		if (pos.y <= rectPos.y + rectSize.y && pos.y >= rectPos.y - rectSize.y) {
			return true;
		}
	}
	return false;
}

void Match::CollisionWithWalls() {
	//Player
	//controlla posizione del pivot che è nell'angolo in alto a sinistra
	if (racket2->local_position().y + racket2->local_scale().y/2.f > 300) {
		racket2->set_position(racket2->local_position().x, 300 + racket2->local_scale().y / 2.f, racket2->local_position().z);
	}

	if (racket2->local_position().y - racket2->local_scale().y/2.0f < -300) {
		racket2->set_position(racket2->local_position().x, -300 - racket2->local_scale().y / 2.f, racket2->local_position().z);
	}


	//AI
	if (racket1->local_position().y + racket1->local_scale().y / 2.f > 300) {
		racket1->set_position(racket1->local_position().x, 300 + racket1->local_scale().y / 2.f, racket1->local_position().z);
	}

	if (racket1->local_position().y - racket1->local_scale().y / 2.0f < -300) {
		racket1->set_position(racket1->local_position().x, -300 - racket1->local_scale().y / 2.0f, racket1->local_position().z);
	}

	//Ball
	if (ball->local_position().y + ball->local_scale().y/2.f > 300) {
		ballDir.y *= -1;//ball->set_local_position(glm::vec3(ball->local_position().x, 1.19f, ball->local_position().z));
	}

	if (ball->local_position().y - ball->local_scale().y/2.f < -300) {
		ballDir.y *= -1;//ball->set_local_position(glm::vec3(ball->local_position().x, -1.2f + ballSize.y, ball->local_position().z));
	}
}
*/

void Match::Close() {

}


Match::~Match()
{
}
