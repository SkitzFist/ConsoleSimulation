#include "IDotBehaviour.h"
#include "Dot.h"

IDotBehaviour::IDotBehaviour(Dot* dot)
{
	//config

	//setup
	this->dot = dot;
	//debug
}

IDotBehaviour::~IDotBehaviour()
{
}

Dot* IDotBehaviour::getDot() const
{
	return dot;
}
