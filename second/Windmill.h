#pragma once

#include <box2d/box2d.h>
#include "Box.h"

class Windmill : public sf::Drawable
{
public:
	Windmill(float x, float y, b2World& world);
	void Update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	b2RevoluteJoint* joint = nullptr;
	Box box1;
	Box box2;
};

