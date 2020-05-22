#pragma once
#include <random>

int getRandomInt(int min, int max) {

	std::random_device randomDevice;
	std::mt19937_64 configuration{randomDevice()};
	std::uniform_int_distribution<int> numbers(min, max);

	int randomInt = numbers(configuration);
	return randomInt;
}

double getRandomDouble(double min, double max) {
	std::random_device randomDevce;
	std::mt19937_64 config{ randomDevce() };
	std::uniform_real_distribution<double> numbers(min, max);
	double randomDouble = numbers(config);
	return randomDouble;
}