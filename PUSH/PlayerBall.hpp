#pragma once
#include "Ball.hpp"

class PlayerBall: public Ball
{
public:
	PlayerBall(P2World& world, Rect stageRect, int size);

	Vec2 getPos() const ;

	void update() override;

	void draw() const override;
};

