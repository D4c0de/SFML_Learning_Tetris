#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef COMPONENT_H
#define COMPONENT_H
class Component	
{
public:
	Component();
	Component(sf::Texture*,int,int,bool);
	Component(sf::Texture*, int, int);
	~Component();
	bool isCentral;
	sf::Vector2i pos;
	sf::Texture* texture;
	sf::Sprite sprite;
	bool isAlive;
	void move(bool);
	void undoMove(bool);
	void setupTexture();
	void fall();
	void undoFall();
	void rotate(const int,const int);
	void undoRotate(const int, const int);
	sf::Sprite getSprite();
private:

};



#endif