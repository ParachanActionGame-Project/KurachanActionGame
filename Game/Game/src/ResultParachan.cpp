#include "ResultParachan.hpp"

ResultParachan::ResultParachan(const Vec2 position, double radius, const Vec2 velocity) {
	this->position = position;
	this->radius = radius;
	this->velocity = velocity;
}

ResultParachan::ResultParachan(const Vec2 position, double size)
	: ResultParachan(position, size, Vec2(0.0, 0.0)) {
}

void ResultParachan::update() {
	this->position += velocity * Scene::DeltaTime();
	if (getPosition().x <= 0 + radius || getPosition().x >= Scene::Width() - radius)
	{
		this->velocity = Vec2(-velocity.x, velocity.y);
	}
	if (getPosition().y <= 0 + radius || getPosition().y >= Scene::Height() - radius)
	{
		this->velocity = Vec2(velocity.x, -velocity.y);
	}
}

void ResultParachan::draw() const {
	const Texture SecondPicture(U"cat.png");
	const Vec2 pos = position + Vec2(-radius * 2.3, -radius * 2.3);
	SecondPicture.scaled(radius / 20).draw(pos);
}

Vec2 ResultParachan::getPosition() const {
	return this->position;
}

double ResultParachan::getRadius() {
	return radius;
}

Vec2 ResultParachan::getVelocity() const {
	return velocity;
}