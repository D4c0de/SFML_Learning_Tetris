#include "GameWorld.h"
#include <SFML/Graphics.hpp>

GameWorld::GameWorld(sf::RenderWindow* _window) {

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
		for (int i = 0; i < curentDroping->components.size(); i++)
		{
			curentDroping->components[i]->fall();
		}
		colisionDetec();
	}
	else if (key == "right")
	{

		for (int i = 0; i < curentDroping->components.size(); i++)
		{
			curentDroping->components[i]->move(false);
		}
		colisionDetec();
	}
	else if (key == "left")
	{
		
		for (int i = 0; i < curentDroping->components.size(); i++)
		{
			curentDroping->components[i]->move(true);
		}
		colisionDetec();
	}
}

bool GameWorld::colisionDetec() {

	std::vector<std::vector<bool>> board(noOfGrid[0],std::vector<bool>(noOfGrid[1],false));
	for (int i = 0; i < figures.size(); i++)
	{
		for (int j = 0; j < figures[i]->components.size(); j++)
		{
			board[figures[i]->components[j]->pos.x][figures[i]->components[j]->pos.y] = true;
		}
	}

}