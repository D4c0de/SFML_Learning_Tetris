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
			spawnNewFigure("T");
		}
		
	}
	else if (key == "right")
	{
		curentDroping->move(false);
		if (!colisionDetec())
		{
			curentDroping->undoMove(false);
			spawnNewFigure("T");
		}
	}
	else if (key == "left")
	{
		curentDroping->move(true);
		if (!colisionDetec())
		{
			curentDroping->undoMove(true);
			spawnNewFigure("T");
		}
	}
	else if (key == "up") {
		curentDroping->rotate();
		if (!colisionDetec())
		{
			curentDroping->undoRotate();
			spawnNewFigure("T");
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
				board[figures[i]->components[j]->pos.y][figures[i]->components[j]->pos.x] = true;
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