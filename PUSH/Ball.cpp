#include "Ball.hpp"

Ball::Ball(P2World& world, Rect stageRect, int size) {
	this->body = world.createCircle(RandomVec2(stageRect), size);
	this->stageRect = stageRect;
	this->size = size;
}

bool Ball::isOutOfStage() {
	return !stageRect.intersects(Circle(body.getPos(), size));
}
