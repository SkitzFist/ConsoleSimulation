#include "DotHandler.h"
#include "Distance.h"
//debug
#include <iostream>

const double FOODTIME = 0.5;

DotHandler::DotHandler(int width, int height) :
	factory(width, height)
{
	//config
	foodTimer = 0.0;
	//setup

	//debug
}

DotHandler::~DotHandler()
{

}

void DotHandler::update(double delta)
{
	updateSheep(delta);
	updateFood(delta);
	updateWolf(delta);

}

Dot* DotHandler::getDotAtPos(int x, int y) const
{
	Vector2i pos;
	pos.x = x;
	pos.y = y;
	bool hasFound = false;
	Dot* dot = nullptr;

	if (!hasFound) {
		if (foodHandler.isDotAtPos(pos)) {
			hasFound = true;
			dot = foodHandler.getDotAt(pos);
		}
	}

	if (!hasFound) {
		if (sheepHandler.isDotAtPos(pos)) {
			hasFound = true;
			dot = sheepHandler.getDotAt(pos);
		}
	}

	if (!hasFound) {
		if (wolfHandler.isDotAtPos(pos)) {
			hasFound = true;
			dot = wolfHandler.getDotAt(pos);
		}
	}

	return dot;
}

int DotHandler::getNrOfSheep() const
{
	return sheepHandler.getNrOf();
}

int DotHandler::getNrOfWolfs() const
{
	return wolfHandler.getNrOf();
}

void DotHandler::createSheep()
{
	sheepHandler.addDot(factory.createSheep());

}

void DotHandler::createWolf()
{
	wolfHandler.addDot(factory.createWolf());
}

void DotHandler::createFood()
{
	foodHandler.addDot(factory.createFood());
}

void DotHandler::updateSheep(double delta)
{
	for (int i = 0; i < sheepHandler.getNrOf(); ++i) {

		Dot* sheep = sheepHandler.getDots()[i];
		Dot* food = foodHandler.getDots()[0];

		if (food) {
			setDirection(sheep, foodHandler.getDots(), foodHandler.getNrOf());
		}
		else {
			Vector2f dir = { 0.f, 0.f };
			sheep->setDirection(dir);
		}
		sheep->update(delta);
		int index = 0;
		while (foodHandler.getNrOf() > 0 && index < foodHandler.getNrOf())
		{
			if (isColliding(sheep->getPosition(), foodHandler.getDots()[index]->getPosition())) {
				foodHandler.removeDotAt(index);
				sheep->alterLifeTime(0.5);
				createSheep(); // TODO :: Make this chance of spawn
			}
			++index;
		}

		if (sheep->getLifeTime() < 0.0) {
			sheepHandler.removeDotAt(i);
		}
		
	}
}

void DotHandler::updateFood(double delta)
{
	foodTimer -= delta;
	if (foodTimer < 0) {
		createFood();
		createFood();
		createFood();
		createFood();
		createFood();
		foodTimer = FOODTIME;
	}
}

void DotHandler::updateWolf(double delta)
{
	for (int i = 0; i < wolfHandler.getNrOf(); ++i) {

		Dot* wolf = wolfHandler.getDots()[i];
		Dot* sheep = sheepHandler.getDots()[0];

		if (sheep) {
			setDirection(wolf, sheepHandler.getDots(), sheepHandler.getNrOf());
		}
		else {
			Vector2f dir = { 0.f, 0.f };
			wolf->setDirection(dir);
		}
		wolf->update(delta);
		int index = 0;
		while (sheepHandler.getNrOf() > 0 && index < sheepHandler.getNrOf())
		{
			if (isColliding(wolf->getPosition(), sheepHandler.getDots()[index]->getPosition())) {
				sheepHandler.removeDotAt(index);
				wolf->alterLifeTime(0.1);
				int random = rand() % 100;
				if (random > 70) {
					createWolf();
				}
			}
			++index;
		}

		if (wolf->getLifeTime() < 0.0) {
			wolfHandler.removeDotAt(i);
		}

	}
}

bool DotHandler::isColliding(Vector2i a, Vector2i b) const
{
	if (a.x == b.x && a.y == b.y) {
		return true;
	}
	return false;
}

void DotHandler::setDirection(Dot* dot, Dot** arr, int nrOf)
{
	Dot* target = arr[0];
	int index = 0;
	float minDistance = getDistance(dot->getPosition(), target->getPosition());
	for (int i = 1; i < nrOf; ++i) {
		target = arr[i];
		float distance = getDistance(dot->getPosition(), target->getPosition());
		if (distance < minDistance) {
			minDistance = distance;
			index = i;
		}
	}
	target = arr[index];
	Vector2f direction = getDirection(dot->getPosition(), target->getPosition());
	dot->setDirection(direction);
}
