#pragma once
#include "Position.h"
#include "IDotBehaviour.h"

class Dot
{

public:
	Dot(Vector2i pos, char c);
	~Dot();

	void update(double delta);

	Vector2i getPosition() const;
	void setPosition(int x, int y);
	void setPosX(int x);
	void setPosY(int y);

	char getChar() const;
	void setIsAlive(bool value);
	bool getIsAlive() const;
	float getSpeed() const;
	void setDirection(Vector2f dir);
	Vector2f getDir() const;

	void setBehaviour(IDotBehaviour* behaviour);
	void alterLifeTime(double time);
	double getLifeTime() const;


private:
	Vector2i position;
	Vector2f dir;
	IDotBehaviour* behaviour;
	char c;
	bool isAlive;
	float speed;
	double lifeTime;
};

