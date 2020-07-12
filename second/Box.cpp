#include "Box.h"
#include "Converter.h"

Box::Box(const sf::Vector2f& position, const sf::Vector2f& size, b2World& world)
{
	rectShape.setSize(size);
	rectShape.setPosition(position);
	rectShape.setOrigin(size / 2.0f);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(Converter::PixelsToMeters(position.x), Converter::PixelsToMeters(position.y));
	
	body = world.CreateBody(&bodyDef);
	body->SetUserData(this);

	b2PolygonShape shape;
	shape.SetAsBox(Converter::PixelsToMeters(size.x / 2.0f), Converter::PixelsToMeters(size.y / 2.0f));

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 0.3f;
	fixtureDef.restitution = 0.5f;
	fixtureDef.friction = 0.3f;

	fixture = body->CreateFixture(&fixtureDef);
}

void Box::Update()
{
	rectShape.setPosition(Converter::MetersToPixels(body->GetPosition().x), Converter::MetersToPixels(body->GetPosition().y));
	rectShape.setRotation(Converter::RadiansToDegrees(body->GetAngle()));
}

void Box::Draw(sf::RenderTarget& target)
{
	target.draw(rectShape);
}
