
# include "ResultScene.hpp"

ResultScene::ResultScene(const InitData& init)
	: IScene(init)
{
	
}

void ResultScene::update()
{
	m_startTransition.update(m_startButton.mouseOver());
	m_goTitleTransition.update(m_goTitleButton.mouseOver());
	m_exitTransition.update(m_exitButton.mouseOver());

	if (m_startButton.mouseOver() || m_goTitleButton.mouseOver() || m_exitButton.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (m_startButton.leftClicked())
	{
		//changeScene(State::Game);
		changeScene(State::ParaSample);
	}

	if (m_goTitleButton.leftClicked())
	{
		changeScene(State::Title);
	}

	if (m_exitButton.leftClicked())
	{
		System::Exit();
	}

	// ぱらちゃんの移動処理はupdateの実装に依存する
	parachan.update();
}

void ResultScene::draw() const
{
	const String titleText = U"けっか";
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Title")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Title")(titleText).drawAt(center);
	FontAsset(U"Score")(U"今回のスコア: {}"_fmt(getData().currentScore)).drawAt(center + Vec2(0, 120));
	FontAsset(U"Score")(U"ハイスコア: {}"_fmt(getData().highScore)).drawAt(center + Vec2(0, 160));

	m_startButton.draw(ColorF(1.0, m_startTransition.value())).drawFrame(2);
	m_goTitleButton.draw(ColorF(1.0, m_goTitleTransition.value())).drawFrame(2);
	m_exitButton.draw(ColorF(1.0, m_exitTransition.value())).drawFrame(2);

	FontAsset(U"Menu")(U"もういちど").drawAt(m_startButton.center(), ColorF(0.25));
	FontAsset(U"Menu")(U"タイトルへ").drawAt(m_goTitleButton.center(), ColorF(0.25));
	FontAsset(U"Menu")(U"おわる").drawAt(m_exitButton.center(), ColorF(0.25));

	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));

	// ぱらちゃんの描画処理はdrawの実装に依存する
	parachan.draw();
}
