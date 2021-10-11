
# include "ParaSampleScene.hpp"
#include <algorithm>
# include <Siv3D.hpp>
#include <vector>

ParaSampleScene::ParaSampleScene(const InitData& init)
	: IScene(init)
{
	Window::Resize(Size(1280, 720));
	//下の第二引数現在は160がradius
	Texture a(U"Characters/Kurachan.png");
	Texture b(U"Characters/Kurachan_8.png");
	Texture c(U"Characters/Kurachan_4.png");
	Texture d(U"Characters/Kurachan_2.png");
	Texture e(U"Characters/Kurachan_1.png");

	textures.push_back(a);
	textures.push_back(b);
	textures.push_back(c);
	textures.push_back(d);
	textures.push_back(e);

	parachans.push_back(ParachanSample(Scene::Center(), 160.0, a, b, c, d, e));
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
		//マウスの位置を代入
		Vec2 mousePos = Cursor::PosF();
		for (int i = 0; i < parachans.size(); i++) {
			if ((parachans[i].getPosition() - mousePos).length() < parachans[i].getRadius()&&parachans[i].getRadius()>10) {
				countClick++;
				this->getData().highScore += 10; // 自身のParaSampleSceneインスタンスの基底クラスであるSceneManagerのgetData関数を呼んでいる
				std::cout << "現在のスコア: " << this->getData().highScore << std::endl;
					double r = parachans[i].getRadius() / 2.0;
				if(r<20)
					double r = 15;
				//このコードでは初速が四角をとるが充分遅いため円にする必要はないと考える
				double direction_x = Random(200);
				double direction_y;
				if (direction_x <= 100)
					direction_y = 100 - direction_x;
				else
					direction_y = 100 - direction_x;
				parachans.push_back(ParachanSample(
					parachans[i].getPosition() - Vec2(r, 0.0), r, Vec2(-direction_x, -direction_y),textures[0], textures[1], textures[2], textures[3], textures[4]));
				parachans.push_back(ParachanSample(
					parachans[i].getPosition() + Vec2(r, 0.0), r, Vec2(direction_x, direction_y), textures[0], textures[1], textures[2], textures[3], textures[4]));
				parachans.erase(parachans.begin() + i);
				if (countClick>16)
					parachans.erase(parachans.begin()+Random(15));
				return;
			}
		}
	}
}

void ParaSampleScene::draw() const
{
	Profiler::EnableAssetCreationWarning(false);
	const String titleText = U"サンプルゲーム";
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"ParaSampleScene")(titleText).drawAt(center.movedBy(2, 3), ColorF(0.0, 0.5));
	FontAsset(U"ParaSampleScene")(titleText).drawAt(center);
	//パラちゃんの描画
	for (ParachanSample parachan : parachans) {
		parachan.draw();
	}
}
