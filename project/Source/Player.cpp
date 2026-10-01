#include "Player.h"
#include "Screen.h"

Player::Player()
{
	image = LoadGraph("data/chara.png");
	float pos_x = 0;
	float pos_y = 0;
	int pat_stn = 0;
	int pat_yz = 0;
	int DOWNz = 0;
	int UPz = 2;
	int RIGHTz = 3;
	int LEFTz = 1;
	int STOPz = 0;
	int WALKz = 4;
	int CHR_SIZE = 64;
	float ksk_z = 0;
	int shift_zk = 2;
	float sped = 2.0 + shift_zk + ksk_z;
	int count = 0;
	int patz = 0;

}

Player::~Player()
{
}


void Player::Update()
{
	pat_stn = STOPz;

	if (CheckHitKey(KEY_INPUT_LSHIFT)) {
		shift_zk += 1;
	}

	float spd = 2.0 + shift_zk + ksk_z;

	if (CheckHitKey(KEY_INPUT_W)) {
		pos_y -= spd;
		if (pos_y < 0) {
			pos_y = 0;
		}
		pat_stn = WALKz;
		pat_yz = UPz;
		shift_zk = STOPz;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		pos_x -= spd;
		if (pos_x < 0) {
			pos_x = 0;
		}
		pat_stn = WALKz;
		pat_yz = LEFTz;
		shift_zk = STOPz;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		pos_y += spd;
		if (pos_y > Screen::HEIGHT - CHR_SIZE) {
			pos_y = Screen::HEIGHT - CHR_SIZE;
		}
		pat_stn = WALKz;
		pat_yz = DOWNz;
		shift_zk = STOPz;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		pos_x += spd;
		if (pos_x > Screen::WIDTH - CHR_SIZE) {
			pos_x = Screen::WIDTH - CHR_SIZE;
		}
		pat_stn = WALKz;
		pat_yz = RIGHTz;
		shift_zk = STOPz;
	}
	count += 1;
	if (count >= 10) {
		count = 0;
		patz = (patz + 1) % 4 + pat_stn;
	}
}


void Player::Draw()
{
	if (Screen::DEVELOPER_MODE == TRUE) {
		DrawFormatString(0, 100, GetColor(255, 255, 255), "speed %4f", sped);
	}
	DrawRectGraph(pos_x, pos_y, CHR_SIZE* patz, CHR_SIZE* pat_yz, CHR_SIZE, CHR_SIZE, image, 1);
}
