
# pragma once
#include "Common.hpp"
#include <vector>
#include "ParachanSample.hpp"

// parachanゲームシーンのサンプル
class ParaSampleScene : public MyApp::Scene
{
private:
	std::vector<ParachanSample> parachans;
	int countClick = 0;
	std::vector<Texture> textures;
public:

	ParaSampleScene(const InitData& init);

	void checkMouseClick();

	void update() override;

	void draw() const override;
};