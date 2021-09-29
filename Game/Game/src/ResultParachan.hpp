# pragma once
# include <Siv3D.hpp>

/* リザルト画面に映すぱらちゃん。ゲームシーンのぱらちゃん実装まで仮実装 */
class ResultParachan {
private:
	Vec2 position;
	double radius;
	Vec2 velocity;

public:
	/* コンストラクタ */
	ResultParachan(const Vec2 position, double radius, const Vec2 velocity);
	ResultParachan(const Vec2 position, double radius);

	/* 毎フレームの値更新処理 */
	void update();

	/* 毎フレームの描画処理 */
	void draw() const;

	/* getter */
	Vec2 getPosition() const;
	double getRadius();
	Vec2 getVelocity() const;
};