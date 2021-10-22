
# include "Rule.hpp"

Rule::Rule(const InitData& init)
	: IScene(init)
{

}

void Rule::update()
{
	m_startTransition.update(m_returnButton.mouseOver());

	if (m_returnButton.leftClicked())
	{
		changeScene(State::Title);
	}
	
}

void Rule::draw() const
{
	const String titleText = U"ブロックくずし";
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Rule")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Rule")(titleText).drawAt(center);

	m_returnButton.draw(ColorF(1.0, m_startTransition.value())).drawFrame(2);

	FontAsset(U"Menu")(U"タイトルに戻る").drawAt(m_returnButton.center(), ColorF(0.25));


	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));

	const Texture Rulephoto(Resource(U"Rulephoto2.jpg"));
	Rulephoto.resized(750).drawAt(center.movedBy(0,100));
	Profiler::EnableAssetCreationWarning(false);
}
