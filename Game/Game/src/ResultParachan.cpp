#include "ResultParachan.hpp"

ResultParachan::ResultParachan(const Vec2 position, double size, const Vec2 velocity, String imagePath) :
	texture(imagePath)
{
	this->position = position;
	this->size = size;
	this->velocity = velocity;
}

ResultParachan::ResultParachan(const Vec2 position, double size, const Vec2 velocity)
	: ResultParachan(position, size, velocity,
		size > 41.0 ?
		(size > 51.0 ? U"Characters/Kurachan.png" : U"Characters/Kurachan_2.png")
		: U"Characters/Kurachan_1.png"
	) {
}

ResultParachan::ResultParachan(const Vec2 position, double size)
	: ResultParachan(position, size, Vec2(0.0, 0.0)) {
}

void ResultParachan::update() {
	this->position += velocity * Scene::DeltaTime();
	if (getPosition().x <= 0 + size || getPosition().x >= Scene::Width() - size)
	{
		this->velocity = Vec2(-velocity.x, velocity.y);
	}
	if (getPosition().y <= 0 + size || getPosition().y >= Scene::Height() - size)
	{
		this->velocity = Vec2(velocity.x, -velocity.y);
	}
}

void ResultParachan::draw() const {
	String file;
	const Vec2 pos = position + Vec2(-size * 2.3, -size * 2.3);
	texture.scaled(size / 800).draw(pos);
}

Vec2 ResultParachan::getPosition() const {
	return this->position;
}

double ResultParachan::getRadius() {
	return size;
}

Vec2 ResultParachan::getVelocity() const {
	return velocity;
}