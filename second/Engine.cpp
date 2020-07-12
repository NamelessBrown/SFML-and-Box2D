#include "Engine.h"

sf::Time Engine::Framerate = sf::seconds(1.f / 60.f);

Engine::Engine()
	:window(sf::VideoMode(1280, 720), "second", sf::Style::Close), world(b2Vec2(0.f, 10.f)), box({ 50.f, 50.f }, {25.f, 25.f}, world)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = 
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

	}
}

void Engine::Update(float dealtaTime)
{
	world.Step(1 / 60.f, 8, 3);
	box.Update();
}

void Engine::Render()
{
	window.clear();
	box.Draw(window);
	window.display();
}
