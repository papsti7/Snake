#pragma once
#include "Scene.h"
#include "GameOverScene.h"
#include "Snake.h"


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
	virtual void update();
	virtual void render();



	~GameScene() {}




private:
	Snake mSnake;
	sf::Text mHighscore;

	void setDirectionActive(unsigned newDirection);

	bool mUp;
	bool mDown;
	bool mLeft;
	bool mRight;

	
};