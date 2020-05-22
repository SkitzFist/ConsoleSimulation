#pragma once
#include <math.h>
#include "Position.h"

float getDistance(Vector2i a, Vector2i b) {

	float x = static_cast<float>(b.x - a.x);
	float y = static_cast<float>(b.y - a.y);
	float delta = static_cast<float>(sqrt((x * x) + (y * y)));
	return delta;
}

Vector2f getDirection(Vector2i a, Vector2i b) {
	float x = static_cast<float>(b.x - a.x);
	float y = static_cast<float>(b.y - a.y);
	float magnitude = static_cast<float>(sqrt((x * x) + (y * y)));
	Vector2f direction;
	direction.x = x / magnitude;
	direction.y = y / magnitude;

	return direction;
}