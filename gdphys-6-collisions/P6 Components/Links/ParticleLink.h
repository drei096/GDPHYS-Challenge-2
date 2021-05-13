#pragma once
#include"../Collision/ParticleContact.h"
#include"../PhysParticle.h"

class ParticleLink
{
public:
	PhysParticle* particles[2];
	virtual ParticleContact* getContact() { return nullptr; }

protected:
	float getDistance();
};

