# pragma once
# include <Siv3D.hpp>

namespace result {
	enum EResultKurachan {
		VERY_BIG,
		BIG,
		MIDDLE,
		SMALL,
		VERY_SMALL,

		OTHER
	};
}

using namespace result;

/* リザルト画面に映すくらちゃん。 */
class ResultKurachan {
private:
	Vec2 position;
	EResultKurachan type;
	Vec2 velocity;
	const Texture texture;
	double scale;

	void initScale();
	String getTexturePath(EResultKurachan type);

public:
	/* コンストラクタ */
	ResultKurachan(const Vec2 position, EResultKurachan type, const Vec2 velocity, String imagePath);
	ResultKurachan(const Vec2 position, EResultKurachan type, const Vec2 velocity);
	ResultKurachan(const Vec2 position, EResultKurachan type);

	/* 毎フレームの値更新処理 */
	void update();

	/* 毎フレームの描画処理 */
	void draw() const;

	/* getter */
	Vec2 getPosition() const;
	Vec2 getVelocity() const;
	double getScale();
};

