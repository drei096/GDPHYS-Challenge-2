#pragma once
#include "PhysParticle.h"

class ForceGenerator
{
public:
	virtual void updateForce(PhysParticle *p, float time)
	{
		p->addForce(PhysVector(0, 0));
	}
};

