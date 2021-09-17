# pragma once
# include "Common.hpp"

// タイトルシーン
class Start : public MyApp::Scene
{
private:

	Rect m_startButton = Rect(Arg::center = Scene::Center().movedBy(0, 0), 300, 60);
	Transition m_startTransition = Transition(0.4s, 0.2s);

	Rect m_exitButton = Rect(Arg::center = Scene::Center().movedBy(0, 100), 300, 60);
	Transition m_exitTransition = Transition(0.4s, 0.2s);
	/////////////////////////////////////////////////////////////////追加 
	
	
	Rect m_ruleButton = Rect(Arg::center = Scene::Center().movedBy(0, 200), 300, 60);
	Transition m_ruleTransition = Transition(0.4s, 0.2s);

	Rect m_creditButton = Rect(Arg::center = Scene::Center().movedBy(0, 300), 300, 60);
	Transition m_creditTransition = Transition(0.4s, 0.2s);


public:

	Start(const InitData& init);

	void update() override;

	void draw() const override;
};