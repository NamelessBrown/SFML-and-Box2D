#include "Engine.h"

sf::Time Engine::Framerate = sf::seconds(1.f / 60.f);

Engine::Engine()
	:window(sf::VideoMode(1280, 720), "second", sf::Style::Close), world(b2Vec2(0.f, 10.f)), box({ 50.f, 50.f }, {25.f, 25.f}, world)
{

	sf::Vector2f groundSize{ static_cast<float>(window.getSize().x), 50.f };
	sf::Vector2f groundPosition{ 0.f, 700 };

	ground.setPosition(groundPosition);
	ground.setSize(groundSize);
	ground.setOrigin(groundSize / 2.0f);
	ground.setFillColor(sf::Color::Blue);

	b2BodyDef groundBodyDef;
	groundBodyDef.type = b2_staticBody;
	groundBodyDef.position.Set(Converter::PixelsToMeters(groundPosition.x), Converter::PixelsToMeters(groundPosition.y));

	groundBody = world.CreateBody(&groundBodyDef);
	groundBody->SetUserData(groundBody);

	b2PolygonShape groundShape;
	groundShape.SetAsBox(Converter::PixelsToMeters(groundSize.x / 2.0f), Converter::PixelsToMeters(groundSize.y / 2.0f));

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &groundShape;
	fixtureDef.density = 0.3f;
	fixtureDef.restitution = 0.5f;
	fixtureDef.friction = 0.3f;

	groundFixture = groundBody->CreateFixture(&fixtureDef);

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
	window.draw(ground);
	box.Draw(window);
	window.display();
}
