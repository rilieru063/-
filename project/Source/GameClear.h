#pragma once
#include "../Library/SceneBase.h"

class GameClear:public SceneBase
{
public:
	GameClear();
	~GameClear();
	void Update() override;
	void Draw()override;

private:

};