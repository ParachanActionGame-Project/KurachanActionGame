#include "ResultKurachan.hpp"

using namespace result;

ResultKurachan::ResultKurachan(const Vec2 position, EResultKurachan type, const Vec2 velocity, String imagePath) :
	texture(imagePath)
{
	this->position = position;
	this->type = type;
	this->velocity = velocity;
	initScale();
}

ResultKurachan::ResultKurachan(const Vec2 position, EResultKurachan type, const Vec2 velocity)
	: ResultKurachan(position, type, velocity, getTexturePath(type))
{
}

ResultKurachan::ResultKurachan(const Vec2 position, EResultKurachan type)
	: ResultKurachan(position, type, Vec2(0.0, 0.0)) {
}

void ResultKurachan::update() {
	this->position += velocity * Scene::DeltaTime();
	if (getPosition().x <= 0 + texture.width() / 2.0 * scale || getPosition().x >= Scene::Width() - texture.width() / 2.0 * scale)
	{
		this->velocity = Vec2(-velocity.x, velocity.y);
	}
	if (getPosition().y <= 0 + texture.height() / 2.0 * scale || getPosition().y >= Scene::Height() - texture.height() / 2.0 * scale)
	{
		this->velocity = Vec2(velocity.x, -velocity.y);
	}
}

void ResultKurachan::initScale() {
	switch (type)
	{
	case VERY_BIG:
		this->scale = 3.0;
		break;
	case BIG:
		this->scale = 2.5;
		break;
	case MIDDLE:
		this->scale = 2.0;
		break;
	case SMALL:
		this->scale = 1.5;
		break;
	case VERY_SMALL:
		this->scale = 1.0;
		break;
	default:
		this->scale = 1.0;
		break;
	}
	this->scale /= 40.0;
}

String ResultKurachan::getTexturePath(EResultKurachan type) {
	switch (type)
	{
	case VERY_BIG:
		return U"Characters/Kurachan_8.png";
	case BIG:
		return U"Characters/Kurachan_4.png";
	case MIDDLE:
		return U"Characters/Kurachan.png";
	case SMALL:
		return U"Characters/Kurachan_2.png";
	case VERY_SMALL:
		return U"Characters/Kurachan_1.png";
	default:
		return U"";
		break;
	}
}

void ResultKurachan::draw() const {
	texture.scaled(scale).drawAt(position);
}

Vec2 ResultKurachan::getPosition() const {
	return this->position;
}

double ResultKurachan::getScale() {
	return scale;
}

Vec2 ResultKurachan::getVelocity() const {
	return velocity;
}