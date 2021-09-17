# pragma once
# include <Siv3D.hpp>

/* ぱらちゃん1体のパラメータ保持と処理 */
class ParachanSample {
private:
	Vec2 position;
	double radius;
	Vec2 velocity;
	
public:
	/* コンストラクタ */
	ParachanSample(const Vec2 position, double radius, const Vec2 velocity);
	ParachanSample(const Vec2 position, double radius);

	/* 毎フレームの値更新処理 */
	void update();

	/* 毎フレームの描画処理 */
	void draw();

	/* getter */
	Vec2 getPosition() const;
	double getRadius();
	Vec2 getVelocity() const;
};