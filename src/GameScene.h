#pragma once
#include "Scene.h"
#include "GameOverScene.h"
#include "Snake.h"
#include "Fruit.h"


#include <vector>

enum DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};


class GameScene : public Scene
{
public:
	GameScene(Application& app);

	virtual void processEvent(const sf::Event& e);
	virtual void update(const sf::Time& deltaTime);
	virtual void render();



	~GameScene() {}




private:
	Snake mSnake;
	Fruit mFruit;
	sf::Text mHighscore;

	void setDirectionActive(unsigned newDirection);

	bool mUp;
	bool mDown;
	bool mLeft;
	bool mRight;

	sf::Time mTimeSinceLastJump;	
};