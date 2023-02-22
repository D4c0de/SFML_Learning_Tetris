#include "GameWorld.h"
#include <SFML/Graphics.hpp>


GameWorld::GameWorld(sf::RenderWindow* _window) {

	sf::Vector2u size = _window->getSize();

	window = _window;
	spawnNewFigure("T");
}
GameWorld::GameWorld(int _windowHeight, int _windowWidth,sf::RenderWindow* _window) {

	noOfGrid[0] = _windowWidth / 50;
	noOfGrid[1] = _windowHeight / 50;
	window = _window;
	spawnNewFigure("T");
}

GameWorld::~GameWorld() {
	for (int i = 0; i < figures.size(); i++)
	{
		delete figures[i];
	}
}

void GameWorld::spawnNewFigure(std::string type) {

	figures.push_back(new Figure(type));
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

		if (!colisionDetec())
		{
			curentDroping->undoFall();
			lainDeleter();
			spawnNewFigure("I");
		}
		
	}
	else if (key == "right")
	{
		curentDroping->move(false);
		if (!colisionDetec())
		{
			curentDroping->undoMove(false);
			lainDeleter();
			spawnNewFigure("I");
		}
	}
	else if (key == "left")
	{
		curentDroping->move(true);
		if (!colisionDetec())
		{
			curentDroping->undoMove(true);
			lainDeleter();
			spawnNewFigure("I");
		}
	}
	else if (key == "up") {
		curentDroping->rotate();
		if (!colisionDetec())
		{
			curentDroping->undoRotate();
			lainDeleter();
			spawnNewFigure("I");
			
		}
	}
}

bool GameWorld::colisionDetec() {


	
	std::vector<std::vector<bool>> board(noOfGrid[0],std::vector<bool>(noOfGrid[1],false));
	for (int i = 0; i < figures.size(); i++)
	{
		for (int j = 0; j < figures[i]->components.size(); j++)
		{

			if (figures[i]!=curentDroping)
			{
				if (figures[i]->components[j]->isAlive)
				{
					board[figures[i]->components[j]->pos.y][figures[i]->components[j]->pos.x] = true;
				}
				
			}
		}
	}
	{
		std::vector<bool> temp(noOfGrid[1],true);
		board.push_back(temp);
	}

	for (int i = 0; i < curentDroping->components.size(); i++)
	{
			if (board[curentDroping->components[i]->pos.y][curentDroping->components[i]->pos.x] == true) {
				return false;
			}
	}

	return true;
	
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