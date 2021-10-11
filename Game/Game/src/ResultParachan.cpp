#include "ResultParachan.hpp"

using namespace result;

ResultParachan::ResultParachan(const Vec2 position, EResultKurachan type, const Vec2 velocity, String imagePath) :
	texture(imagePath)
{
	this->position = position;
	this->type = type;
	this->velocity = velocity;
	initScale();
}

ResultParachan::ResultParachan(const Vec2 position, EResultKurachan type, const Vec2 velocity)
	: ResultParachan(position, type, velocity, getTexturePath(type))
{
}

ResultParachan::ResultParachan(const Vec2 position, EResultKurachan type)
	: ResultParachan(position, type, Vec2(0.0, 0.0)) {
}

void ResultParachan::update() {
	this->position += velocity * Scene::DeltaTime();
	if (getPosition().x <= 0 || getPosition().x >= Scene::Width())
	{
		this->velocity = Vec2(-velocity.x, velocity.y);
	}
	if (getPosition().y <= 0 || getPosition().y >= Scene::Height())
	{
		this->velocity = Vec2(velocity.x, -velocity.y);
	}
}

void ResultParachan::initScale() {
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
		break;
	}
	this->scale /= 40.0;
}

String ResultParachan::getTexturePath(EResultKurachan type) {
	switch (type)
	{
	case VERY_BIG:
		return U"Characters/Kurachan_8.png";
		break;
	case BIG:
		return U"Characters/Kurachan_4.png";
		break;
	case MIDDLE:
		return U"Characters/Kurachan.png";
		break;
	case SMALL:
		return U"Characters/Kurachan_2.png";
		break;
	case VERY_SMALL:
		return U"Characters/Kurachan_1.png";
		break;
	default:
		break;
	}
}

void ResultParachan::draw() const {
	texture.scaled(scale).drawAt(position);
}

Vec2 ResultParachan::getPosition() const {
	return this->position;
}

double ResultParachan::getScale() {
	return scale;
}

Vec2 ResultParachan::getVelocity() const {
	return velocity;
}