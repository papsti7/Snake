#pragma once
#include "Scene.h"
#include "GameScene.h"

class IntroScene : public Scene
{
public:
	IntroScene(Application& app);

	virtual void processEvent(const sf::Event& e);
	virtual void update(const sf::Time& time);
	virtual void render();


	
	~IntroScene() {}


	

private:
	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSpr;
	




};