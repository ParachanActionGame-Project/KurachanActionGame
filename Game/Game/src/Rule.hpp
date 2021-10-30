#pragma once
# include "Common.hpp"

// ルールシーン
class Rule : public MyApp::Scene
{
private:

	Rect m_returnButton = Rect(Arg::center = Scene::Center().movedBy(0,275), 225, 40);
	Transition m_startTransition = Transition(0.4s, 0.2s);
	const Texture rulePhoto;
	const Texture Background;

	

public:

	Rule(const InitData& init);

	void update() override;

	void draw() const override;
};
