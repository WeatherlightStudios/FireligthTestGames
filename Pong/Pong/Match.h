#pragma once
#include <FireLight.h>
class Match : public Scene
{
public:
	Match();
	void Init();
	void CameraUpdate(Camera *camera);
	void Update(double dt);
	void Close();

	~Match();
};

