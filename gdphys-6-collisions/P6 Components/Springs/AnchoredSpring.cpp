#include "AnchoredSpring.h"

void AnchoredSpring::updateForce(PhysParticle* particle, float time)
{
	PhysVector pos = particle->position;
	PhysVector force = pos - anchorPoint;
	float mag = force.magnitude();
	float springForce = -springConstant * abs(mag - restLength);

	force.normalize();
	PhysVector dir = force;

	particle->addForce(dir * springForce);
}
