#include "MovRight.h"
#include "Dot.h"

MovRight::MovRight(Dot* dot):
	IDotBehaviour(dot)
{
}

MovRight::~MovRight()
{
}

void MovRight::behave(double delta)
{
	getDot()->setPosition(getDot()->getPosition().x + 1, getDot()->getPosition().y);
}
