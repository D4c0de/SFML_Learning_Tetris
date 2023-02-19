#include "figure.h"
#include <vector>


#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{
public:

	GameWorld(sf::RenderWindow*);
	~GameWorld();

	sf::RenderWindow* window;
	std::vector<Figure*> figures;
	Figure* curentDroping=NULL;
	void spawnNewFigure(std::string);
	void draw();

private:

};


#endif
