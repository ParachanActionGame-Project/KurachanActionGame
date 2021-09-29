
# pragma once
# include "Common.hpp"
# include "ResultParachan.hpp"

// リザルトシーン
// ぱらちゃんを1匹泳がせる。等速直線運動で、スクリーン端で跳ね返る
class ResultScene : public MyApp::Scene
{
private:
	ResultParachan parachan = ResultParachan(Scene::Center(), 40.0);

	Rect m_startButton = Rect(Arg::center = Scene::Center().movedBy(0, 80), 300, 60);
	Transition m_startTransition = Transition(0.4s, 0.2s);

	Rect m_goTitleButton = Rect(Arg::center = Scene::Center().movedBy(0, 160), 300, 60);
	Transition m_goTitleTransition = Transition(0.4s, 0.2s);

	Rect m_exitButton = Rect(Arg::center = Scene::Center().movedBy(0, 240), 300, 60);
	Transition m_exitTransition = Transition(0.4s, 0.2s);

public:

	ResultScene(const InitData& init);

	void update() override;

	void draw() const override;
};
