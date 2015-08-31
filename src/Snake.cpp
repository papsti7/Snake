#include "Snake.h"


Snake::Snake(sf::RenderWindow& window): mSection{10.f, 7.5f}, mVelocity{5.f, 0.f}
{
	//head
	sf::RectangleShape head;
	head.setFillColor(sf::Color::Green);
	head.setSize(mSection);
	head.setPosition(window.getSize().x / 2.f - mSection.x / 2.f, window.getSize().y / 2.f - mSection.y / 2.f);
	mBody.push_back(head);
	//init bodysection
	head.setFillColor(sf::Color::Black);
	head.setOutlineColor(sf::Color::Green);
	head.setOutlineThickness(-2.f);
	mBodySection = head;

	
}

void Snake::changeVelocity(float x, float y)
{
	mVelocity = { x, y}; 
}

void Snake::addSection()
{
	//mBody.push_back()
}

const std::vector<sf::RectangleShape>& Snake::getSnake()
{
	return mBody;
}

const sf::Vector2f& Snake::getVelocity()
{
	return mVelocity;
}