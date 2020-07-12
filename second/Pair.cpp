#include "Pair.h"
#include "Converter.h"

Pair::Pair(const Box& box1, const Box& box2, b2World& world)
	:box1(box1), box2(box2)
{
	float lenght = 15.f;

	b2DistanceJointDef jointDef;
	jointDef.bodyA = &this->box1.GetBody();
	jointDef.bodyB = &this->box2.GetBody();
	jointDef.type = b2JointType::e_distanceJoint;
	jointDef.userData = this;

	jointDef.length = Converter::PixelsToMeters(lenght);
	jointDef.frequencyHz = 1.f;
	jointDef.dampingRatio = 0.8f;

	joint = (b2DistanceJoint*)world.CreateJoint(&(const b2JointDef)jointDef);

}

Pair::Pair(const sf::Vector2f& positionBox1, const sf::Vector2f& sizeBox1, const sf::Vector2f& positionBox2, const sf::Vector2f& sizeBox2, b2World& world, b2BodyType type, sf::Color color)
	:box1(positionBox1, sizeBox1, world, type, color), box2( positionBox2, sizeBox2, world, type, color)
{

	float lenght = 15.f;

	b2DistanceJointDef jointDef;
	jointDef.bodyA = &this->box1.GetBody();
	jointDef.bodyB = &this->box2.GetBody();
	jointDef.type = b2JointType::e_distanceJoint;
	jointDef.userData = this;

	jointDef.length = Converter::PixelsToMeters(lenght);
	jointDef.frequencyHz = 1.f;
	jointDef.dampingRatio = 1.f;

	joint = (b2DistanceJoint*)world.CreateJoint(&(const b2JointDef)jointDef);
}

void Pair::Update()
{
	box1.Update();
	box2.Update();
}

void Pair::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box1);
	target.draw(box2);
}
