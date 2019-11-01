#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Common.hpp"
#include "PlayerBall.hpp"
#include "EnemyBall.hpp"

class Game: public MyApp::Scene
{
private:
	Rect stage = Rect(0, 0, 50, 50);

	P2World world = P2World(0);

	PlayerBall ball = PlayerBall(world, stage, 2);

	Array<EnemyBall> others;
	
	Camera2D camera = Camera2D(Vec2(0, -8), 10.0, Camera2DParameters::MouseOnly());

	Stopwatch spentTime = Stopwatch(0s);

	bool finished = false;

public:
	Game(const InitData& init);

	void init(int level);

	void update() override;

	void draw() const override;
};

