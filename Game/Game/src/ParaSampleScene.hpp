
# pragma once
#include "Common.hpp"
#include <vector>
#include "ParachanSample.hpp"

// parachan�Q�[���V�[���̃T���v��
class ParaSampleScene : public MyApp::Scene
{
private:
	std::vector<ParachanSample> parachans;

public:

	ParaSampleScene(const InitData& init);

	void checkMouseClick();

	void update() override;

	void draw() const override;
};