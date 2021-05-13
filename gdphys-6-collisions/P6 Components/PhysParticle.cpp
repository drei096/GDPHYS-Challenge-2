#include "PhysParticle.h"
#include "../Utils.h"
#include <iostream>
using namespace std;

void PhysParticle::update(float time)
{
	if (mass == 0)
	{
		return;
	}
	updatePos(time);
	updateVelocity(time);
	//updateDestroyed();
	resetForce();
}

void PhysParticle::updatePos(float time)
{
	position = position + (velocity * time) + ((acceleration * powf(time, 2)) * (1 / 2));
}

void PhysParticle::updateVelocity(float time)
{
	//setting acceleration
	acceleration = acceleration + accumulatedForce * (1 / mass);

	velocity = velocity + acceleration * time;
	//velocity with damping
	velocity = velocity * powf(damping, time);

	//calculate total velocity over the sim
	totalVelocity = totalVelocity + velocity;
}

/*
void PhysParticle::updateDestroyed()
{
	//Change Particle Destructor here after the question mark
	if (timer.getElapsedTime().asSeconds() >= (rand() % 2 == 0 ? 0.5 : 1))
	{
		setIsDestroyed();
	}
}
*/

float PhysParticle::measureTime()
{
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	return elapsed.asSeconds() * 1000;
}

bool PhysParticle::getIsDestroyed()
{
	return isDestroyed;
}

void PhysParticle::setIsDestroyed()
{
	isDestroyed = true;
}

void PhysParticle::addForce(PhysVector f)
{
	accumulatedForce = accumulatedForce + f;
}

void PhysParticle::resetForce()
{
	accumulatedForce = PhysVector(0, 0);
	acceleration = PhysVector(0, 0);
}

PhysParticle::PhysParticle()
{
}

PhysVector PhysParticle::toRenderPoint()
{
	return Utils::p6ToSFMLPoint(position);
}






