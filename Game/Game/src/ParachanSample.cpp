#include "ParachanSample.hpp"



ParachanSample::ParachanSample(const Vec2 position, double radius, const Vec2 velocity) : countTime(true) {
	this->position = position;
	this->radius = radius;
	this->velocity = velocity;

}


ParachanSample::ParachanSample(const Vec2 position, double size)
	: ParachanSample(position, size, Vec2(0.0, 0.0))
{
}

	
void ParachanSample::update() {
	/*if (MouseL.down())
	{
		if ((getPosition() - Cursor::PosF()).length() < getRadius())
		{
			if (getRadius() < 20)
			{
				// ストップウォッチをリセットして再び 0 から計測
				time_a.restart();
			}
			else if (getRadius() < 40)
			{
				// ストップウォッチをリセットして再び 0 から計測
				time_b.restart();
			}
		}
	}*/
	//ストップウォッチで一定時間経過したら
	  //20より小さく10よりおおきかったら20に
	  //20より大きく40より小さかったら40に
	this->position += velocity * Scene::DeltaTime();
	if (getPosition().x <= 0+radius || getPosition().x >= Scene::Width() -radius)
	{
		this->velocity = Vec2(-velocity.x, velocity.y);
	}
	if (getPosition().y <= 0 + radius || getPosition().y >= Scene::Height() -radius)
	{
		this->velocity = Vec2(velocity.x, -velocity.y);
	}
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
		}
	}
}

//parachanの画像に関係
void ParachanSample::draw() {
	const Texture CreditPicture(U"dog.png");
	const Texture SecondPicture(U"cat.png");
	const Texture ThirdPicture(U"mouse.png");
	if(getRadius()>=40)
		CreditPicture.scaled(radius/20).draw(position.moveBy(-radius*2.3, -radius*2.3));
	else if (getRadius() >= 20)
		SecondPicture.scaled(radius / 20).draw(position.moveBy(-radius * 2.3, -radius * 2.3));
	else 
		ThirdPicture.scaled(radius / 20).draw(position.moveBy(-radius * 2.3, -radius * 2.3));
	//basecode
	//Circle(position, radius).draw(Palette::Red);
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