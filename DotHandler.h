#pragma once
#include "DotFactory.h"
#include "DotSubHandler.h"

class DotHandler
{
public:
	DotHandler(int width, int height);
	~DotHandler();
	 
	void update(double delta);
	Dot* getDotAtPos(int x, int y) const;

	int getNrOfSheep() const;
	int getNrOfWolfs() const;
	void createSheep();
	void createWolf();
	void createFood();

private:
	DotFactory factory;
	DotSubHandler sheepHandler;
	DotSubHandler foodHandler;
	DotSubHandler wolfHandler;

	double foodTimer;

	void updateSheep(double delta);
	void updateFood(double delta);
	void updateWolf(double delta);
	bool isColliding(Vector2i a, Vector2i b) const;
	void setDirection(Dot* dot, Dot** arr, int nrOf);
};

