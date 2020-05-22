#include "Map.h"
#include <iostream>

Map::Map(int width, int height)
{
	//config

	//setup
	size.width = width;
	size.height = height;
	map = new std::string[height];

	//debug

}

Map::~Map()
{
	delete[] map;
}

void Map::render() const
{
	for (int y = 0; y < size.height; ++y) {
		printf(map[y].c_str());
		printf("\n");
	}
}

void Map::addAt(int index, char c)
{
	map[index] += c;
}

const Size& Map::getSize() const
{
	return size;
}

void Map::cleanMap()
{
	for (int i = 0; i < size.height; ++i) {
		map[i] = "";
	}
}
