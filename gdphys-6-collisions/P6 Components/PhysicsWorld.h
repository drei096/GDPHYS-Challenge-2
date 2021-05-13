#pragma once
#include<list>
#include"PhysParticle.h"
#include "ForceRegistry.h"
#include "GravityForceGenerator.h"
#include "Collision/ParticleContact.h"
#include "Collision/ContactResolver.h"
#include <vector>
#include "Links/ParticleLink.h"

using namespace std;

class PhysicsWorld
{
public:
	ForceRegistry registry;
	list <PhysParticle*> particles;
	list <ParticleLink*> links;

	//Change Gravity Value here
	PhysVector gravity = PhysVector(0, 0);  // 20m/s2 down

	vector<ParticleContact*> contacts;

public:
	void addParticle(PhysParticle* particle);
	void update(float time);
	void addContact(PhysParticle* p1, PhysParticle* p2, float restitution, PhysVector collisionNormal);

protected:
	GravityForceGenerator Gravity = GravityForceGenerator();
	void updateParticleList();
	ContactResolver contactResolver = ContactResolver(20);

	void generateContacts();
	void getOverlaps();
};

