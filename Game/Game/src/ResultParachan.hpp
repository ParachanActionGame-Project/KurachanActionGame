# pragma once
# include <Siv3D.hpp>

/* リザルト画面に映すぱらちゃん。ゲームシーンのぱらちゃん実装まで仮実装 */
class ResultParachan {
private:
	Vec2 position;
	double size;
	Vec2 velocity;
	const Texture texture;

public:
	/* コンストラクタ */
	ResultParachan(const Vec2 position, double size, const Vec2 velocity, String imagePath);
	ResultParachan(const Vec2 position, double size, const Vec2 velocity);
	ResultParachan(const Vec2 position, double size);

	/* 毎フレームの値更新処理 */
	void update();

	/* 毎フレームの描画処理 */
	void draw() const;

	/* getter */
	Vec2 getPosition() const;
	double getRadius();
	Vec2 getVelocity() const;
};