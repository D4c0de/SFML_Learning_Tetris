#include "Component.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Component::Component() {
	
	pos.x = 5;
	pos.y = 0;
	isAlive = true;
	setupTexture();

}
Component::Component(sf::Texture* _texture,int posH,int posV)
{
	isAlive = true;
	isCentral = false;
	texture = _texture;
	pos.x = posH;
	pos.y = posV;

	setupTexture();
	
}
Component::Component(sf::Texture* _texture, int posH, int posV,bool _isCentral)
{
	isAlive = true;
	texture = _texture;
	isCentral = _isCentral;
	pos.x = posH;
	pos.y = posV;

	setupTexture();

}

Component::~Component()
{

}

void Component::setupTexture()
{
	sprite.setTexture(*texture);
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
	int posx = pos.x;
	int posy = pos.y;
	if (difx != 0)
	{
		pos.y = y - difx;
		
	}
	else
	{
		pos.y = y;
	}
	if (dify != 0) {
		
		pos.x = x + dify;
	}
	else
	{
		pos.x = x;
	}
	sprite.setPosition(pos.x * 50, pos.y * 50);
}
void Component::undoRotate(const int x, const int y) {
	int difx = x - pos.x;
	int dify = y - pos.y;
	int posx = pos.x;
	int posy = pos.y;

	if (difx != 0)
	{
		pos.y = y + difx;

	}
	else
	{
		pos.y = y;
	}
	if (dify != 0) {

		pos.x = x - dify;
	}
	else
	{
		pos.x = x;
	}
	sprite.setPosition(pos.x * 50, pos.y * 50);
}
sf::Sprite Component::getSprite()
{
	return sprite;
}