#pragma once
#include <FireLight.h>
#include "InputBarMoverComponent.h"
class InputBarMoverSystem : public System
{
public:
	InputBarMoverSystem();
	~InputBarMoverSystem();

	void Init();
	void Update(std::vector<BaseComponent*> components);
};

