#include "Component.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Component::Component() {
	
	color = "red";
	pos.x = 5;
	pos.y = 0;
	isAlive = true;
	setupTexture();

}
Component::Component(const std::string& _color,int posH,int posV)
{
	isAlive = true;
	isCentral = false;
	color = _color;
	pos.x = posH;
	pos.y = posV;

	setupTexture();
	
}
Component::Component(const std::string& _color, int posH, int posV,bool _isCentral)
{
	isAlive = true;
	isCentral = _isCentral;
	color = _color;
	pos.x = posH;
	pos.y = posV;

	setupTexture();

}

Component::~Component()
{

}

void Component::setupTexture()
{
	texture.loadFromFile("img/" + color + ".png");
	sprite.setTexture(texture);
	sprite.setPosition(pos.x * 50, pos.y * 50);
}

void Component::fall() 
{

	pos.y++;
	sprite.setPosition(pos.x*50, pos.y*50);

}
void Component::undoFall()
{

	pos.y--;
	sprite.setPosition(pos.x * 50, pos.y * 50);

}
void Component::move(bool left) {

	if (left)
	{
		pos.x--;
		sprite.setPosition(pos.x * 50, pos.y * 50);
	}
	else
	{
		pos.x++;
		sprite.setPosition(pos.x * 50, pos.y * 50);

	}

}
void Component::undoMove(bool left) {

	if (!left)
	{
		pos.x--;
		sprite.setPosition(pos.x * 50, pos.y * 50);
	}
	else
	{
		pos.x++;
		sprite.setPosition(pos.x * 50, pos.y * 50);

	}

}
void Component::rotate(const int x, const int y) {
	int difx = x - pos.x;
	int dify = y - pos.y;

	if (difx!=0)
	{
		pos.y = y - difx;
		pos.x = x;
	}
	if (dify!=0)
	{
		pos.x = x + dify;
		pos.y = y;
	}
	sprite.setPosition(pos.x * 50, pos.y * 50);
}
void Component::undoRotate(const int x, const int y) {
	int difx = x - pos.x;
	int dify = y - pos.y;

	if (difx != 0)
	{
		pos.y = y + difx;
		pos.x = x;
	}
	if (dify != 0)
	{
		pos.x = x - dify;
		pos.y = y;
	}
	sprite.setPosition(pos.x * 50, pos.y * 50);
}
sf::Sprite Component::getSprite()
{
	return sprite;
}