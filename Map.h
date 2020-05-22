#pragma once
#include <string>
#include <vector>

struct Size {
	int width;
	int height;
};

class Map
{
public:
	Map(int width, int height);
	~Map();
	void render() const;
	void addAt(int index, char c);
	const Size& getSize() const;
	void cleanMap();

private:
	Size size;
	std::string* map;

	
};

