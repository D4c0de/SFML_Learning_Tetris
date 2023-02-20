#include "Component.h"
#include <SFML/Graphics.hpp>

Component::Component() {
	
	color = "red";
	pos.x = 5;
	pos.y = 0;
	setupTexture();
}
Component::Component(const std::string& _color,int posH,int posV)
{
	isCentral = false;
	color = _color;
	pos.x = posH;
	pos.y = posV;

	setupTexture();
	
}
Component::Component(const std::string& _color, int posH, int posV,bool _isCentral)
{
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
sf::Sprite Component::getSprite()
{
	return sprite;
}