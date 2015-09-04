#include "Application.h"
#include "Scene.h"

#include <SFML/System/Clock.hpp>

Application::~Application()
{
	if(mActiveScene)
		delete mActiveScene;
}

Application::Application() : mActiveScene(nullptr), mWindow(sf::VideoMode(800,600), "Snake"), mHighscore(0)
{
	mWindow.setVerticalSyncEnabled(true);
	mWindow.setFramerateLimit(20);
	mFont.loadFromFile("D:/Programmieren/Snake/data/VideoPhreak.ttf");
}

void Application::setActiveScene(Scene* ptr)
{
	if (mActiveScene)
		delete mActiveScene;
	mActiveScene = ptr;
}

void Application::run()
{
	sf::Clock frameTimer;
	sf::Time deltaTime = sf::Time::Zero;
	
	while (mWindow.isOpen())
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			processEvent(event);
		}
		update(deltaTime);
		render();
		//Get frametime
		deltaTime = frameTimer.restart();
	}
}

void Application::processEvent(const sf::Event& e)
{
	if (e.type == sf::Event::Closed)
		mWindow.close();

	if (mActiveScene)
		mActiveScene->processEvent(e);
}

void Application::update(const sf::Time& deltaTime)
{
	if (mActiveScene)
		mActiveScene->update(deltaTime);
}

void Application::render()
{
	mWindow.clear(sf::Color::Black);

	if (mActiveScene)
		mActiveScene->render();

	mWindow.display();
}