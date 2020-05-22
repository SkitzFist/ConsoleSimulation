#include "Game.h"
#include <thread>
#include <Windows.h>
#include <string>

//debug
#include <iostream>

void setcursor(bool, DWORD);
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

Game::Game() :
	dotHandler(WIDTH, HEIGHT)
{
	//config
	delay = 16;
	//setup
	setcursor(0, 0);
	isRunning = true;
	map = new Map(WIDTH, HEIGHT);

	//debug
	dotHandler.createFood();
	dotHandler.createSheep();
	dotHandler.createSheep();
	dotHandler.createSheep();
	dotHandler.createSheep();
	dotHandler.createWolf();
	dotHandler.createWolf();
}

Game::~Game()
{
	delete map;
}

void Game::run()
{	

	while (isRunning)	{
		dt.restartClock();
		update(dt.getDeltaTime());
		buildMap();
		render();
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
}

void Game::update(double delta)
{
	dotHandler.update(delta);
}

void Game::buildMap()
{
	for (int y = 0; y < map->getSize().height; ++y) {
		for (int x = 0; x < map->getSize().width; ++x) {
			Dot* dot = dotHandler.getDotAtPos(x, y);
			if (dot) {
				map->addAt(y, dot->getChar());
			}
			else {
				map->addAt(y, ' ');
			}
		}
	}
}

void Game::render() const
{
	system("cls");
	map->render();
	map->cleanMap();
	std::cout <<"Wolfs: " << dotHandler.getNrOfWolfs() << "    Sheep: " << dotHandler.getNrOfSheep() << std::flush;
}

void setcursor(bool visible, DWORD size)
{
	if (size == 0)
	{
		size = 20;	
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}