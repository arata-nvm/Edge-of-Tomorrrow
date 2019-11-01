#include "EnemyBall.hpp"

EnemyBall::EnemyBall(P2World& world, Rect stageRect, int size) 
	: Ball::Ball(world, stageRect, size) {
}

void EnemyBall::update() {

}

void EnemyBall::update(PlayerBall ball) {
	Vec2 v;
	if (stageRect.scaled(0.7).intersects(Circle(body.getPos(), 2))) {
		v = ball.getPos() - body.getPos();
	}
	else
	{
		v = Vec2(25, 25) - body.getPos();
	}
	v *= Random();
	v *= 0.2;
	v *= body.getMass();

	body.applyLinearImpulse(v);
	body.setVelocity(body.getVelocity() * 0.99);
}

void EnemyBall::draw() const {
	body.drawWireframe();
}