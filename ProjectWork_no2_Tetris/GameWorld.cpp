#include "GameWorld.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

GameWorld::GameWorld(sf::RenderWindow* _window) {

	sf::Vector2u size = _window->getSize();

	window = _window;
	spawnNewFigure("T");
}
GameWorld::GameWorld(int _windowHeight, int _windowWidth,sf::RenderWindow* _window) {

	noOfGrid[0] = _windowWidth / 50;
	noOfGrid[1] = _windowHeight / 50;
	window = _window;
	spawnNewFigure("Rand");
}

GameWorld::~GameWorld() {
	for (int i = 0; i < figures.size(); i++)
	{
		delete figures[i];
	}
}

void GameWorld::spawnNewFigure(std::string type) {
	if (type == "Rand") {
		int r = rand() % 4+1;
		switch (r)
		{
		case(1):
			figures.push_back(new Figure("T"));
			break;
		case(2):
			figures.push_back(new Figure("I"));
			break;
		case(3):
			figures.push_back(new Figure("Z"));
			break;
		case(4):
			figures.push_back(new Figure("o"));
			break;
		}


	}
	else
	{
	figures.push_back(new Figure(type));
	}
	curentDroping = figures[figures.size() - 1];
}
void GameWorld::draw() {
	
	for (int i = 0; i < figures.size(); i++)
	{
		std::vector<sf::Sprite>* sprite = figures[i]->getComponet();

		for (int j = 0; j < sprite->size(); j++)
		{
			window->draw((*sprite)[j]);
		}
		delete sprite;
	}
	
}
void GameWorld::keyPressed(const std::string& key) {
	if (key == "down")
	{
		curentDroping->fall();

		if (colisionDetec())
		{
			curentDroping->undoFall();
			lainDeleter();
			spawnNewFigure("Rand");
		}
		
	}
	else if (key == "right")
	{
		curentDroping->move(false);
		if (colisionDetec())
		{
			curentDroping->undoMove(false);
		}
	}
	else if (key == "left")
	{
		curentDroping->move(true);
		if (colisionDetec())
		{
			curentDroping->undoMove(true);
		}
	}
	else if (key == "up") {
		curentDroping->rotate();
		if (colisionDetec())
		{
			curentDroping->undoRotate();
			
		}
	}
}

bool GameWorld::colisionDetec() {

	for (int i = 0; i < curentDroping->components.size(); i++)
	{
		sf::Vector2i pos(curentDroping->components[i]->pos.x, curentDroping->components[i]->pos.y);
		if (pos.x<0||pos.y>=noOfGrid[0]|| pos.x>=noOfGrid[1])
		{
			return true;
		}

		for (int j = 0; j < figures.size(); j++)
		{
			if (figures[j] != curentDroping)
			{
				for (int k = 0; k < figures[j]->components.size(); k++)
				{
					if (figures[j]->components[k]->isAlive)
					{
						if (pos.x == figures[j]->components[k]->pos.x &&
							pos.y == figures[j]->components[k]->pos.y)
						{
							return true;
						}
					}
				}
			}
		}
	}
	
	return false;
	
}
void GameWorld::lainDeleter() {

	std::vector<std::vector<bool>> board(noOfGrid[0], std::vector<bool>(noOfGrid[1], false));
	for (int i = 0; i < figures.size(); i++)
	{
		for (int j = 0; j < figures[i]->components.size(); j++)
		{

			if (figures[i]->components[j]->isAlive)
			{
				board[figures[i]->components[j]->pos.y][figures[i]->components[j]->pos.x] = true;
			}


		}
	}
	for (int i = 0; i < board.size(); i++)
	{
		bool isLainFull = true;
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == false)
			{
				isLainFull = false;
				break;
			}
		}
		if (isLainFull)
		{
			for (int k = 0; k < figures.size(); k++)
			{
				for (int l = 0; l < figures[k]->components.size(); l++)
				{

					if (figures[k]->components[l]->isAlive)
					{
						if (figures[k]->components[l]->pos.y==i)
						{
							figures[k]->components[l]->isAlive = false;
						}
					}

				}
			}
			for (int g = 0; g< figures.size(); g++)
			{
				figures[g]->fall(i);
			}
		}
	}
}