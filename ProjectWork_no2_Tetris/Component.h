#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef COMPONENT_H
#define COMPONENT_H
class Component	
{
public:
	Component();
	Component(const std::string&,int,int,bool);
	Component(const std::string&, int, int);
	~Component();
	bool isCentral;
	sf::Vector2i pos;
	std::string color;
	sf::Texture texture;
	sf::Sprite sprite;
	void move(bool);
	void setupTexture();
	void fall();
	sf::Sprite getSprite();
private:

};



#endif