#include "PhysicsWorld.h"

void PhysicsWorld::addParticle(PhysParticle* particle)
{
	particles.push_back(particle);
	//registry.add(particle, &Gravity);
}

void PhysicsWorld::update(float time)
{
	updateParticleList();
	registry.updateForce(time);

	for (list<PhysParticle*>::iterator i = particles.begin(); i != particles.end(); i++)
	{
		//(*i)->acceleration = gravity;
		(*i)->update(time);
	}

	generateContacts(); 

	if (contacts.size() > 0)
	{
		contactResolver.max_iterations = contacts.size() * 2;
		contactResolver.resolveContacts(contacts, time);
	}
}

void PhysicsWorld::addContact(PhysParticle* p1, PhysParticle* p2, float restitution, PhysVector collisionNormal)
{
	ParticleContact* toAdd = new ParticleContact();

	toAdd->particles[0] = p1;
	toAdd->particles[1] = p2;
	toAdd->restitution = restitution;
	toAdd->collisonNormal = collisionNormal;

	contacts.push_back(toAdd);
}

void PhysicsWorld::updateParticleList()
{
	particles.remove_if(
		[](PhysParticle* p)
		{
			return p->getIsDestroyed();
		}
	);
}

void PhysicsWorld::generateContacts()
{
	contacts.clear();
	getOverlaps();

	for (list<ParticleLink*>::iterator i = links.begin(); i != links.end(); i++)
	{
		ParticleContact* contact = (*i)->getContact();
		if (contact != nullptr)
		{
			contacts.push_back(contact);
		}
	}
}

void PhysicsWorld::getOverlaps()
{
	for (int i = 0; i < particles.size() - 1; i++)
	{
		list<PhysParticle*>::iterator a = next(particles.begin(), i);

		for (int h = i + 1; h < particles.size(); h++)
		{
			list<PhysParticle*>::iterator b = next(particles.begin(), h);

			float mag2 = ((*a)->position - (*b)->position).magnitudeSquared();
			float rad2 = ((*a)->radius + (*b)->radius) * ((*a)->radius + (*b)->radius);

			if (mag2 <= rad2)
			{
				PhysVector dir = (*a)->position - (*b)->position;
				dir.normalize();
				float r = rad2 - mag2;
				float depth = sqrt(r);

				float restitution = (*a)->restitution;
				if ((*b)->restitution < restitution)
					restitution = (*b)->restitution;

				addContact(*a, *b, restitution, dir);
			}
		}
	}
}


