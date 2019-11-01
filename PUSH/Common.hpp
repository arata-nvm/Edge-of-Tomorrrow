#pragma once
#include <Siv3D.hpp>
#include "Ranking.h"

enum class State {
	Title,
	Game
};

struct GameData {
	int32 sceneTransisionTime = 200;
	
	Array<Ranking> rankings = { Ranking(U"stage1.txt"), Ranking(U"stage2.txt"), Ranking(U"stage3.txt") };

	int selectedStage = 1;
};

using MyApp = SceneManager<State, GameData>;