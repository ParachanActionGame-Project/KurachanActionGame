
# include "ParaSampleScene.hpp"
#include <algorithm>
# include <Siv3D.hpp>
#include <vector>

ParaSampleScene::ParaSampleScene(const InitData& init)
	: IScene(init),SE(U"sound/enemy.mp3"),BGM(U"sound/BGM.mp3", Arg::loop = true), Timer(true)
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
	BGM.play();
	
	parachans.push_back(ParachanSample(Scene::Center(), 160.0, a, b, c, d, e));
}

void ParaSampleScene::update()
{	
	checkMouseClick();
	checkMouseOver();
	for (int i = 0; i < parachans.size(); i++) {
		parachans[i].update();
	}
}

void ParaSampleScene::checkMouseOver()
{
	Vec2 mousePos = Cursor::PosF();
	for(int i = 0; i < parachans.size(); i++)
	{
		if ((parachans[i].getPosition() - mousePos).length() < parachans[i].getRadius())
			Cursor::RequestStyle(CursorStyle::Hand);
	}
}

void ParaSampleScene::checkMouseClick() {
	if (MouseL.down()) {
		Vec2 mousePos = Cursor::PosF();
		for (int i = 0; i < parachans.size(); i++) {
			//マウスの位置を代入
			Vec2 mousePos = Cursor::PosF();
			if ((parachans[i].getPosition() - mousePos).length() < parachans[i].getRadius()&&parachans[i].getRadius()>10) {
				//point
				countClick += 1;
				if (parachans[i].getRadius() > 80)
					countScore += 20;
				else if (parachans[i].getRadius() > 40)
					countScore += 20;
				else if (parachans[i].getRadius() > 20)
					countScore += 40;
				else
					countScore += 80;
				SE.play();
				if (parachans[i].getRadius() > 80)
				{
					Timer.restart();
				}
				this->getData().highScore += 10; // 自身のParaSampleSceneインスタンスの基底クラスであるSceneManagerのgetData関数を呼んでいる
				//std::cout << "score"+countScore << this->getData().highScore << std::endl;
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
				//std::cout << c << std::endl;
				parachans.erase(parachans.begin() + i);
				if (countClick > 32)
				{
					parachans.erase(parachans.begin()+Random(30));
					countClick = 32;
					
				}
				if (Timer.sF() > 60)
				{
					if(countClick==32)
						for (int i = 0; i < 33; i++)
						{
							parachans.erase(parachans.begin());
						}
				}
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
	double timeLeft = 60-Timer.sF();
	//パラちゃんの描画
	for (ParachanSample parachan : parachans) {
		parachan.draw();
		if (timeLeft < 0)
		{
			FontAsset(U"ParaSampleScene")(countScore).drawAt(Scene::Center().x, 200);
			FontAsset(U"ParaSampleScene")(timeLeft).drawAt(Scene::Center().x, Scene::Center().y - 1000);
		}
		else
		{
			FontAsset(U"ParaSampleScene")(countScore).drawAt(Scene::Width() - 100, Scene::Height() - 80);
			FontAsset(U"ParaSampleScene")(timeLeft).drawAt(Scene::Center().x, Scene::Center().y+300);
		}
	}
}
