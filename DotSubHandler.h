#pragma once
#include "Dot.h"

class DotSubHandler
{
public:
	DotSubHandler();
	~DotSubHandler();

	void addDot(Dot* dot);
	void removeDotAt(int index);
	bool isDotAtPos(Vector2i pos) const;
	Dot* getDotAt(Vector2i pos) const;
	Dot** getDots();
	int getNrOf() const;

private:
	int nrOf;
	int cap;
	Dot** dots;

	void expandArr();
};

