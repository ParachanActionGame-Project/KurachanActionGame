# include "Start.hpp"

Start::Start(const InitData& init)
	: IScene(init)
{

}

void Start::update()
{
	m_startTransition.update(m_startButton.mouseOver());
	m_exitTransition.update(m_exitButton.mouseOver());

	if (m_startButton.mouseOver() || m_exitButton.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (m_startButton.leftClicked())
	{
		changeScene(State::Title);//状態を変更　
	}

	if (m_exitButton.leftClicked())
	{
		System::Exit();
	}
}

void Start::draw() const
{
	const String titleText = U"ParachanActionGame"; //＜ーブロックくずし
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Start")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Start")(titleText).drawAt(center);

	m_startButton.draw(ColorF(1.0, m_startTransition.value())).drawFrame(2);
	m_exitButton.draw(ColorF(1.0, m_exitTransition.value())).drawFrame(2);

	FontAsset(U"Menu")(U"ゲームスタート！").drawAt(m_startButton.center(), ColorF(0.25));
	FontAsset(U"Menu")(U"おわる").drawAt(m_exitButton.center(), ColorF(0.25));
	//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー
	FontAsset(U"Menu")(U"ルール説明").drawAt(m_ruleButton.center(), ColorF(0.25));
	FontAsset(U"Menu")(U"クレジット").drawAt(m_creditButton.center(), ColorF(0.25));
	////////////m_startButtonを流用したら重なった-->ruleとcreditを追加した

	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));

	const int32 highScore = getData().highScore;
	FontAsset(U"Score")(U"High score: {}"_fmt(highScore)).drawAt(Vec2(620, 550));
}