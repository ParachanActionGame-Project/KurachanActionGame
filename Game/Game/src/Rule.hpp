#pragma once
# include "Common.hpp"

// ƒ‹[ƒ‹ƒV[ƒ“
class Rule : public MyApp::Scene
{
private:

	Rect m_returnButton = Rect(Arg::center = Scene::Center().movedBy(0, 150), 225, 40);
	Transition m_startTransition = Transition(0.4s, 0.2s);

	

public:

	Rule(const InitData& init);

	void update() override;

	void draw() const override;
};
