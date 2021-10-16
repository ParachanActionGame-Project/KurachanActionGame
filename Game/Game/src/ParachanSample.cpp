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
	if (getPosition().x <= 0 + radius || getPosition().x >= Scene::Width() -radius)
	{
		this->velocity = Vec2(-velocity.x, velocity.y);
	}
	if (getPosition().y <= 0 + radius || getPosition().y >= Scene::Height() -radius)
	{
		this->velocity = Vec2(velocity.x, -velocity.y);
	}
	if (countTime.sF() > 3)
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
		}
	}
}

//parachanの画像に関係
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

Vec2 ParachanSample::getPosition() const {
	return this->position;
}

double ParachanSample::getRadius() {
	return radius;
}

Vec2 ParachanSample::getVelocity() const {
	return velocity;
}

void ParachanSample::setRadius(double x) 
{
	radius = x;
	return;
}
