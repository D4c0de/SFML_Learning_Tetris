#include <iostream>
#include "component.h"
#include <vector>

#ifndef FIGURES_H
#define FIGURES_H

class Figure
{
public:
	Figure(const std::string&);
	~Figure();

	std::string type;

	std::vector<Component*> components;
	Component* central;
	std::vector<sf::Sprite>* getComponet();
	void setUpComponent();
	void rotate(bool);

private:

};

#endif 