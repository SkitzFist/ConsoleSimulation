#include "DotFactory.h"

#include "Random.h"
#include "FoodBehaviour.h"
#include "SheepBehaviour.h"
#include "WolfBehaviour.h"
#include "MovRight.h"

DotFactory::DotFactory(int width, int height)
{
	//config

	//setup
	this->width = width;
	this->height = height;

	//debug
}

DotFactory::~DotFactory()
{
}

Dot* DotFactory::createTest()
{
	Dot* test = new Dot(getRandomPos(), 'T');
	IDotBehaviour* behaviour = new MovRight(test);
	test->setBehaviour(behaviour);
	return test;
}

const Vector2i DotFactory::getRandomPos() const
{
	Vector2i pos;
	pos.x = getRandomInt(1, width - 1);
	pos.y = getRandomInt(1, height - 1);
	return pos;
}

Dot* DotFactory::createWolf()
{
	Dot* wolf = new Dot(getRandomPos(), 'W');
	IDotBehaviour* wolfBehaviour = new WolfBehaviour(wolf);
	wolf->setBehaviour(wolfBehaviour);
	wolf->alterLifeTime(2.5);
	return wolf;
}

Dot* DotFactory::createSheep()
{
	Dot* sheep = new Dot(getRandomPos(), 'S');
	IDotBehaviour* sheepBehaviour = new SheepBehaviour(sheep);
	sheep->setBehaviour(sheepBehaviour);
	return sheep;
}

Dot* DotFactory::createFood()
{
	Dot* food = new Dot(getRandomPos(), '*');
	IDotBehaviour* foodBehaviour = new FoodBehaviour(food);
	food->setBehaviour(foodBehaviour);
	return food;
}