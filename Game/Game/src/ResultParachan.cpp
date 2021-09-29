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
}

void ResultParachan::draw() const {
	Circle(position, radius).draw(Palette::Red);
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