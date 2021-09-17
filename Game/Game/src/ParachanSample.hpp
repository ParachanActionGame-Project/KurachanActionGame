# pragma once
# include <Siv3D.hpp>

/* �ς炿���1�̂̃p�����[�^�ێ��Ə��� */
class ParachanSample {
private:
	Vec2 position;
	double radius;
	Vec2 velocity;
	
public:
	/* �R���X�g���N�^ */
	ParachanSample(const Vec2 position, double radius, const Vec2 velocity);
	ParachanSample(const Vec2 position, double radius);

	/* ���t���[���̒l�X�V���� */
	void update();

	/* ���t���[���̕`�揈�� */
	void draw();

	/* getter */
	Vec2 getPosition() const;
	double getRadius();
	Vec2 getVelocity() const;
};