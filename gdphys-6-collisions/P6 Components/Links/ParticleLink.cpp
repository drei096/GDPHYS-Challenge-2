#include "ParticleLink.h"

float ParticleLink::getDistance()
{
	PhysVector dist = particles[0]->position - particles[1]->position;
	return dist.magnitude();
}
