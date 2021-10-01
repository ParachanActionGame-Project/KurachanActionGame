
# pragma once
#include "Common.hpp"
#include <vector>
#include "ParachanSample.hpp"

// parachanゲームシーンのサンプル
class ParaSampleScene : public MyApp::Scene
{
private:
	std::vector<ParachanSample> parachans;
	std::vector<ParachanSample> separate;

public:

	ParaSampleScene(const InitData& init);
	Stopwatch stopwatch();

	void checkMouseClick();

	//void checkReflection();

	void update() override;

	void draw() const override;
};