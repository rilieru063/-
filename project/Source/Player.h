#pragma once
#include "../Library/GameObject.h"

//classとはプレイヤーのことをやる処理を書くところ
class Player : public GameObject
{
public:
	Player(); //コンストラクター（最初に1回呼ばれる）
	~Player(); //デストラクター（最後に１回呼ばれる）
	void Update() override; //毎フレーム呼ばれる　計算
	void Draw() override; //毎フレーム呼ばれる　描画


	//:メンバー変数:プレイヤーを処理するのに必要な変数
	int image;
	int pat_stn;
	int pat_yz;
	int DOWNz;
	int UPz;
	int RIGHTz;
	int LEFTz;
	int STOPz;
	int WALKz;
	int CHR_SIZE;
	float ksk_z;
	int shift_zk;
	float sped;
	int count;
	int patz;
	float pos_x;
	float pos_y;
};