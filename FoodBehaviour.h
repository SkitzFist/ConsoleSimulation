#pragma once
#include "IDotBehaviour.h"
class FoodBehaviour :
	public IDotBehaviour
{
public:
	FoodBehaviour(Dot* dot);
	~FoodBehaviour();

	// Inherited via IDotBehaviour
	virtual void behave(double delta) override;

private:
	double lifeTime;
};

