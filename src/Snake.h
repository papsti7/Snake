#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

#include "Application.h"

class Snake
{
public:
	Snake(sf::RenderWindow& window);
	
	//void changeVelocity(float x, float y);
	void addSection();

	const std::vector<sf::RectangleShape>& getSnake();
	//const sf::Vector2f& getVelocity();
	sf::RectangleShape getHead();

	void setUpMovement();
	void setDownMovement();
	void setLeftMovement();
	void setRightMovement();

private:
	unsigned mLenght;
	sf::Vector2f mSection;
	//
	sf::RectangleShape mHead;
	//body
	std::vector<sf::RectangleShape> mBody;
	sf::RectangleShape mBodySection;

};