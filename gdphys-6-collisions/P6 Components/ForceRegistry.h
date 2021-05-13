#pragma once
#include "PhysParticle.h"
#include "ForceGenerator.h"
#include <list>

using namespace std;

class ForceRegistry
{
protected:
	struct ParticleGeneratorPair
	{
		PhysParticle* particle;
		ForceGenerator* generator;
	};

	list <ParticleGeneratorPair> registry;

public:
	void add(PhysParticle* particle, ForceGenerator* generator);
	void remove(PhysParticle* particle, ForceGenerator* generator);
	void clear();
	void updateForce(float time);

};

