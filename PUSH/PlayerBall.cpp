#include "PlayerBall.hpp"

PlayerBall::PlayerBall(P2World& world, Rect stageRect, int size)
	: Ball::Ball(world, stageRect, size) {
}

Vec2 PlayerBall::getPos() const {
	return body.getPos();
}

void PlayerBall::update() {
	int scale = 15;
	if (KeyUp.pressed() || KeyW.pressed() || KeyK.pressed()) {
		body.applyLinearImpulse(Vec2(0, -scale));
	}

	if (KeyLeft.pressed() || KeyA.pressed() || KeyH.pressed()) {
		body.applyLinearImpulse(Vec2(-scale, 0));
	}

	if (KeyDown.pressed() || KeyS.pressed() || KeyJ.pressed()) {
		body.applyLinearImpulse(Vec2(0, scale));
	}

	if (KeyRight.pressed() || KeyD.pressed() || KeyL.pressed()) {
		body.applyLinearImpulse(Vec2(scale, 0));
	}

	body.setVelocity(body.getVelocity() * 0.99);
}

void PlayerBall::draw() const {
	body.draw(Palette::Pink);
}