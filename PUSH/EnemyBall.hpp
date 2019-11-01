#pragma once
#include <Siv3D.hpp>
#include "PlayerBall.hpp"

class EnemyBall : public Ball
{
public:
	EnemyBall(P2World& world, Rect stageRect, int size);

	void update() override;

	void update(PlayerBall ball);

	void draw() const;
};

