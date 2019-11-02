#include "Game.hpp"
#include "Random.hpp"

Game::Game(const InitData& init) : IScene(init) {
	this->init(getData().selectedStage);
	spentTime.start();
}

void Game::init(int level) {
	spentTime.restart();
	finished = false;
	switch (level) {
	case 1:
		for (int i = 0; i < 1; i++) {
			others << EnemyBall(world, stage, 2);
		}
		break;
	case 2:
		for (int i = 0; i < 10; i++) {
			others << EnemyBall(world, stage, 2);
		}
		break;
	case 3:
		for (int i = 0; i < 15; i++) {
			others << EnemyBall(world, stage, 3);
		}
		break;
	}
}

void Game::update() {
	if (KeySpace.down()) {
		changeScene(State::Game, getData().sceneTransisionTime);
		return;
	}
	if (KeyEnter.down()) {
		changeScene(State::Title, getData().sceneTransisionTime);
		return;
	}

	if (finished) return;

	if (ball.isOutOfStage()) {
		spentTime.pause();
		finished = true;
		return;
	}

	if (others.size() == 0) {
		spentTime.pause();
		getData().rankings[getData().selectedStage - 1].addScore(spentTime.s());
	 	getData().rankings[getData().selectedStage - 1].saveRanking();
		finished = true;
		return;
	}

	camera.update();

	 
	world .update(1.0 / 60.0, 12, 4);

	ball.update();

	camera.setCenter(stage.center());

	others.remove_if([](EnemyBall b) { return b.isOutOfStage(); });

	others.each([&](EnemyBall& b) { b.update(ball); });
}

void Game::draw() const {
	{
		const auto t = camera.createTransformer();

		stage.draw(Palette::Skyblue);

		ball.draw();

		others.each([](EnemyBall b) { b.draw(); });
 	}

	FontAsset(U"Score")(U"経過時間: ", spentTime.s(), U"秒").drawAt(Scene::Center().x * 1.8, Scene::Height() - 160);
	FontAsset(U"Score")(U"あと ", others.size(), U"体").drawAt(Scene::Center().x * 1.8, Scene::Height() - 120);

	if (!stage.intersects(Circle(ball.getPos(), 2))) {
		FontAsset(U"Title")(U"Game Over").drawAt(Scene::Center());
		FontAsset(U"Menu")(U"スペースキー : リトライ").drawAt(Scene::Center().movedBy(0, 100));
		FontAsset(U"Menu")(U"エンターキー : 戻る").drawAt(Scene::Center().movedBy(0,140));
		return;
	}

	if (others.size() == 0) {
		FontAsset(U"Title")(U"Game Clear!").drawAt(Scene::Center());
		FontAsset(U"Menu")(U"スペースキー : リトライ").drawAt(Scene::Center().movedBy(0, 100));
		FontAsset(U"Menu")(U"エンターキー : 戻る").drawAt(Scene::Center().movedBy(0, 140));
		return;
	}

	FontAsset(U"Menu")(U"スペースキー : リトライ").draw(Scene::Center().x * 1.65, Scene::Height() - 80);
	FontAsset(U"Menu")(U"エンターキー : 戻る").draw(Scene::Center().x * 1.65, Scene::Height() - 40);
}
