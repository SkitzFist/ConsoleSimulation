#pragma once
#include "DotHandler.h"
#include "Map.h"
#include "DeltaTime.h"

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	const int WIDTH = 90;
	const int HEIGHT = 28;
	bool isRunning;
	int delay;

	DeltaTime dt;
	Map* map;
	DotHandler dotHandler;

	void update(double delta);
	void buildMap();
	void render() const;
};

