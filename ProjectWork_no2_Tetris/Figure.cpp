#include "Figure.h"


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
	if (type=="T")
	{
		central= new Component("red", 4, 0, true);
		components.push_back(new Component("red", 3, 0));
		components.push_back(central);
		components.push_back(new Component("red", 5, 0));
		components.push_back(new Component("red", 4, 1));
		components.push_back(new Component("red", 4, 2));
	}
	else if (type=="I")

	{
		central = new Component("red", 4, 1, true);
		components.push_back(new Component("red", 4, 0));
		components.push_back(central);
		components.push_back(new Component("red", 4, 2));
		components.push_back(new Component("red", 4, 3));
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