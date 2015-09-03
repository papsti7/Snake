#pragma once
#include "Application.h"
#include "Random.h"



class Fruit
{
public:
	Fruit(Application& app);
	
	void update(Application& app);

	sf::RectangleShape& getFruit();


private:
	sf::RectangleShape mFruit;
	Random random;


};