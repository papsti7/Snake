#include "GameScene.h"
#include <iostream>


GameScene::GameScene(Application& app) : Scene(app), mSnake(getApp().getWindow())
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

void GameScene::update()
{
	


	//calculate current score
	std::stringstream strstring;
	strstring << "Score: " << getApp().getHighscore();
	mHighscore.setString(strstring.str());

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

	//ball clamping of three sides
	/*if (mBall.getPosition().x <= 0.f)
	{
		mBall.setPosition(0.f, mBall.getPosition().y);
		mBallSpeed.x *= -1.f;
	}
	else if (mBall.getPosition().y <= 0.f)
	{
		mBall.setPosition(mBall.getPosition().x, 0.f);
		mBallSpeed.y *= -1.f;
	}
	else if ((mBall.getPosition().x + mBall.getRadius()*2.f) >= getApp().getWindow().getSize().x)
	{
		mBall.setPosition(getApp().getWindow().getSize().x - mBall.getRadius()*2.f, mBall.getPosition().y);
		mBallSpeed.x *= -1.f;
	}
	//ball and bat collision
	else if (((mBall.getPosition().y + mBall.getRadius()*2.f) >= mBat.getPosition().y) && (mBall.getPosition().x >= (mBat.getPosition().x - mBall.getRadius())) && (mBall.getPosition().x <= (mBat.getPosition().x + mBat.getSize().x - mBall.getRadius())))
	{
		mBall.setPosition(mBall.getPosition().x, (mBat.getPosition().y) - mBall.getRadius() * 2.f - 1.f);
		mBallSpeed.y *= -1.f;
	}
	//game over -> new Scene
	else if ((mBall.getPosition().y + mBall.getRadius()*2.f) >= mBat.getPosition().y)
	{
		getApp().setActiveScene(new GameOverScene(getApp()));
	}
	*/
	
	
	
	
	
	
}

void GameScene::render()
{
	for(auto& section: mSnake.getSnake())
		getApp().getWindow().draw(section);
	//getApp().getWindow().draw(mBall);
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