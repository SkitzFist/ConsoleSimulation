#pragma once
#include "IDotBehaviour.h"

class MovRight:
	public IDotBehaviour
{
public:
	MovRight(Dot* dot);
	~MovRight();

	// Inherited via IDotBehaviour
	virtual void behave(double delta) override;

private:

};

