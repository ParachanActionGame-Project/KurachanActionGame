
# include "ParaSampleScene.hpp"
#include <algorithm>

ParaSampleScene::ParaSampleScene(const InitData& init)
	: IScene(init)
{
	parachans.push_back(ParachanSample(Scene::Center(), 40.0));
}

void ParaSampleScene::update()
{	
	checkMouseClick();
	for (int i = 0; i < parachans.size(); i++) {
		parachans[i].update();
	}
}

void ParaSampleScene::checkMouseClick() {
	if (MouseL.down()) {
		Vec2 mousePos = Cursor::PosF();
		for (int i = 0; i < parachans.size(); i++) {
			if ((parachans[i].getPosition() - mousePos).length() < parachans[i].getRadius()) {
				this->getData().highScore += 10; // 自身のParaSampleSceneインスタンスの基底クラスであるSceneManagerのgetData関数を呼んでいる
				std::cout << "現在のスコア: " << this->getData().highScore << std::endl;
				double r = parachans[i].getRadius() / 2.0;
				parachans.push_back(ParachanSample(
					parachans[i].getPosition() - Vec2(r, 0.0), r, Vec2(-10.0, 0.0)));
				parachans.push_back(ParachanSample(
					parachans[i].getPosition() + Vec2(r, 0.0), r, Vec2(10.0, 0.0)));
				parachans.erase(parachans.begin() + i);
				return;
			}
		}
	}
}

void ParaSampleScene::draw() const
{
	const String titleText = U"サンプルゲーム";
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"ParaSampleScene")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"ParaSampleScene")(titleText).drawAt(center);

	for (ParachanSample parachan : parachans) {
		parachan.draw();
	}
}
