#include "Dot.h"

//debug
#include "MovRight.h"

Dot::Dot(Vector2i pos, char c)
{
	//config
	speed = 12.f;

	//setup
	isAlive = true;
	position.x = pos.x;
	position.y = pos.y;
	this->c = c;
	this->behaviour = nullptr;
	dir = { 0.f,0.f };
	lifeTime = 8.0;
	//debug
	
}

Dot::~Dot()
{
	delete behaviour;
}

void Dot::update(double delta)
{
	behaviour->behave(delta);
}

Vector2i Dot::getPosition() const
{
	return position;
}

void Dot::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Dot::setPosX(int x)
{
	position.x = x;
}

void Dot::setPosY(int y)
{
	position.y = y;
}

char Dot::getChar() const
{
	return c;
}

void Dot::setBehaviour(IDotBehaviour* behaviour)
{
	this->behaviour = behaviour;
}

void Dot::alterLifeTime(double time)
{
	lifeTime += time;
}

double Dot::getLifeTime() const
{
	return lifeTime;
}

void Dot::setIsAlive(bool value)
{
	isAlive = value;
}

bool Dot::getIsAlive() const
{
	return isAlive;
}

float Dot::getSpeed() const
{
	return speed;
}

void Dot::setDirection(Vector2f dir)
{
	this->dir = dir;
}

Vector2f Dot::getDir() const
{
	return dir;
}
