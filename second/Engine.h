#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "Pair.h"
#include "Converter.h"
#include "Windmill.h"

class Engine
{
public:
	Engine();
public:
	void Run();
private:
	void HandleEvents();
	void Update(float dealtaTime);
	void Render();
private:
	sf::RenderWindow window;
	sf::Clock clock;
	static sf::Time Framerate;
	b2World world;
	Box box;
	std::vector<Box> boxes;
	std::vector<Pair> pairBoxes;
	Windmill windmill;

	//ground
	Box groundBox;
};

