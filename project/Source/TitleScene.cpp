#include "TitleScene.h"
#include "Screen.h"
#include "dontDes.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	dontDes* dontdes = FindGameObject<dontDes>();
	if (CheckHitKey(KEY_INPUT_P)) {
		dontdes->point = 0;
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	if (Screen::DEVELOPER_MODE == TRUE) {
		extern const char* Version();
		DrawString(0, 20, Version(), GetColor(255, 255, 255));
		DrawString(0, 0, "TITLE SCENE", GetColor(255, 255, 255));
		DrawFormatString(100, 100, GetColor(255, 255, 255), "%4.1f", 1.0f / Time::DeltaTime());
	}
	DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}