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
	
	auto var1 = Resource::LoadTexture("resources/Sprites/Pong_White.png", true, "PongSprite");
	auto var2 = Resource::LoadShader("resources/Shaders/2D_shader.vert", "resources/Shaders/2D_shader.frag", NULL,"sha_Basic2D");
	
	World::addGameSystem(new MovementSystem());
	ball = World::CreateEntity();
	ball->add_Component<Transform>(glm::vec3(0, 0, 0), 0 , glm::vec2(1, 1));
	ball->add_Component<MoveComponent>(ballSpeed, ballDir);
	ball->add_Component<MeshRender>();
	ball->add_Component<Sprite>(var1, var2, 2 , 1, 0, 0, 75, 75);


	/*
	for (int i = 0; i < 1000; i++) {
		ball = new Sprite(var1, var2, 2, 1);
		
		auto randX = rand() % 801 - 400;
		auto randY = rand() % 601 - 300;
		ball->setOffset(0, 0);
		ball->set_scale(2, 2, 2);
		ball->translate(randX, randY, 0);
		this->add_object(*ball);
	}
	
	
	racket1 = new Sprite(var1, var2, 2, 1);
	racket1->setOffset(1, 0);
	racket1->translate(300,0,0);

	racket1->set_scale(2, 2, 2);

	racket2 = new Sprite(var1, var2, 2, 1);
	racket2->setOffset(1, 0);
	racket2->translate(-300,0,0);

	racket2->set_scale(2, 2, 2);


	ball = new Sprite(var1, var2, 2, 1);
	ball->setOffset(0, 0);
	ball->set_scale(2, 2, 2);

	this->add_object(*racket1);
	this->add_object(*racket2);
	this->add_object(*ball);
	*/
}


void Match::Update() {
	

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
