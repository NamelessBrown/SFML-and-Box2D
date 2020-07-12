#include "Box.h"
#include "Converter.h"

Box::Box(const sf::Vector2f& position, const sf::Vector2f& size, b2World& world, b2BodyType type, sf::Color color)
{
	setSize(size);
	setPosition(position);
	setOrigin(size / 2.0f);
	setFillColor(color);

	b2BodyDef bodyDef;
	bodyDef.type = type;
	bodyDef.position.Set(Converter::PixelsToMeters(position.x), Converter::PixelsToMeters(position.y));
	
	body = world.CreateBody(&bodyDef);
	body->SetUserData(this);

	b2PolygonShape shape;
	shape.SetAsBox(Converter::PixelsToMeters(size.x / 2.0f), Converter::PixelsToMeters(size.y / 2.0f));

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 0.3f;
	fixtureDef.restitution = 1.f;
	fixtureDef.friction = 0.3f;

	fixture = body->CreateFixture(&fixtureDef);
}

void Box::Update()
{
	setPosition(Converter::MetersToPixels(body->GetPosition().x), Converter::MetersToPixels(body->GetPosition().y));
	setRotation(Converter::RadiansToDegrees(body->GetAngle()));
}


