#pragma once
#include "DeltaTime.h"

class Dot;
class IDotBehaviour
{
public:
	IDotBehaviour(Dot* dot);
	~IDotBehaviour();

	virtual void behave(double delta) = 0;

protected:
	Dot* getDot() const;
private:
	Dot* dot;
};

