#include "Ball.hpp"

Ball::Ball(P2World& world, Rect stageRect, int size) {
	//this->body = world.createCircle(RandomVec2(stageRect.stretched(-20)), size);
	this->body = world.createRect(RandomVec2(stageRect.stretched(-10)), Rect(size, size));

	this->stageRect = stageRect;
	this->size = size;
}

bool Ball::isOutOfStage() {
	return !stageRect.intersects(Circle(body.getPos(), size));
}
