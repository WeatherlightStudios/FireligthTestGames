#pragma once
#include <FireLight.h>
class MovementSystem : public System
{
public:
	MovementSystem();
	~MovementSystem();

	void Init();
	void Update(std::vector<BaseComponent*> components);
};

