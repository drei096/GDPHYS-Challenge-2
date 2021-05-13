#include "DragForceGenerator.h"

void DragForceGenerator::updateForce(PhysParticle* p, float time)
{
	PhysVector force = PhysVector(0,0);

	PhysVector currV = p->velocity;
	float mag = currV.magnitude();
	float dragF = (k1 * mag) + (k2 * mag * mag);

	currV.normalize();
	PhysVector dir = currV;

	p->addForce(dir * (-dragF));
}
