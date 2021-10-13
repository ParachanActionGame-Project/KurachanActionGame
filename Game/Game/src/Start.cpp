# include "Start.hpp"

Start::Start(const InitData& init)
	: IScene(init), TitleScene(U"./StartScenef.png")
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
		changeScene(State::Game);//��Ԃ�ύX�@
	}

	if (m_exitButton.leftClicked())
	{
		System::Exit();
	}
	if (m_ruleButton.leftClicked()) 
	{
		changeScene(State::Rule);/*�t�@�C���̖��O����Ȃ���, Common.hpp
		�̒��ɂ���State�̂Ƃ��̖��O*/
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
	const String titleText = U"ParachanActionGame"; //���[�u���b�N������
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Start")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Start")(titleText).drawAt(center);

	m_startButton.draw(ColorF(1.0, m_startTransition.value())).drawFrame(2);
	m_exitButton.draw(ColorF(1.0, m_exitTransition.value())).drawFrame(2);
	m_ruleButton.draw(ColorF(1.0, m_ruleTransition.value())).drawFrame(2);
	m_creditButton.draw(ColorF(1.0, m_creditTransition.value())).drawFrame(2);
	/// <summary>
	/// </summary>
	FontAsset(U"Score")(U"�Q�[���X�^�[�g�I").drawAt(m_startButton.center(), Color(0, 0, 0));
	FontAsset(U"Score")(U"�����").drawAt(m_exitButton.center(), Color(0, 0, 0));
	FontAsset(U"Score")(U"���[������").drawAt(m_ruleButton.center(), Color(0, 0, 0));
	FontAsset(U"Score")(U"�N���W�b�g").drawAt(m_creditButton.center(), Color(0,0,0));
	
	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));

	const int32 highScore = getData().highScore;
	FontAsset(U"Score")(U"High score: {}"_fmt(highScore)).drawAt(Vec2(1000/*620*/, 650/*550*/),Color(0,0,0));
}