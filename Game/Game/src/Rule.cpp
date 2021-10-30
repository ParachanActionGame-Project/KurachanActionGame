
# include "Rule.hpp"

Rule::Rule(const InitData& init)
	: IScene(init), rulePhoto(Resource(U"HowToPlay.png")), Background(Resource(U"background/RuleBackGround.jpg"))
{

}

void Rule::update()
{
	m_startTransition.update(m_returnButton.mouseOver());

	if (m_returnButton.leftClicked())
	{
		changeScene(State::Start);
	}
	
}

void Rule::draw() const
{

	const String titleText = U"ブロックくずし";
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Rule")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Rule")(titleText).drawAt(center);

	Background.resized(1600).drawAt(center.movedBy(0, 200));
	Profiler::EnableAssetCreationWarning(false);

	rulePhoto.resized(1000).drawAt(center.movedBy(0, 200));
	Profiler::EnableAssetCreationWarning(false);

	m_returnButton.draw(ColorF(0, m_startTransition.value())).drawFrame(2);

	FontAsset(U"Menu")(U"タイトルに戻る").drawAt(m_returnButton.center(), ColorF(1.0,1.0,1.0,1.0));

	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));


}
