#pragma once
#include "../ForceGenerator.h"
#include "../PhysVector.h"
#include "../PhysParticle.h"
class BungeeSpring : public ForceGenerator
{
private:
	PhysVector anchorPoint;
	float springConstant;
	float bungeeLength;

public:
	BungeeSpring(PhysVector _pos, float _springConst, float _restLen) :
		anchorPoint(_pos), springConstant(_springConst), bungeeLength(_restLen) {}

	void updateForce(PhysParticle* particle, float time) override;
};

