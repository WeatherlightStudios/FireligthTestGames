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
	
	auto var1 = ResourceManager::LoadTexture("resources/Sprites/Pong_White.png", true, "PongSprite");
	auto var2 = ResourceManager::LoadShader("resources/Shaders/2D_shader.vert", "resources/Shaders/2D_shader.frag", NULL,"sha_Basic2D");

	racket1 = new Sprite(var1, var2);
	racket1->setRows(2, 1);
	racket1->setOffset(1, 0);
	racket1->set_local_scale(glm::vec3(1, 1, 1));
	racket1->set_local_scale(glm::vec3(.3f, .8, 1));
	glm::vec3 centering1 = glm::vec3(-racket1->get_local_scale().x, racket1->get_local_scale().y, racket1->get_local_scale().z) / 2.0f;
	racket1->set_local_position(centering1);
	racket1->set_local_position(racket1->get_local_position() + glm::vec3(1,0,0));

	racket2 = new Sprite(var1, var2);
	racket2->setRows(2, 1);
	racket2->setOffset(1, 0);
	racket2->set_local_scale(glm::vec3(.3f, .8, 1));
	glm::vec3 centering2 = glm::vec3(-racket2->get_local_scale().x, racket2->get_local_scale().y, racket2->get_local_scale().z) / 2.0f;
	racket2->set_local_position(centering2);
	racket2->set_local_position(racket2->get_local_position() + glm::vec3(-1,0,0));



	ball = new Sprite(var1, var2);
	ball->setRows(2, 1);
	ball->setOffset(0, 0);
	ball->set_local_scale(glm::vec3(.25f, .5, .5));
	glm::vec3 centering3 = glm::vec3(-ball->get_local_scale().x, ball->get_local_scale().y, ball->get_local_scale().z) / 2.0f;
	ball->set_local_position(centering3);

	this->add_object(*racket1);
	this->add_object(*racket2);
	this->add_object(*ball);
}

void Match::CameraUpdate(Camera *camera) {

}

void Match::Update(double dt) {
	
}

void Match::Close() {

}


Match::~Match()
{
}
