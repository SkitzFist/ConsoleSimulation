#include "WolfBehaviour.h"
#include "Dot.h"

WolfBehaviour::WolfBehaviour(Dot* dot):
	IDotBehaviour(dot)
{
}

WolfBehaviour::~WolfBehaviour()
{
}

void WolfBehaviour::behave(double delta)
{
	Dot* master = getDot();
	int newX = static_cast<int>(delta * master->getSpeed() * master->getDir().x);
	int newY = static_cast<int>(delta * master->getSpeed() * master->getDir().y);
	master->setPosX(master->getPosition().x + newX);
	master->setPosY(master->getPosition().y + newY);
	master->alterLifeTime(-delta);
}
