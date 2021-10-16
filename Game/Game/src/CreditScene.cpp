//roro
# include "CreditScene.hpp"

CreditScene::CreditScene(const InitData& init)
	: IScene(init)
{

}

void CreditScene::update()
{
	Window::Resize(Size(1280, 640));
	m_startTransition.update(m_titleButton.mouseOver());

	if (m_titleButton.mouseOver())
	{

		Cursor::RequestStyle(CursorStyle::Hand);
		
	}

	if (m_titleButton.leftClicked())
	{
		//Scene::SetBackground(ColorF(0.2, 0.8, 0.4));
		changeScene(State::Start);
	}
}

void CreditScene::draw() const
{
	Profiler::EnableAssetCreationWarning(false);
	Rect(0, 0, Scene::Width(), Scene::Height()).draw(ColorF(1, 1, 1));
	const Vec2 center(Scene::Center().x, 120);
	//画像
	const Texture CreditPicture(U"credit2.png");
	CreditPicture.scaled(0.5).draw(Scene::Center().moveBy(-500, -275));
	m_titleButton.draw(ColorF(1.0, m_startTransition.value())).drawFrame(2);
	FontAsset(U"Menu")(U"タイトルに戻る").drawAt(m_titleButton.center(), ColorF(0.25));

	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));
}
