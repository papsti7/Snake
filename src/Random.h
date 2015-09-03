#pragma once

#include <random>
#include <chrono>

#include "Application.h"

using namespace std::chrono;

class Random
{
public:
	sf::Vector2f getPos(Application& app)
	{
		// Use time for the random seed, nanoseconds should be enough precision
		auto time = duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
		//Init random engine with the time as seed (fixed value during debugging to have the same value
		//each run)
		std::default_random_engine engine(time);
		//Real distribution for floating numbers
		std::uniform_real_distribution<float> float_dist_x(10.f, app.getWindow().getSize().x - 10.f);
		std::uniform_real_distribution<float> float_dist_y(10.f, app.getWindow().getSize().y - 10.f);

		sf::Vector2f random_pos = {float_dist_x(engine), float_dist_y(engine)};

		return random_pos;
	}
};