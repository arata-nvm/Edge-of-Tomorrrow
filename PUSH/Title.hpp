#pragma once
#include "Common.hpp"

class Title : public MyApp::Scene {
private:
	int select = 1;

public:
	Title(const InitData& init);

	void update() override;

	void draw() const override;
};