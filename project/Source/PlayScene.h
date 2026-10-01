#pragma once
#include "../Library/SceneBase.h"

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

	void GoUp(float spd);
	void GoLight(float spd);
	void GoDown(float spd);
	void GoRight(float spd);
private:
	int image_player; //キャラ画像
	int image_coin; //アイテム画像
	int image_en; //敵画像
	int pat_st = 0; //キャラの待機モーション
	int pat = 0; //アニメーションのパターン
	float ws = 0; //アニメーションの左右の動き
	float ad = 0; //アニメーションの前後の動き
	int count_k = 0; //WASDを押したときのアニメーション
	int pat_y = 0; //キャラの向き
	int shift_k = 2; //shiftダッシュ
	const int CHR_SIZE = 64; //キャラのサイズ
	float coin_x = 600; //コインのx座標
	float coin_y = 50; //コインのy座標
	const int DOWN = 0;
	const int UP = 2;
	const int RIGHT = 3;
	const int LEFT = 1;
	const int STOP = 0;
	const int WALK = 4;
	const int PARTS_SIZE = 40; // parts.pngのサイズ
	int point = 0; //ポイント
	float en_x = 400; //敵のx座標
	float en_y = 200; //敵のy座標
	float ksk = 0;
	int dispCount = 0;//0より大きければCOINGETと表示する
	int disp_x;
	int disp_y;
	int dispen = 0;
	int den_x;
	int den_y;
	int ime = 100 * 60; //残り時間
};
