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

	std::vector<Component*> part;
	if (type=="T")
	{
		central= new Component("red", 4, 0, true);
		components.push_back(new Component("red", 3, 0));
		components.push_back(central);
		components.push_back(new Component("red", 5, 0));
		components.push_back(new Component("red", 4, 1));
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

		sprite->push_back(components[i]->getSprite());
		
	}
	return sprite;
}


void Figure::rotate(bool left) {
	
	const int centalHor = central->pos.x;
	const int centralVec = central->pos.y;
	if (left)
	{
		for (int i = 0; i < components.size(); i++)
		{
			if (!components[i]->isCentral) {


			}
		}
	}
	else
	{

	}


}