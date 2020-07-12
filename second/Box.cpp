#include "Box.h"
#include "Converter.h"

Box::Box(const sf::Vector2f& position, const sf::Vector2f& size, b2World& world, b2BodyType type, sf::Color color)
{
	setSize(size);
	setPosition(position);
	setOrigin(size / 2.0f);
	setFillColor(color);
	/* First create a body defination */
	b2BodyDef bodyDef;
	bodyDef.type = type;
	bodyDef.position.Set(Converter::PixelsToMeters(position.x), Converter::PixelsToMeters(position.y));
	
	body = world.CreateBody(&bodyDef);
	body->SetUserData(this);
	/* create a polygon shape and make a box */
	b2PolygonShape shape;
	shape.SetAsBox(Converter::PixelsToMeters(size.x / 2.0f), Converter::PixelsToMeters(size.y / 2.0f));
	/* The fixture is for the conection to the shape and the body this is where the physics are set */
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 0.5f;
	fixtureDef.restitution = .7f;
	fixtureDef.friction = 0.5f;

	fixture = body->CreateFixture(&fixtureDef);
}

void Box::Update()
{
	setPosition(Converter::MetersToPixels(body->GetPosition().x), Converter::MetersToPixels(body->GetPosition().y));
	setRotation(Converter::RadiansToDegrees(body->GetAngle()));
}


