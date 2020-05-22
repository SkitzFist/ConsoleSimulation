#include "DotSubHandler.h"

DotSubHandler::DotSubHandler()
{
	//config

	//setup
	cap = 20;
	nrOf = 0;
	dots = new Dot * [cap] {nullptr};

	//debug
}

DotSubHandler::~DotSubHandler()
{
	for (int i = 0; i < nrOf; ++i) {
		delete dots[i];
	}
	delete[] dots;
}

void DotSubHandler::addDot(Dot* dot)
{
	if (nrOf == cap) {
		expandArr();
	}
	dots[nrOf++] = dot;
}

void DotSubHandler::removeDotAt(int index)
{
	delete dots[index]; 
	dots[index] = dots[--nrOf]; 
	dots[nrOf] = nullptr; 
}

bool DotSubHandler::isDotAtPos(Vector2i pos) const
{
	bool rv = false;
	for (int i = 0; i < nrOf; ++i) {
		if (dots[i]->getPosition().x == pos.x
			&& dots[i]->getPosition().y == pos.y) {
			rv = true;
			break;
		}
	}
	return rv;
}

Dot* DotSubHandler::getDotAt(Vector2i pos) const
{
	int index = 0;
	for (int i = 0; i < nrOf; ++i) {
		if (dots[i]->getPosition().x == pos.x
			&& dots[i]->getPosition().y == pos.y) {
			index = i;
		}
	}
	return dots[index];
}

Dot** DotSubHandler::getDots()
{
	return dots;
}

int DotSubHandler::getNrOf() const
{
	return nrOf;
}

void DotSubHandler::expandArr()
{
	cap += 10;
	Dot** tmp = new Dot * [cap] { nullptr };
	for (int i = 0; i < nrOf; ++i) {
		tmp[i] = dots[i];
	}
	delete[] dots;
	dots = tmp;
}
