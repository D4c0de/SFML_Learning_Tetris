#include "GameWorld.h"
#include <SFML/Graphics.hpp>

GameWorld::GameWorld(sf::RenderWindow* _window) {

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