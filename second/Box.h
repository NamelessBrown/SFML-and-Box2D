#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Box : public sf::RectangleShape
{
public:
	Box(const sf::Vector2f& position, const sf::Vector2f& size, b2World& world, b2BodyType type = b2_dynamicBody, sf::Color color = sf::Color::Green);
	void Update();
	b2Body& GetBody() const
	{
		return *body;
	}
private:
	b2Body* body = nullptr;
	b2Fixture* fixture = nullptr;
};

