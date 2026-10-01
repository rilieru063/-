#include "PlayScene.h"
#include <DxLib.h>
#include "Screen.h"
#include<random>
#include "dontDes.h"

using namespace std;

PlayScene::PlayScene()
{
	image_player = LoadGraph("data/chara.png");
	image_coin = LoadGraph("data/item.png");
	image_en = LoadGraph("data/parts.png");
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	dontDes* dontdes = FindGameObject<dontDes>();
	if (ime > 0) {
		ime -= 1;
	}
	if (CheckHitKey(KEY_INPUT_K)) {
		ime = 0;
	}
	if (CheckHitKey(KEY_INPUT_0)) {
		dontdes->point += 50;
	}
	if (ime == 0) {
		SceneManager::ChangeScene("GAMECLEAR");
	}

	pat_st = STOP;

	if (CheckHitKey(KEY_INPUT_LSHIFT)) {
		shift_k += 1;
	}

	float speed = 2 + shift_k + ksk; //キャラの速さ

	if (ime > 0) {

		if (CheckHitKey(KEY_INPUT_W)) {
			GoUp(speed);
		}
		if (CheckHitKey(KEY_INPUT_A)) {
			GoLight(speed);
		}
		if (CheckHitKey(KEY_INPUT_S)) {
			GoDown(speed);
		}
		if (CheckHitKey(KEY_INPUT_D)) {
			GoRight(speed);
		}
		if (ad > en_x) {
			en_x += 0.5;
		}

		if (ad < en_x) {
			en_x -= 0.5;
		}

		if (ws > en_y) {
			en_y += 0.5;
		}
		if (ws < en_y) {
			en_y -= 0.5;
		}

	}

	count_k += 1;
	if (count_k >= 10) {
		count_k = 0;
		pat = (pat + 1) % 4 + pat_st;
	}

	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<>rand1920(0 + CHR_SIZE, 1920 - CHR_SIZE);
	mt19937 rk(rnd());
	uniform_int_distribution<>rand1080(0 + CHR_SIZE, 1080 - CHR_SIZE);

	float dx = coin_x - ad; //X座標の差
	float dy = coin_y - ws; //Y座標の差
	float d = sqrt(dx * dx + dy * dy); //距離を求める
	if (d < 53) {     //コインとの当たり判定
		dispCount = 60;
		disp_x = coin_x;
		disp_y = coin_y;
		//coin_x = rand() % (Screen::WIDTH - CHR_SIZE);
		//coin_y = rand() % (Screen::HEIGHT - CHR_SIZE);
		coin_x = rand1920(mt);
		coin_y = rand1080(rk);
		dontdes->point += 1;
		ksk += 0.5;
	}
	dispCount -= 1;
	float ex = en_x - ad; //X座標の差
	float ey = en_y - ws; //Y座標の差
	float e = sqrt(ex * ex + ey * ey); //距離を求める
	if (e < 52) {     //敵との当たり判定
		dispen = 60;
		den_x = en_x;
		den_y = en_y;
		en_x = rand() % (Screen::WIDTH - CHR_SIZE);
		en_y = rand() % (Screen::HEIGHT - CHR_SIZE);
		if (dontdes->point >= 5) {
			dontdes->point -= 5;
		}
		else if (dontdes->point <= 4) {
			dontdes->point = 0;
		}
		ksk = 0;
	}

	dispen -= 1;
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}

void PlayScene::Draw()
{
	dontDes* dontdes = FindGameObject<dontDes>();
	if (Screen::DEVELOPER_MODE == TRUE) {
		DrawString(0, 0, "TITLE SCENE", GetColor(25, 5, 215), 0);
		DrawString(200, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
		if (CheckHitKey(KEY_INPUT_I)) {
			DrawFormatString(0, 100, GetColor(255, 255, 255), "x=%4f y=%4f", ad, ws);
			DrawFormatString(0, 120, GetColor(255, 255, 255), "count=%d", count_k);
		}
	}

	DrawRectGraph(ad, ws, CHR_SIZE * pat, CHR_SIZE * pat_y, CHR_SIZE, CHR_SIZE, image_player, 1);
	DrawRectGraph(coin_x, coin_y, CHR_SIZE * 1, CHR_SIZE * 0, CHR_SIZE, CHR_SIZE, image_coin, 1);
	DrawRectGraph(en_x, en_y, PARTS_SIZE * 5, PARTS_SIZE * 0, PARTS_SIZE, PARTS_SIZE, image_en, 1);

	DrawExtendFormatString(1100, 0, 2, 2, GetColor(50, 250, 50), "POINT %4d", dontdes->point);
	if (dispCount > 0) {
		DrawFormatString(disp_x, disp_y, GetColor(255, 255, 55), "コインゲット！");
	}
	if (dispen > 0) {
		DrawFormatString(den_x, den_y, GetColor(255, 0, 0), "痛っ！");
	}
	DrawExtendFormatString(900, 0, 2, 2, GetColor(50, 250, 50), "TIME: %4d", ime / 60);
}

void PlayScene::GoUp(float spd)
{
	ws -= spd;
	if (ws < 0) {
		ws = 0;
	}
	pat_st = WALK;
	pat_y = UP;
	shift_k = STOP;
}

void PlayScene::GoLight(float spd)
{
	ad -= spd;
	if (ad < 0) {
		ad = 0;
	}
	pat_st = WALK;
	pat_y = LEFT;
	shift_k = STOP;
}

void PlayScene::GoDown(float spd)
{
	ws += spd;
	if (ws > Screen::HEIGHT - CHR_SIZE) {
		ws = Screen::HEIGHT - CHR_SIZE;
	}
	pat_st = WALK;
	pat_y = DOWN;
	shift_k = STOP;
}

void PlayScene::GoRight(float spd)
{
	ad += spd;
	if (ad > Screen::WIDTH - CHR_SIZE) {
		ad = Screen::WIDTH - CHR_SIZE;
	}
	pat_st = WALK;
	pat_y = RIGHT;
	shift_k = STOP;
}
