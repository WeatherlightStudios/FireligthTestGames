#include "Match.h"



Match::Match()
{

}


/*
	auto var1 = Resource::Shader("resources/Shaders/2D_shader.vert", "resources/Shaders/2D_shader.frag", NULL,"sha_Basic2D");
	auto var2 = Resource::Texture("resources/Sprites/Pong_White.png", true, "PongSprite");

	racket = new Sprite(var2, var1, 2, 1, 1, 0);
	ball = new Sprite(var2, var1, 2, 1, 0, 0);

	this->add_object(*racket);
	this->add_object(*ball);
*/

void Match::Init() {
	
	ResourceManager::LoadShader("resources/Shaders/2D_shader.vert", "resources/Shaders/2D_shader.frag", NULL,"sha_Basic2D");
	ResourceManager::LoadTexture("resources/Sprites/Pong_White.png", true, "PongSprite");
	racket = new Sprite(ResourceManager::GetTexture("PongSprite"), ResourceManager::GetShader("sha_Basic2D"));
	racket->setRows(2, 1);
	racket->setOffset(1, 0);
	racket->set_local_scale(glm::vec3(.5f, 1, 1));

	ball = new Sprite(ResourceManager::GetTexture("PongSprite"), ResourceManager::GetShader("sha_Basic2D"));
	ball->setRows(2, 1);
	ball->setOffset(0, 0);
	ball->set_local_scale(glm::vec3(.5f, 1, 1));

	this->add_object(*racket);
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
