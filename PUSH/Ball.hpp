#pragma once
#include <Siv3D.hpp>

class Ball
{
protected:
	Rect stageRect;

	P2Body body;

	int size;

public:
	Ball(P2World& world, Rect stageRect, int size);

	bool isOutOfStage();

	virtual void update() = 0;

	virtual void draw() const = 0;
};

