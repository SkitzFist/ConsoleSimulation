#include "SheepBehaviour.h"
#include "Dot.h"

//debug
#include <iostream>

SheepBehaviour::SheepBehaviour(Dot* dot):
	IDotBehaviour(dot)
{
}

SheepBehaviour::~SheepBehaviour()
{
}

void SheepBehaviour::behave(double delta)
{
	Dot* master = getDot();
	int newX = static_cast<int>(delta * master->getSpeed() * master->getDir().x);
	int newY = static_cast<int>(delta * master->getSpeed() * master->getDir().y);
	master->setPosX (master->getPosition().x + newX);
	master->setPosY (master->getPosition().y + newY);
	master->alterLifeTime(-delta);
}
