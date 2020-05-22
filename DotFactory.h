#pragma once
#include "Dot.h"

class DotFactory
{
public:
	DotFactory(int width, int height);
	~DotFactory();
	Dot* createTest();
	Dot* createWolf();
	Dot* createSheep();
	Dot* createFood();

private:
	int width, height;

	const Vector2i getRandomPos() const;
};