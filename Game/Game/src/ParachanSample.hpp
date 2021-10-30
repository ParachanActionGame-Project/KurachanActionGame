# pragma once
# include <Siv3D.hpp>

/*さんたろ*/
//ロロ

/* ぱらちゃん1体のパラメータ保持と処理 */
class ParachanSample {
private:
	Vec2 position;
	double radius;
	Vec2 velocity;
	Stopwatch countTime;
	Texture texture, texture_16,texture_8, texture_4, texture_2, texture_1;
	
public:
	/* コンストラクタ */
	ParachanSample(const Vec2 position, double radius, const Vec2 velocity, Texture texture_16,Texture texture_8, Texture texture_4, Texture texture_2, Texture texture_1);
	ParachanSample(const Vec2 position, double radius,Texture texture_16,
		Texture texture_8, Texture texture_4, Texture texture_2, Texture texture_1);
	/* 毎フレームの値更新処理 */
	void update();

	/* 毎フレームの描画処理 */
	void draw();

	/* getter */
	Vec2 getPosition() const;
	double getRadius();
	Vec2 getVelocity() const;
	
	//setter
	void setRadius(double x);

	double checkSizeW();
	double checkSizeH();
};