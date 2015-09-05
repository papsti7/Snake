#include "Snake.h"


Snake::Snake(sf::RenderWindow& window): mSection{10.f, 10.f}, mLenght(0), mGrowing(false)
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
	addSection();
	addSection();
	addSection();
	

	
}

/*void Snake::changeVelocity(float x, float y)
{
	mVelocity = { x, y}; 
}*/

void Snake::addSection()
{
	mBodySection.setPosition(getLastPos());
	mBody.push_back(mBodySection);
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
	if (!mGrowing)
	{
		mBody.pop_back();
	}
	else if (mGrowing)
	{
		mGrowing = false;
	}
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
	if (!mGrowing)
	{
		mBody.pop_back();
	}
	else if (mGrowing)
	{
		mGrowing = false;
	}
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
	if (!mGrowing)
	{
		mBody.pop_back();
	}
	else if (mGrowing)
	{
		mGrowing = false;
	}
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
	if (!mGrowing)
	{
		mBody.pop_back();
	}
	else if (mGrowing)
	{
		mGrowing = false;
	}
}

sf::Vector2f Snake::getLastPos()
{
	sf::RectangleShape temp_rect = mBody.back();
	
	return{ temp_rect.getPosition().x + 10.f, temp_rect.getPosition().y };
}

bool Snake::checkCollisionWithItself()
{
	for (auto& it = mBody.begin() + 1; it != mBody.end(); it++)
		if(mHead.getGlobalBounds().intersects(it->getGlobalBounds()))
			return true;
	
	return false;
}