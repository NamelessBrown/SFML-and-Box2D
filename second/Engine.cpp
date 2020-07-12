#include "Engine.h"
#include <algorithm>

sf::Time Engine::Framerate = sf::seconds(1.f / 60.f);

Engine::Engine()
	:window(sf::VideoMode(1280, 720), "second", sf::Style::Close), world(b2Vec2(0.f, 10.f)), box({ 50.f, 50.f }, {25.f, 25.f}, world),
	groundBox({ 250.f, 700.f }, { 2880.f, 50.f },  world, b2_staticBody)
{
	
}

void Engine::Run()
{
	while (window.isOpen())
	{
		HandleEvents();
		Update(Framerate.asSeconds());
		Render();
	}
}

void Engine::HandleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Color boxColor = { sf::Uint8(rand() % 255), sf::Uint8(rand() % 255), sf::Uint8(rand() % 255), sf::Uint8(255) };
			Box box(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)), { 50.f, 50.f }, world, b2_dynamicBody, boxColor);
			boxes.emplace_back(box);
		}

	}
}

void Engine::Update(float dealtaTime)
{
	world.Step(1 / 60.f, 8, 3);
	box.Update();
	for (auto& box : boxes)
	{
		box.Update();
	}
}

void Engine::Render()
{
	window.clear();
	window.draw(groundBox);
	window.draw(box);

	for (auto& box : boxes)
	{
		window.draw(box);
	}

	window.display();
}
