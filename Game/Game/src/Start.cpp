# include "Start.hpp"

Start::Start(const InitData& init)
	: IScene(init), TitleScene(Resource(U"StartScenef.png"))
{
	
}

void Start::update()
{///////////////////////////////////////////////////////////////////////
	m_startTransition.update(m_startButton.mouseOver());
	m_exitTransition.update(m_exitButton.mouseOver());
	m_ruleTransition.update(m_ruleButton.mouseOver());
	m_creditTransition.update(m_creditButton.mouseOver());
	
	if (m_startButton.mouseOver() || m_exitButton.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}
	
	if (m_ruleButton.mouseOver() || m_creditButton.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (m_startButton.leftClicked())
	{
		changeScene(State::Result); // リザルト
		//changeScene(State::ParaSample); // プロトタイプゲーム
		//changeScene(State::Game); // ブロック崩し
	}

	if (m_exitButton.leftClicked())
	{
		System::Exit();
	}
	if (m_ruleButton.leftClicked()) 
	{
		changeScene(State::Rule);/*ファイルの名前じゃなくて, Common.hpp
		の中にあるStateのとこの名前*/
	}
	if (m_creditButton.leftClicked()) 
	{
		changeScene(State::Credit);
	}
}
void Start::draw() const
{
	TitleScene.draw(0, 0);
	//TitleScene.scaled(0.5).drawAt(Scene::Center());
	const String titleText = U"ParachanActionGame"; //＜ーブロックくずし
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Start")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Start")(titleText).drawAt(center);

	m_startButton.draw(ColorF(0.0, m_startTransition.value())).drawFrame(2);
	m_exitButton.draw(ColorF(0.0, m_exitTransition.value())).drawFrame(2);
	m_ruleButton.draw(ColorF(0.0, m_ruleTransition.value())).drawFrame(2);
	m_creditButton.draw(ColorF(0.0, m_creditTransition.value())).drawFrame(2);
	/// <summary>
	/// </summary>
	FontAsset(U"Score")(U"ゲームスタート！").drawAt(m_startButton.center(), Color(255,255,255));
	FontAsset(U"Score")(U"おわる").drawAt(m_exitButton.center(), Color(255,255,255));
	FontAsset(U"Score")(U"ルール説明").drawAt(m_ruleButton.center(), Color(255, 255, 255));
	FontAsset(U"Score")(U"クレジット").drawAt(m_creditButton.center(), Color(255, 255, 255));
	
	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));
		//.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));

	const int32 highScore = getData().highScore;
	FontAsset(U"Score")(U"High score: {}"_fmt(highScore)).drawAt(Vec2(1000/*620*/, 650/*550*/),Color(255,255,255));
}