#include "PlayerBall.hpp"

PlayerBall::PlayerBall(P2World& world, Rect stageRect, int size)
	: Ball::Ball(world, stageRect, size) {
}

Vec2 PlayerBall::getPos() const {
	return body.getPos();
}

void PlayerBall::update() {
	int scale = 10;
	if (KeyUp.pressed()) {
		body.applyLinearImpulse(Vec2(0, -scale));
	}

	if (KeyLeft.pressed()) {
		body.applyLinearImpulse(Vec2(-scale, 0));
	}

	if (KeyDown.pressed()) {
		body.applyLinearImpulse(Vec2(0, scale));
	}

	if (KeyRight.pressed()) {
		body.applyLinearImpulse(Vec2(scale, 0));
	}

	body.setVelocity(body.getVelocity() * 0.99);
}

void PlayerBall::draw() const {
	body.draw(Palette::Deepskyblue);
}