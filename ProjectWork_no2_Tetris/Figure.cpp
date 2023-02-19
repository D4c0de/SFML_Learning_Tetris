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


void Figure::setUpComponent() {

	components.clear();
	if (type=="T")
	{
		components.push_back(new Component("red", 3, 0));
		components.push_back(new Component("red", 4, 0));
		components.push_back(new Component("red", 5, 0));
		components.push_back(new Component("red", 4, 1));
	}
	else if (type=="I")
	{
		components.push_back(new Component("red", 4, 0));
		components.push_back(new Component("red", 4, 1));
		components.push_back(new Component("red", 4, 2));
		components.push_back(new Component("red", 4, 3));
	}
}
std::vector<sf::Sprite>* Figure::getComponet() {

	std::vector<sf::Sprite>* sprite= new std::vector<sf::Sprite>();
	for (int i = 0; i < components.size(); i++)
	{
		 sprite->push_back(components[i]->getSprite());
	}
	return sprite;
}