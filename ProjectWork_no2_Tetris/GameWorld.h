#include "figure.h"
#include <vector>


#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{
public:
	GameWorld(sf::RenderWindow*);
	GameWorld(int,int,sf::RenderWindow*);
	~GameWorld();
	int noOfGrid[2];
	sf::RenderWindow* window;
	std::vector<Figure*> figures;
	Figure* curentDroping=NULL;
	void spawnNewFigure(std::string);
	void fall();
	void draw();
	void keyPressed(const std::string&);
	bool colisionDetec();
	void lainDeleter();
private:

};


#endif
