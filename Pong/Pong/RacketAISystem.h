#pragma once
#include <FireLight.h>
#include "RacketAIComp.h"
class RacketAISystem : public System
{
public:
	RacketAISystem();

	void Init();
	void Update(std::vector<BaseComponent*> components);
	~RacketAISystem();
};

