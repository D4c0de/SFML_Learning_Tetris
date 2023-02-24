#include "Figure.h"
#include <cstdlib>

Figure::Figure(const std::string& _type)
{
	type = _type;
	setUpComponent();
}


Figure::~Figure()
{
	for (int i = 0; i < components.size(); i++)
	{
			delete components[i];
	}
}

void Figure::fall() {

	for (int i = 0; i < components.size(); i++)
	{
		components[i]->fall();
	}
}
void Figure::fall(int posy)
{

	
	for (int i = 0; i < components.size(); i++)
	{
		
		if (components[i]->pos.y < posy) {
			components[i]->fall();
		}
	}
}
void Figure::undoFall() {

	for (int i = 0; i < components.size(); i++)
	{
		components[i]->undoFall();
	}
}

void Figure::move(bool left) {

	for (int i = 0; i < components.size(); i++)
	{
		components[i]->move(left);
	}
}
void Figure::undoMove(bool left) {

	for (int i = 0; i < components.size(); i++)
	{
		components[i]->undoMove(left);
	}
}
void Figure::setUpComponent() {

	std::vector<Component*> part;
	sf::Texture* texture = new sf::Texture();
	setUpColor();
	texture->loadFromFile("img/" + color + ".png");
	if (type=="T")
	{
		central= new Component(texture, 4, 0, true);
		components.push_back(new Component(texture, 3, 0));
		components.push_back(central);
		components.push_back(new Component(texture, 5, 0));
		components.push_back(new Component(texture, 4, 1));
	}
	else if (type=="I")

	{
		central = new Component(texture, 4, 1, true);
		components.push_back(new Component(texture, 4, 0));
		components.push_back(central);
		components.push_back(new Component(texture, 4, 2));
		components.push_back(new Component(texture, 4, 3));
	}
	else if (type=="Z")
	{
		central = new Component(texture, 4, 1, true);
		components.push_back(new Component(texture, 3, 1));
		components.push_back(central);
		components.push_back(new Component(texture, 4, 2));
		components.push_back(new Component(texture, 5, 2));
	}
	else if (type == "O")
	{
		central = new Component(texture, 4, 1, true);
		components.push_back(new Component(texture, 3, 1));
		components.push_back(central);
		components.push_back(new Component(texture, 4, 2));
		components.push_back(new Component(texture, 3, 2));
	}
	else if (type == "S")
	{
		central = new Component(texture, 4, 1, true);
		components.push_back(new Component(texture, 5, 1));
		components.push_back(central);
		components.push_back(new Component(texture, 4, 2));
		components.push_back(new Component(texture, 3, 2));
	}
	else if (type == "L")
	{
		central = new Component(texture, 4, 2, true);
		components.push_back(new Component(texture, 4, 1));
		components.push_back(central);
		components.push_back(new Component(texture, 5, 3));
		components.push_back(new Component(texture, 4, 3));
	}
	else if (type == "J")
	{
		central = new Component(texture, 4, 2, true);
		components.push_back(new Component(texture, 4, 1));
		components.push_back(central);
		components.push_back(new Component(texture, 4, 3));
		components.push_back(new Component(texture, 3, 3));
	}
}
void Figure::setUpColor()
{
	int r = rand() % 4 + 1;
	switch (r)
	{
	case(1):
		color = "red";
		break;
	case(2):
		color = "blue";
		break;
	case(3):
		color = "green";
		break;
	case(4):
		color = "pink";
		break;
	}

}
std::vector<sf::Sprite>* Figure::getComponet() {

	std::vector<sf::Sprite>* sprite= new std::vector<sf::Sprite>();
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->isAlive)
		{
			sprite->push_back(components[i]->getSprite());

		}
		
		
	}
	return sprite;
}


void Figure::rotate() {
	if (type=="o")
	{
		return;
	}
	const int centalHor = central->pos.x;
	const int centralVec = central->pos.y;

	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]!=central)
		{
			components[i]->rotate(centalHor, centralVec);
		}
		
	}

}
void Figure::undoRotate() {
	if (type == "o")
	{
		return;
	}
	const int centalHor = central->pos.x;
	const int centralVec = central->pos.y;

	for (int i = 0; i < components.size(); i++)
	{
		if (components[i] != central)
		{
			components[i]->undoRotate(centalHor, centralVec);
		}

	}

}