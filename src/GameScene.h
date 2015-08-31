#pragma once
#include "Scene.h"
#include "GameOverScene.h"


#include <vector>

class GameScene : public Scene
{
public:
	GameScene(Application& app);

	virtual void processEvent(const sf::Event& e);
	virtual void update();
	virtual void render();



	~GameScene() {}




private:
	
	sf::Text mHighscore;
	
};