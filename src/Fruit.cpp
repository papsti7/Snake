#include "Fruit.h"


Fruit::Fruit(Application& app)
{
	mFruit.setFillColor(sf::Color::Red);
	mFruit.setSize(sf::Vector2f(10.f, 10.f));
	mFruit.setPosition(random.getPos(app));
}

void Fruit::update(Application& app)
{
	mFruit.setPosition(random.getPos(app));
}

sf::RectangleShape& Fruit::getFruit()
{
	return mFruit;
}

