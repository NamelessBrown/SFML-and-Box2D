#pragma once

#include "Box.h"

class Pair : public sf::Drawable
{
public:
	Pair(const Box& box1, const Box& box2, b2World& world);
	Pair(const sf::Vector2f& positionBox1, const sf::Vector2f& sizeBox1, const sf::Vector2f& positionBox2, const sf::Vector2f& sizeBox2,
		b2World& world, b2BodyType type = b2_dynamicBody, sf::Color color = sf::Color::Green);
	void Update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	Box box1;
	Box box2;
	b2DistanceJoint* joint = nullptr;
};

