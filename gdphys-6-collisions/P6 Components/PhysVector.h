#pragma once
#include <cmath>
class PhysVector
{
public:
	float x;
	float y;

public:
	float magnitude();
	PhysVector direction();
	PhysVector operator*(const float f); //A*Bx
	PhysVector operator+(PhysVector b); //A+B
	PhysVector operator-(PhysVector b); //A-B
	PhysVector operator*(PhysVector b); //Component Product of A and B
	PhysVector crossProduct(PhysVector a, PhysVector b);
	float dotProduct(PhysVector a, PhysVector b);
	float operator*=(const PhysVector v); //dot prod alt
	float magnitudeSquared();
	float getDistanceBetweenPoints(PhysVector a, PhysVector b);
	
	void normalize();

	PhysVector(float xIn, float yIn);
};

