#include "Windmill.h"
#include "Converter.h"

Windmill::Windmill(float x, float y, b2World& world)
	:box1({ x, y - 20.f }, { 120.f, 10.f }, world, b2_dynamicBody), box2({x, y}, {10.f, 40.f}, world, b2_dynamicBody)
{
	b2RevoluteJointDef jointDef;
	jointDef.Initialize(&box1.GetBody(), &box2.GetBody(), box1.GetBody().GetWorldCenter());

	jointDef.motorSpeed = Converter::DegreesToRadians(25.f);
	jointDef.maxMotorTorque = 1000.f;
	jointDef.enableMotor = true;
	jointDef.userData = this;
	jointDef.type = b2JointType::e_revoluteJoint;

	joint = (b2RevoluteJoint*)world.CreateJoint(&(const b2JointDef)jointDef);
	joint->EnableMotor(true);
	joint->SetUserData(this);
	
}


void Windmill::Update()
{
	box1.Update();
	box2.Update();
}

void Windmill::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box1);
	target.draw(box2);
}
