
# pragma once
# include "Common.hpp"

// クレジットシーン
class CreditScene : public MyApp::Scene
{
private:
	Rect m_titleButton = Rect(Arg::center = Scene::Center().movedBy(237, 200), 300, 60);
	Transition m_titleTransition = Transition(0.4s, 0.2s);

	Rect m_startButton = Rect(Arg::center = Scene::Center().movedBy(0, 0), 300, 60);
	Transition m_startTransition = Transition(0.4s, 0.2s);



public:

	CreditScene(const InitData& init);

	void update() override;

	void draw() const override;

	Texture StuffCredit, Kurachan_32;
	
};
