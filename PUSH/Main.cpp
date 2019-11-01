#include <Siv3D.hpp>
#include "Common.hpp"
#include "Title.hpp"
#include "Game.hpp"
#include "Ranking.h"
#include <iostream>

using namespace std;

void Main()
{
	System::SetTerminationTriggers(UserAction::CloseButtonClicked);
	Graphics::SetTargetFrameRateHz(60);

	Window::SetTitle(U"PUSH");
	Window::SetFullscreen(true);

	FontAsset::Register(U"Title", 120);
	FontAsset::Register(U"Menu", 30);
	FontAsset::Register(U"Score", 36, Typeface::Bold);

	MyApp sceneManager;
	sceneManager
		.add<Title>(State::Title)
		.add<Game>(State::Game)
		.setFadeColor(Palette::White);

	while (System::Update())
	{
		if (!sceneManager.update()) {
			break;
		}
	}
}


