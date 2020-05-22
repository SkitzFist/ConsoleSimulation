#pragma once
#include "IDotBehaviour.h"
class WolfBehaviour :
	public IDotBehaviour
{
public:
	WolfBehaviour(Dot* dot);
	~WolfBehaviour();

	// Inherited via IDotBehaviour
	virtual void behave(double delta) override;
};

