#include "Utils.h"

PhysVector Utils::offset = PhysVector(0, 0);

void Utils::displayStats(vector<PhysParticle> orderedFinish, int totalUpdateCalls)
{
	int i;
	string placements[3] = { "1st","2nd","3rd" };

	for (i = 0; i < orderedFinish.size(); i++)
	{
		cout << orderedFinish[i].name << " " << placements[i] << endl;
		cout << "Mag. of Velocity at finish line: " << orderedFinish[i].velocity.magnitude() << " m/s" << endl;

		cout << "Ave. Velocity in the last 500m: (" << fixed << setprecision(2) <<
			orderedFinish[i].totalVelocity.x / float(totalUpdateCalls)
			<< "," << orderedFinish[i].totalVelocity.y / (float)totalUpdateCalls << ") m/s" << endl;

		cout << orderedFinish[i].timer.getElapsedTime().asSeconds() << "secs" << endl << endl;
	}

}

void Utils::displayDistanceTravelled(PhysParticle p)
{
	PhysVector result = PhysVector(0, 0);

	result = result + (p.position - p.initialPos);
	cout << result.x << "m" << endl;
}

PhysVector Utils::p6ToSFMLPoint(PhysVector v)
{
	PhysVector ret = PhysVector(v.x, -v.y);
	return ret + offset;
}


