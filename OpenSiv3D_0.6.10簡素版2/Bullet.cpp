#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(Vec2 _pos)
	:GameChara(_pos)
{
	speed_ = BULLET_MOVE_SPEED;
	tex_ = TextureAsset(U"BULLET");
	moveDir_ = { 0, -1 };
	isAlive_ = true;
	SetCharaRect(Vec2{ BULLET_RECT_SIZE, BULLET_RECT_SIZE});
	double* p = new double[512];
}

void Bullet::Update()
{
	if (isAlive_) {
		pos_ = pos_ + moveDir_ * speed_ * Scene::DeltaTime();
		SetCharaRect({ BULLET_CHR_SIZE, BULLET_CHR_SIZE });
		if (pos_.y < 100)
			isAlive_ = false;
	}
}

void Bullet::Draw()
{
	Line{ 0,100, Scene::Width(),100 }.draw(2, Palette::Red);
	if (isAlive_) {
		tex_.resized(BULLET_CHR_SIZE).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
	
}
