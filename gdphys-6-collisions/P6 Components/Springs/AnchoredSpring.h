#pragma once
#include "../ForceGenerator.h"
#include "../PhysVector.h"
#include "../PhysParticle.h"
class AnchoredSpring : public ForceGenerator
{
private:
	PhysVector anchorPoint;
	float springConstant;
	float restLength;
public:
	AnchoredSpring(PhysVector _pos, float _springConst, float _restLen) :
		anchorPoint(_pos), springConstant(_springConst), restLength(_restLen) {}

	void updateForce(PhysParticle* particle, float time) override;
};

