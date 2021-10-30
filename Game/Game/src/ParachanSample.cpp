#include "ParachanSample.hpp"



ParachanSample::ParachanSample(const Vec2 position, double radius, const Vec2 velocity, Texture texture_16,
	Texture texture_8, Texture texture_4, Texture texture_2, Texture texture_1) : countTime(true) {
	
	this->position = position;
	
	this->radius = radius;
	
	this->velocity = velocity;
	
	this->texture_16 = texture_16;
	
	this->texture_8 = texture_8;
	
	this->texture_4 = texture_4;
	
	this->texture_2 = texture_2;
	
	this->texture_1 = texture_1;
}


ParachanSample::ParachanSample(const Vec2 position, double radius,Texture texture_16,
	Texture texture_8, Texture texture_4, Texture texture_2, Texture texture_1)
	: ParachanSample(position, radius, Vec2(0.0, 0.0),texture_16,
		texture_8, texture_4, texture_2, texture_1)
{
}

	
void ParachanSample::update() {
	this->position += velocity * Scene::DeltaTime();
	//クラちゃんが壁に当たって反射する際の処理
	if (getPosition().x <= 0 + texture.width() * checkSizeW())
	{
		this->position.x = texture.width() * checkSizeW();
		this->velocity = Vec2(-velocity.x, velocity.y);
	}
	
	if (getPosition().x >= Scene::Width() - texture.width() * checkSizeW())
	{
		this->position.x = Scene::Width() - texture.width() * checkSizeW();
		this->velocity = Vec2(-velocity.x, velocity.y);
	}
	
	if (getPosition().y <= 0 + texture.height() * checkSizeH())
	{
		this->position.y = texture.height() * checkSizeH();
		this->velocity = Vec2(velocity.x, -velocity.y);
	}
	
	if (getPosition().y >= Scene::Height() - texture.height() * checkSizeH())
	{
		this->position.y = Scene::Height() - texture.height() * checkSizeH();
		this->velocity = Vec2(velocity.x, -velocity.y);
	}
	//クラちゃんが大きくなる際の処理
	if (countTime.sF() > 5)
	{
		if (getRadius() < 20)
		{
			setRadius(20);
			countTime.restart();
		}
		else if (getRadius() < 40)
		{
			setRadius(40);
			countTime.restart();
		}
		else if (getRadius() < 80)
		{
			setRadius(80);
			countTime.restart();
		}
		else if (getRadius() < 160)
		{
			setRadius(160);
		}
	}
}

//大きさ事のパラちゃんの画像の描画
void ParachanSample::draw() {
	if (getRadius() >= 160)
		texture_16.scaled(radius / 800).drawAt(position);
	else if (getRadius() >= 80)
		texture_8.scaled(radius / 800).drawAt(position);
	else if (getRadius() >= 40)
		texture_4.scaled(radius / 800).drawAt(position);
	else if (getRadius() >= 20)
		texture_2.scaled(radius / 800).drawAt(position);
	else
		texture_1.scaled(radius / 300).drawAt(position);
}
//クラちゃんの現在位置を呼び出す関数
Vec2 ParachanSample::getPosition() const {
	return this->position;
}
//クラちゃんの大きさを呼び出す関数
double ParachanSample::getRadius() {
	return radius;
}
//クラちゃんの速度を呼び出す関数
Vec2 ParachanSample::getVelocity() const {
	return velocity;
}
//クラちゃんの大きさを設定する関数
void ParachanSample::setRadius(double x) 
{
	radius = x;
	return;
}
//画像の大きさごとの横の当たり判定の比を呼び出す関数
double ParachanSample::checkSizeW()
{
	double a;
	if (getRadius() >= 160)
		a = 4;
	else if (getRadius() >= 80)
		a = 6.5;
	else if (getRadius() >= 40)
		a = 3;
	else if (getRadius() >= 20)
		a = 0.75;
	else
		a = 0.5;
	return a;
}
//画像の大きさごとの縦の当たり判定の比を呼び出す関数
double ParachanSample::checkSizeH()
{
	double a;
	if (getRadius() >= 160)
		a = 8;
	else if (getRadius() >= 80)
		a = 3;
	else if (getRadius() >= 40)
		a = 1.5;
	else if (getRadius() >= 20)
		a = 1;
	else
		a = 0.75;
	return a;
}
