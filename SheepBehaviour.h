#pragma once
#include "IDotBehaviour.h"


class SheepBehaviour:
	public IDotBehaviour
{
public:
	SheepBehaviour(Dot* dot);
	~SheepBehaviour();
	// Inherited via IDotBehaviour
	virtual void behave(double delta) override;
};

