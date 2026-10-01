#include "GameClear.h"
#include "Screen.h"
#include "PlayScene.h"

GameClear::GameClear()
{
}

GameClear::~GameClear()
{
}

void GameClear::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void GameClear::Draw()
{
	PlayScene* playscene = FindGameObject<PlayScene>();
	if (playscene->point >= 50) {
		DrawString(Screen::WIDTH / 2 - 50, Screen::HEIGHT / 2 + 20, "Great!", GetColor(255, 255, 255));
	}
	else if (playscene->point >= 30) {
		DrawString(Screen::WIDTH / 2 - 50, Screen::HEIGHT / 2 + 20, "Nice!", GetColor(255, 255, 255));
	}
	else {
		DrawString(Screen::WIDTH / 2 - 70, Screen::HEIGHT / 2 + 20, "Try harder!", GetColor(255, 255, 255));
	}
}