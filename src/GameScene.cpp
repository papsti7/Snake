#include "GameScene.h"


GameScene::GameScene(Application& app) : Scene(app)
{
	//init Highscore
	getApp().resetHighscore();
	mHighscore.setFont(getApp().getFont());
	mHighscore.setCharacterSize(20);
	mHighscore.setColor(sf::Color(255, 255, 255, 128));
	mHighscore.setPosition(10.f, 10.f);

}

void GameScene::processEvent(const sf::Event& e)
{
	if(e.type == sf::Event::KeyReleased)
	if (e.key.code == sf::Keyboard::Delete)
	{
		getApp().setActiveScene(new GameOverScene(getApp()));
	}
}

void GameScene::update()
{
	//Bat movement
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		mBat.move(-5.f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		mBat.move(5.f, 0.f);
	//bat clamping
	if (mBat.getPosition().x <= 0.f)
		mBat.setPosition(0.f, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));
	else if ((mBat.getPosition().x + mBat.getSize().x) >= getApp().getWindow().getSize().x)
		mBat.setPosition(getApp().getWindow().getSize().x - mBat.getSize().x, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));*/


	//calculate current score
	std::stringstream strstring;
	strstring << "Score: " << getApp().getHighscore();
	mHighscore.setString(strstring.str());

	
	

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
	
	
	//ball movement
	mBall.move(mBallSpeed);*/
	
	
	
}

void GameScene::render()
{
	

	//getApp().getWindow().draw(mBat);
	//getApp().getWindow().draw(mBall);
	//show current score
	getApp().getWindow().draw(mHighscore);
}