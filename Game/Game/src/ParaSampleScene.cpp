
# include "ParaSampleScene.hpp"
#include <algorithm>
# include <Siv3D.hpp>
#include <vector>
//#include <stdlib.h>
//#include <time.h>
//#include <cmath>  

ParaSampleScene::ParaSampleScene(const InitData& init)
	: IScene(init)
{
	Window::Resize(Size(1280, 720));
	//下の第二引数現在は80がradius
	parachans.push_back(ParachanSample(Scene::Center(), 80.0));
}

void ParaSampleScene::update()
{	
	checkMouseClick();
	for (int i = 0; i < parachans.size(); i++) {
		parachans[i].update();
	}
	//checkReflection();
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
				//rorokaihenmae
				//parachans.push_back(ParachanSample(
					//parachans[i].getPosition() - Vec2(r, 0.0), r, Vec2(-10.0, 0.0)));
				//parachans.push_back(ParachanSample(
					//parachans[i].getPosition() + Vec2(r, 0.0), r, Vec2(10.0, 0.0)));
				//parachans.erase(parachans.begin() + i);
				//return;
				// rorotuiki
				//srand(time(NULL)*rand());
				//double direction_x = std::abs(rand() % 20);
				//このコードでは初速が四角をとるが充分遅いため円にする必要はないと考える
				double direction_x = Random(200);
				double direction_y;
				if (direction_x <= 100)
					direction_y = 100 - direction_x;
				else
					direction_y = 100 - direction_x;
				parachans.push_back(ParachanSample(
					parachans[i].getPosition() - Vec2(r, 0.0), r, Vec2(-direction_x, -direction_y)));
				parachans.push_back(ParachanSample(
					parachans[i].getPosition() + Vec2(r, 0.0), r, Vec2(direction_x, direction_y)));
				parachans.erase(parachans.begin() + i);
				if (countClick>16)
					parachans.erase(parachans.begin()+Random(15));
				return;
			}
		}
	}
}
//反射
/*void ParaSampleScene::checkReflection()
{
	for (int i = 0; i < parachans.size(); i++)
	{
		
		//大きさの取得
		double r = parachans[i].getRadius();
		//反射後の方向
	
		if (parachans[i].getPosition().y == 0|| parachans[i].getPosition().y == 780)
		{
			//反射するにはぶつかった壁がｙの壁かxの壁かによってdirectionの該当部(xの時はy,yの時はx)を反転すればよい
			parachans.push_back(ParachanSample(
				parachans[i].getPosition() - Vec2(r, 0.0), r, Vec2(direction_x[i], -direction_y[i])));
			parachans.erase(parachans.begin() + i);
			return;
		}

		if (parachans[i].getPosition().x == 0|| parachans[i].getPosition().y == 1280)
		{
			//反射するにはぶつかった壁がｙの壁かxの壁かによってdirectionの該当部(xの時はy,yの時はx)を反転すればよい
			parachans.push_back(ParachanSample(
				parachans[i].getPosition() - Vec2(r, 0.0), r, Vec2(-direction_x[i], direction_y[i])));
			parachans.erase(parachans.begin() + i);
			return;
		}
	}
}*/

void ParaSampleScene::draw() const
{
	Profiler::EnableAssetCreationWarning(false);
	const String titleText = U"サンプルゲーム";
	const Vec2 center(Scene::Center().x, 120);
	const Texture CreditPicture(U"dog.png");
	FontAsset(U"ParaSampleScene")(titleText).drawAt(center.movedBy(2, 3), ColorF(0.0, 0.5));
	FontAsset(U"ParaSampleScene")(titleText).drawAt(center);
	//パラちゃんの描画
	for (ParachanSample parachan : parachans) {
		parachan.draw();
	}
}
