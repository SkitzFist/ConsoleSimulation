#include "FoodBehaviour.h"
#include "Dot.h"

FoodBehaviour::FoodBehaviour(Dot* dot):
	IDotBehaviour(dot)
{
	lifeTime = 5.0;
}

FoodBehaviour::~FoodBehaviour()
{
}

void FoodBehaviour::behave(double delta)
{
	lifeTime -= delta;
	if (lifeTime < 0) {
		getDot()->setIsAlive(false);
	}
}
