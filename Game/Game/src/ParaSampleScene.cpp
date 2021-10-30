
# include "ParaSampleScene.hpp"
#include <algorithm>
# include <Siv3D.hpp>
#include <vector>

ParaSampleScene::ParaSampleScene(const InitData& init)
	: IScene(init),SE(Resource(U"sound/enemy.mp3")),BGM(Resource(U"sound/BGM.mp3"), Arg::loop = true),
	Timer(true), BackGround(Resource(U"background/BackGround.jpg"))
{
	//ウィンドウサイズの設定
	Window::Resize(Size(1280, 720));
	//画像ファイルを配列textureに挿入
	Texture a(Resource(U"Characters/Kurachan_crop.png"));
	Texture b(Resource(U"Characters/Kurachan_8_crop.png"));
	Texture c(Resource(U"Characters/Kurachan_4_crop.png"));
	Texture d(Resource(U"Characters/Kurachan_2_crop.png"));
	Texture e(Resource(U"Characters/Kurachan_1_crop.png"));
	textures.push_back(a);
	textures.push_back(b);
	textures.push_back(c);
	textures.push_back(d);
	textures.push_back(e);
	//BGMの音量設定
	BGM.setVolume(0.2);
	//BGMの再生
	BGM.play();
	//最初に画面に表示されるクラちゃんの定義
	parachans.push_back(ParachanSample(Scene::Center(), 160.0, a, b, c, d, e));
}

void ParaSampleScene::update()
{	
	//マウスがクリックされているかとクラちゃんにカーソルを合わせているかの判定
	checkMouseClick();
	checkMouseOver();
	for (int i = 0; i < parachans.size(); i++) {
		parachans[i].update();
	}
	//制限時間が過ぎた時にルールシーンに遷移する,BGMを停止する
	if (Timer.sF() >= 60)
	{
		BGM.stop();
		changeScene(State::Result);
	}
}
//マウスがクラちゃんの画像の上にあるかを判定する
void ParaSampleScene::checkMouseOver()
{
	Vec2 mousePos = Cursor::PosF();
	for(int i = 0; i < parachans.size(); i++)
	{
		if ((parachans[i].getPosition() - mousePos).length() < parachans[i].getRadius())
		{
			if(parachans[i].getRadius() > 10)
				Cursor::RequestStyle(CursorStyle::Hand);
		}
	}
}
//マウスがクリックされた際の処理
void ParaSampleScene::checkMouseClick() {
	if (MouseL.down()) {
		Vec2 mousePos = Cursor::PosF();
		for (int i = 0; i < parachans.size(); i++) {
			//マウスの位置を代入
			Vec2 mousePos = Cursor::PosF();
			if ((parachans[i].getPosition() - mousePos).length() < parachans[i].getRadius()&&parachans[i].getRadius()>10) {
				//point
				countClick += 1;
				//スコアの配点
				if (parachans[i].getRadius() > 80)
					countScore += 10;
				else if (parachans[i].getRadius() > 40)
					countScore += 20;
				else if (parachans[i].getRadius() > 20)
					countScore += 40;
				else
					countScore += 80;
				//クリックした際の効果音
				SE.play();
				//クリックされてからtimerをスタートする
				if (countClick==1)
				{
					Timer.restart();
				}
				this->getData().highScore += 10; // 自身のParaSampleSceneインスタンスの基底クラスであるSceneManagerのgetData関数を呼んでいる
				//クリックされ分裂した後のクラちゃんの初速と飛んでいく角度を決める
				double r = parachans[i].getRadius() / 2.0;
				if(r<20)
					double r = 15;
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
				//画面上に表示される最大数の設定
				parachans.erase(parachans.begin() + i);
				if (countClick > 32)
				{
					parachans.erase(parachans.begin()+Random(30));
					countClick = 32;
				}
				//タイムアップしたときにクラちゃんをすべて削除する
				if (Timer.sF() > 60)
				{
					if(countClick>=32)
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
	//大量の画像を呼び出すことができるようにする
	Profiler::EnableAssetCreationWarning(false);
	//背景画像の
	BackGround.scaled(Scene::Width() / (double)BackGround.width()).draw(0, 0);
	//timerを表示する際の形式の変更
	int timeLeft = 60 - Timer.sF();
	double leave = 60 - Timer.sF();
	//クラちゃんの描画
	for (ParachanSample parachan : parachans) {
		parachan.draw();
		//時間切れになった際の処理
		if (leave < 0.1)
		{
			FontAsset(U"ParaSampleScene")(timeLeft).drawAt(Scene::Center().x, Scene::Center().y - 1000);
			getData().currentScore=countScore;
		}
		//スコアや時間の表示
		else
		{
			FontAsset(U"ParaSampleScene")(countScore).drawAt(Scene::Width() - 100, Scene::Height() - 80);
			if (countClick >= 1)
			{
				FontAsset(U"ParaSampleScene")(timeLeft).drawAt(Scene::Center().x, Scene::Center().y + 300);
			}
			else
				FontAsset(U"ParaSampleScene")(60).drawAt(Scene::Center().x, Scene::Center().y + 300);
		}
	}
}
