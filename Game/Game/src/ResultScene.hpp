
# pragma once
# include "Common.hpp"
# include "ResultParachan.hpp"
# include <vector>

// リザルトシーン
// ぱらちゃんを1匹泳がせる。等速直線運動で、スクリーン端で跳ね返る
class ResultScene : public MyApp::Scene
{
private:
	std::vector<ResultParachan> parachans
	{
		ResultParachan(Scene::Center(), 10.0, Vec2(100.0, 50.0)), 
		ResultParachan(Scene::Center() + Vec2(100.0, 0.0), 30.0, Vec2(0, 100.0)), 
		ResultParachan(Scene::Center() + Vec2(-50.0, 50.0), 10.0, Vec2(-60.0, 80.0)) 
	};
	//ResultParachan parachan = ResultParachan(Scene::Center(), 20.0, Vec2(100.0, 50.0));

	Rect m_startButton = Rect(Arg::center = Scene::Center().movedBy(0, 80), 300, 60);
	Transition m_startTransition = Transition(0.4s, 0.2s);

	Rect m_goTitleButton = Rect(Arg::center = Scene::Center().movedBy(0, 160), 300, 60);
	Transition m_goTitleTransition = Transition(0.4s, 0.2s);

	Rect m_exitButton = Rect(Arg::center = Scene::Center().movedBy(0, 240), 300, 60);
	Transition m_exitTransition = Transition(0.4s, 0.2s);

	Rect m_tweetButton = Rect(Arg::center = Scene::Center().movedBy(300, 240), 150, 60);
	Transition m_tweetTransition = Transition(0.4s, 0.2s);

	int highScore; //今回のプレイ以前のハイスコア

public:

	ResultScene(const InitData& init);

	void update() override;

	void draw() const override;

	void writeHighScore();

	void setHighScore(int highScore);

	int getHighScore();

	void updateHighScore();
};
