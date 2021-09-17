#include "ParachanSample.hpp"

ParachanSample::ParachanSample(const Vec2 position, double radius, const Vec2 velocity) {
	this->position = position;
	this->radius = radius;
	this->velocity = velocity;
}

ParachanSample::ParachanSample(const Vec2 position, double size)
	: ParachanSample(position, size, Vec2(0.0, 0.0)){
}

void ParachanSample::update() {
	this->position += velocity * Scene::DeltaTime();
}

void ParachanSample::draw() {
	Circle(position, radius).draw(Palette::Red);
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