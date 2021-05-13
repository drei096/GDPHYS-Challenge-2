#include "PhysVector.h"

float PhysVector::magnitude()
{
	return sqrt((x * x) + (y * y));
}

PhysVector PhysVector::direction()
{

	PhysVector result = PhysVector(0, 0);
	float magnit;

	magnit = magnitude();
	result.x = x / magnit;
	result.y = y / magnit;

	return result;
}


PhysVector PhysVector::operator*(const float f) //A*Bx
{
	PhysVector result = PhysVector(0, 0);
	result.x = x * f;
	result.y = y * f;
	return result;
}

PhysVector PhysVector::operator+(PhysVector b) //A+B
{
	PhysVector result = PhysVector(0, 0);
	result.x = x + b.x;
	result.y = y + b.y;
	return result;
}

PhysVector PhysVector::operator-(PhysVector b) //A-B
{
	PhysVector result = PhysVector(0, 0);
	result.x = x - b.x;
	result.y = y - b.y;
	return result;
}

PhysVector PhysVector::operator*(PhysVector b) //Compo prod
{
	PhysVector result = PhysVector(0, 0);
	result.x = x * b.x;
	result.y = y * b.y;
	return result;
}

PhysVector PhysVector::crossProduct(PhysVector a, PhysVector b)
{
	PhysVector result = PhysVector(0, 0);

	result.x = (a.y * 0) - (0 * b.y);
	result.y = (0 * b.x) - (a.x * 0);

	return result;
}

float PhysVector::dotProduct(PhysVector a, PhysVector b)
{
	float result;

	result = (a.x * b.x) + (a.y * b.y);

	return result;
}

float PhysVector::operator*=(const PhysVector v)
{
	return this->x * v.x + this->y * v.y;
}

float PhysVector::magnitudeSquared()
{
	return pow(magnitude(), 2);
}

float PhysVector::getDistanceBetweenPoints(PhysVector a, PhysVector b)
{
	return sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
}

void PhysVector::normalize()
{
	//PhysVector result = PhysVector(0, 0);

	float mag = this->magnitude();

	this->x = x / mag;
	this->y = y / mag;
	
}

PhysVector::PhysVector(float xIn, float yIn)
{
	x = xIn;
	y = yIn;
}





