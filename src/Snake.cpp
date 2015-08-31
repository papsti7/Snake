#include "Snake.h"


Snake::Snake(sf::RenderWindow& window): mSection{10.f, 10.f}, mLenght(0)//, mVelocity{5.f, 0.f}
{
	//head
	mHead.setFillColor(sf::Color::Green);
	mHead.setSize(mSection);
	mHead.setPosition(window.getSize().x / 2.f - mSection.x / 2.f, window.getSize().y / 2.f - mSection.y / 2.f);
	mBody.push_back(mHead);
	//init bodysection
	mBodySection = getHead();
	mBodySection.setFillColor(sf::Color::Black);
	mBodySection.setOutlineColor(sf::Color::Green);
	mBodySection.setOutlineThickness(-2.f);
	

	
}

/*void Snake::changeVelocity(float x, float y)
{
	mVelocity = { x, y}; 
}*/

void Snake::addSection()
{
	//mBody.push_back()
}

const std::vector<sf::RectangleShape>& Snake::getSnake()
{
	return mBody;
}

/*const sf::Vector2f& Snake::getVelocity()
{
	return mVelocity;
}*/

sf::RectangleShape Snake::getHead()
{
	return mHead;
}

void Snake::setUpMovement()
{
	sf::RectangleShape temp_head;
	temp_head = getHead();
	temp_head.move(0.f, -temp_head.getSize().y);
	mBody.insert(mBody.begin(), temp_head);
	if (mBody.size() > 1)
	{
		mBody.at(1).setFillColor(sf::Color::Black);
		mBody.at(1).setOutlineColor(sf::Color::Green);
		mBody.at(1).setOutlineThickness(-2.f);
	}
	mHead = temp_head;
	mBody.pop_back();
}

void Snake::setDownMovement()
{
	sf::RectangleShape temp_head;
	temp_head = getHead();
	temp_head.move(0.f, temp_head.getSize().y);
	mBody.insert(mBody.begin(), temp_head);
	if (mBody.size() > 1)
	{
		mBody.at(1).setFillColor(sf::Color::Black);
		mBody.at(1).setOutlineColor(sf::Color::Green);
		mBody.at(1).setOutlineThickness(-2.f);
	}
	mHead = temp_head;
	mBody.pop_back();
}

void Snake::setLeftMovement()
{
	sf::RectangleShape temp_head;
	temp_head = getHead();
	temp_head.move(-temp_head.getSize().x, 0.f);
	mBody.insert(mBody.begin(), temp_head);
	if (mBody.size() > 1)
	{
		mBody.at(1).setFillColor(sf::Color::Black);
		mBody.at(1).setOutlineColor(sf::Color::Green);
		mBody.at(1).setOutlineThickness(-2.f);
	}
	mHead = temp_head;
	mBody.pop_back();
}

void Snake::setRightMovement()
{
	sf::RectangleShape temp_head;
	temp_head = getHead();
	temp_head.move(temp_head.getSize().x, 0.f);
	mBody.insert(mBody.begin(), temp_head);
	if (mBody.size() > 1)
	{
		mBody.at(1).setFillColor(sf::Color::Black);
		mBody.at(1).setOutlineColor(sf::Color::Green);
		mBody.at(1).setOutlineThickness(-2.f);
	}
	mHead = temp_head;
	mBody.pop_back();
}