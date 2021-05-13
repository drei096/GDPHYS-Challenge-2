#pragma once
#include "ForceGenerator.h"
class GravityForceGenerator : public ForceGenerator
{
private:
	PhysVector gravity = PhysVector(0, 0);
public:
	GravityForceGenerator(PhysVector g) : gravity(g) {};
	GravityForceGenerator() {}

	void updateForce(PhysParticle* p, float time) override;
};

