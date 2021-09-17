﻿
# include "CreditScene.hpp"

CreditScene::CreditScene(const InitData& init)
	: IScene(init)
{

}

void CreditScene::update()
{
	m_startTransition.update(m_titleButton.mouseOver());

	if (m_titleButton.mouseOver())
	{

		Cursor::RequestStyle(CursorStyle::Hand);
		
	}

	if (m_titleButton.leftClicked())
	{
		//Scene::SetBackground(ColorF(0.2, 0.8, 0.4));
		changeScene(State::Title);
	}
}

void CreditScene::draw() const
{
	//Scene::SetBackground(ColorF(1.0, 1.0, 1.0));
	Profiler::EnableAssetCreationWarning(false);
	//const String CreditSceneText = U"クレジット";
	//const String CreditText=U"制作(敬称略)　Jumpaku, さんたろ, \nロロ, しょくそん, アステル\n\n音源\n魔王魂\n\nイラスト(敬称略)\nJumpaku";
	//白四角
	Rect(0, 0, Scene::Width(), Scene::Height()).draw(ColorF(1, 1, 1));
	const Vec2 center(Scene::Center().x, 120);
	//画像
	const Texture CreditPicture(U"credit2.png");
	CreditPicture.scaled(0.5).draw(Scene::Center().moveBy(-500, -275));
	//FontAsset(U"CreditScene")(CreditSceneText).drawAt(center.movedBy(2, -47), ColorF(0.0, 0.5));
	//FontAsset(U"CreditScene")(CreditSceneText).drawAt(center.movedBy(0,-50));
	//FontAsset(U"CreditScene")(CreditText).drawAt(center.movedBy(0,200));

	m_titleButton.draw(ColorF(1.0, m_startTransition.value())).drawFrame(2);
	FontAsset(U"Menu")(U"タイトルに戻る").drawAt(m_titleButton.center(), ColorF(0.25));

	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));

	//画像を出力する方
	//const int32 highScore = getData().highScore;
	//FontAsset(U"Score")(U"High score: {}"_fmt(highScore)).drawAt(Vec2(620, 550));
	


}
