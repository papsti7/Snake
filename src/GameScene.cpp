#include "GameScene.h"
#include <iostream>


GameScene::GameScene(Application& app) : Scene(app), mSnake(getApp().getWindow()), mFruit(getApp()), mTimeSinceLastJump(sf::Time::Zero)
{
	//init Highscore
	getApp().resetHighscore();
	mHighscore.setFont(getApp().getFont());
	mHighscore.setCharacterSize(20);
	mHighscore.setColor(sf::Color(255, 255, 255, 128));
	mHighscore.setPosition(10.f, 10.f);

	setDirectionActive(RIGHT);
	

}

void GameScene::processEvent(const sf::Event& e)
{
	if(e.type == sf::Event::KeyPressed)
		switch (e.key.code)
		{
		case sf::Keyboard::Up:
			setDirectionActive(UP);
			//std::cout << "UP" << std::endl;
			break;
		case sf::Keyboard::Down:
			setDirectionActive(DOWN);
			//std::cout << "Down" << std::endl;
			break;
		case sf::Keyboard::Left:
			setDirectionActive(LEFT);
			//std::cout << "Left" << std::endl;
			break;
		case sf::Keyboard::Right:
			setDirectionActive(RIGHT);
			//std::cout << "Right" << std::endl;
			break;
		default:
			break;
		}
		
}

void GameScene::update(const sf::Time& deltaTime)
{
	const sf::Time jumpIntervall(sf::seconds(0.05f));
	
	mTimeSinceLastJump += deltaTime;
	
	while(mTimeSinceLastJump >= jumpIntervall)
	{
		mTimeSinceLastJump -= jumpIntervall;
		
		//snake movement
		if (mUp)
		{
			mSnake.setUpMovement();
		}
		else if (mDown)
		{
			mSnake.setDownMovement();
		}
		else if (mLeft)
		{
			mSnake.setLeftMovement();
		}
		else if (mRight)
		{
			mSnake.setRightMovement();
		}

		if (mSnake.getHead().getGlobalBounds().intersects(mFruit.getFruit().getGlobalBounds()))
		{
			getApp().increaseHighscore();
			mFruit.update(getApp());
			mSnake.addSection();
		}

	}
	
	

	//calculate current score
	std::stringstream strstring;
	strstring << "Score: " << getApp().getHighscore();
	mHighscore.setString(strstring.str());



	//check game over(without collision with itself)

	if (mSnake.getHead().getPosition().x <= 0 || mSnake.getHead().getPosition().y <= 0 ||
		mSnake.getHead().getPosition().x + 10 >= getApp().getWindow().getSize().x ||
		mSnake.getHead().getPosition().y + 10 >= getApp().getWindow().getSize().y)
		getApp().setActiveScene(new GameOverScene(getApp()));
	
	
	
	
}

void GameScene::render()
{
	for(auto& section: mSnake.getSnake())
		getApp().getWindow().draw(section);

	getApp().getWindow().draw(mFruit.getFruit());
	//show current score
	getApp().getWindow().draw(mHighscore);
}

void GameScene::setDirectionActive(unsigned newDirection)
{
	switch (newDirection)
	{
	case UP:
		mUp = true;
		mDown = false;
		mLeft = false;
		mRight = false;
		break;
	case DOWN:
		mUp = false;
		mDown = true;
		mLeft = false;
		mRight = false;
		break;
	case LEFT:
		mUp = false;
		mDown = false;
		mLeft = true;
		mRight = false;
		break;
	case RIGHT:
		mUp = false;
		mDown = false;
		mLeft = false;
		mRight = true;
		break;
	default:
		break;
	}
}