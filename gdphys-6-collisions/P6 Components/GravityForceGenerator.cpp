#include "GravityForceGenerator.h"

void GravityForceGenerator::updateForce(PhysParticle* p, float time)
{
	if (p->mass <= 0)
	{
		return;
	}

	PhysVector force = gravity * p->mass;
	p->addForce(force);
}
