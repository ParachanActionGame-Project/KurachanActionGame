
# include "ResultScene.hpp"

ResultScene::ResultScene(const InitData& init)
	: IScene(init), backgroundTexture(Resource(U"background/GameBackGround.jpg"))
{
	//getData().currentScore = 20;
	updateHighScore();
}

void ResultScene::update()
{
	m_startTransition.update(m_startButton.mouseOver());
	m_goTitleTransition.update(m_goTitleButton.mouseOver());
	m_exitTransition.update(m_exitButton.mouseOver());
	m_tweetTransition.update(m_tweetButton.mouseOver());

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
		//changeScene(State::Title);
		changeScene(State::Start);
	}

	if (m_exitButton.leftClicked())
	{
		System::Exit();
	}

	if (m_tweetButton.leftClicked()) {
		Twitter::OpenTweetWindow(Format(getData().currentScore) + U"点獲得! #KurachanActionGame");
	}

	for (int i = 0; i < parachans.size(); i++) {
		parachans[i].update();
	}
}

void ResultScene::draw() const
{
	backgroundTexture.scaled(Scene::Width() / (double)backgroundTexture.width()).draw(0, 0);

	for (int i = 0; i < parachans.size(); i++) {
		//std::cout << parachans[i].getPosition() << " " << parachans[i].getVelocity() << std::endl;
		parachans[i].draw();
	}

	const String titleText = U"けっか";
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Title")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Title")(titleText).drawAt(center);
	FontAsset(U"Score")(U"今回のスコア: {}"_fmt(getData().currentScore)).drawAt(center + Vec2(0, 120));
	FontAsset(U"Score")(U"ハイスコア: {}"_fmt(highScore)).drawAt(center + Vec2(0, 160));

	m_startButton.draw(ColorF(1.0, m_startTransition.value())).draw(ColorF(1, 1, 1, 0.7));
	m_goTitleButton.draw(ColorF(1.0, m_goTitleTransition.value())).draw(ColorF(1, 1, 1, 0.7));
	m_exitButton.draw(ColorF(1.0, m_exitTransition.value())).draw(ColorF(1, 1, 1, 0.7));
	m_tweetButton.draw(ColorF(1.0, m_tweetTransition.value())).draw(ColorF(1, 1, 1, 0.7));

	FontAsset(U"Menu")(U"もういちど").drawAt(m_startButton.center(), ColorF(0.25));
	FontAsset(U"Menu")(U"タイトルへ").drawAt(m_goTitleButton.center(), ColorF(0.25));
	FontAsset(U"Menu")(U"おわる").drawAt(m_exitButton.center(), ColorF(0.25));
	FontAsset(U"Menu")(U"ツイート").drawAt(m_tweetButton.center(), ColorF(0.25));

	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));
}

void ResultScene::writeHighScore() 
{
	TextWriter writer(U"highscore.txt");

	if (!writer) {
		throw Error(U"failed to open 'highscore.txt'");
	}

	writer << getData().highScore;
}

void ResultScene::setHighScore(int highScore) 
{
	this->highScore = highScore;
}

int ResultScene::getHighScore() 
{
	return highScore;
}

void ResultScene::updateHighScore() 
{
	highScore = getData().highScore;
	if (getData().currentScore > highScore) {
		getData().highScore = getData().currentScore;
		writeHighScore();
	}
}