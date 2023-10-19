#pragma once
#include "GameChara.h"


const int BULLET_CHR_SIZE{ 20 }; //画像サイズ
const double BULLET_RECT_SIZE{ 20 }; //当たり判定用のBBのサイズ
const double BULLET_MOVE_SPEED{ 100 }; //弾丸の動作スピード

//1個の弾丸を表現するクラス
class Bullet :
    public GameChara
{
public:
	Bullet(Vec2 _pos);
	void Update() override;
	void Draw() override;
};

