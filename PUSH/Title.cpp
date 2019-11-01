#include "Title.hpp"
#include "Random.hpp"

Title::Title(const InitData& init) : IScene(init) {
	getData().rankings.each([](Ranking& ranking) { ranking.loadRanking(); });
}

void Title::update() {
	if (KeyDown.down()) {
		if (++select > 3) select = 1;
	}
	if (KeyUp.down()) {
		if (--select < 1) select = 3;
	}
	if (KeySpace.down()) {
		getData().selectedStage = select;
		changeScene(State::Game, getData().sceneTransisionTime);
	}
}

void Title::draw() const {
	const String titleText = U"Edge of Tomorrow";
	const int centerX = Scene::Center().x;
	const Vec2 center(centerX, 120);
	FontAsset(U"Title")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Title")(titleText).drawAt(center);

	for (int i = 1; i <= 3; i++) {
		FontAsset(U"Score")(U"ステージ ", i).drawAt(centerX, 300 + i * 100);
	}

	FontAsset(U"Score")(U"⇒").drawAt(centerX - 140, 300 + select * 100);

	Array<int> ranks = getData().rankings[select - 1].getScores(3);
	for (int i = 1; i <= 3; i++) {
		FontAsset(U"Score")(ranks[i - 1], U" 秒").drawAt(centerX * 1.5, 300 + i * 50);
	}

	FontAsset(U"Score")(U"Select stage").drawAt(centerX, 800);

	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));
}