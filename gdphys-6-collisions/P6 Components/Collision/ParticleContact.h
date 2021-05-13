#pragma once
#include "../PhysParticle.h"
class ParticleContact
{
public:
	PhysParticle* particles[2];
	float restitution;
	PhysVector collisonNormal = PhysVector(0,0);
	float depth = 0;

public:
	ParticleContact();
	void resolve(float time);
	float getSeparatingSpeed();
	void resolveInterpenetration(float time);

protected:
	void resolveVelocity(float time);
};

