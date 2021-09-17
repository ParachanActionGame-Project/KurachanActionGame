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
		changeScene(State::Title);//��Ԃ�ύX�@
	}

	if (m_exitButton.leftClicked())
	{
		System::Exit();
	}
}

void Start::draw() const
{
	const String titleText = U"ParachanActionGame"; //���[�u���b�N������
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Start")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Start")(titleText).drawAt(center);

	m_startButton.draw(ColorF(1.0, m_startTransition.value())).drawFrame(2);
	m_exitButton.draw(ColorF(1.0, m_exitTransition.value())).drawFrame(2);

	FontAsset(U"Menu")(U"�Q�[���X�^�[�g�I").drawAt(m_startButton.center(), ColorF(0.25));
	FontAsset(U"Menu")(U"�����").drawAt(m_exitButton.center(), ColorF(0.25));
	//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[
	FontAsset(U"Menu")(U"���[������").drawAt(m_ruleButton.center(), ColorF(0.25));
	FontAsset(U"Menu")(U"�N���W�b�g").drawAt(m_creditButton.center(), ColorF(0.25));
	////////////m_startButton�𗬗p������d�Ȃ���-->rule��credit��ǉ�����

	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));

	const int32 highScore = getData().highScore;
	FontAsset(U"Score")(U"High score: {}"_fmt(highScore)).drawAt(Vec2(620, 550));
}