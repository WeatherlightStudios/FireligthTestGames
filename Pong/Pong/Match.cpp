#include "Match.h"


Match::Match()
{

}

void Match::Init() {
	
	//get texture
	auto text = Resource::LoadTexture("resources/Sprites/Pong_White.png", true, "PongSprite");
	//get shader
	auto shad = Resource::LoadShader("resources/Shaders/2D_shader.vert", "resources/Shaders/2D_shader.frag", NULL,"sha_Basic2D");
	//added custom game system to world
	World::addGameSystem(new MovementSystem());
	World::addGameSystem(new InputBarMoverSystem());
	World::addGameSystem(new RacketAISystem());
	World::addGameSystem(new BallPhysicsSystem());

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
	ball->add_Component<Sprite>(text, shad, 2 , 1, 0, 0, 64/2, 64/1);
	ball->add_Component<MeshRender>();


	racket1 = World::CreateEntity();

	racket1->add_Component<Transform>(glm::vec3(-300, 0, 0), 0, glm::vec2(2, 2));
	//racket1->add_Component<InputBarMoverComponent>(racketSpeed, barHeight);
	racket1->add_Component<RacketAIComp>(racketSpeed, barHeight);
	racket1->add_Component<Sprite>(text, shad, 2, 1, 1, 0, 64 / 2, 64 / 1);
	racket1->add_Component<MeshRender>();
	racket1->add_Component<BallPhysicsComponent>(
		ball->getComponent<Transform>(),
		ball->getComponent<MoveComponent>(),
		6,
		//(&racket1->getComponent<InputBarMoverComponent>()->dir),
		(&racket1->getComponent<RacketAIComp>()->moveDir),
		racketSpeed);
	
	racket2 = World::CreateEntity();

	racket2->add_Component<Transform>(glm::vec3(300, 0, 0), 0, glm::vec2(2, 2));
	racket2->add_Component<RacketAIComp>(racketSpeed, barHeight);
	racket2->add_Component<Sprite>(text, shad, 2, 1, 1, 0, 64 / 2, 64 / 1);
	racket2->add_Component<MeshRender>();
	racket2->add_Component<BallPhysicsComponent>(
		ball->getComponent<Transform>(),
		ball->getComponent<MoveComponent>(),
		6,
		(&racket2->getComponent<RacketAIComp>()->moveDir),
		racketSpeed);

	//ball->add_Component<BallPhysicsComponent>(racket1->getComponent<Transform>(), racket1->getComponent<InputBarMoverComponent>(), 6, 7.5f * 2.0f);
}


void Match::Update() {
	racket2->getComponent<RacketAIComp>()->ballpos = ball->getComponent<Transform>()->position;
	racket1->getComponent<RacketAIComp>()->ballpos = ball->getComponent<Transform>()->position;


	float numb = RandomNumber::GaussianRange(0, 100);
	std::cout << numb << std::endl;

}

void Match::Close() {

}


Match::~Match()
{
}
