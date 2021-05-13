#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "P6 components/PhysVector.h"
#include "P6 components/PhysParticle.h"
#include "Utils.h"
#include "P6 components/PhysicsWorld.h"
#include "P6 Components/DragForceGenerator.h"
#include "P6 Components/ForceGenerator.h"
#include "P6 Components/ForceRegistry.h"
#include "P6 Components/GravityForceGenerator.h"
#include "P6 Components/Springs/AnchoredSpring.h"
#include "P6 Components/Springs/BungeeSpring.h"
#include "P6 Components/Collision/ParticleContact.h"


#define PI 3.14159

using namespace std;


int main()
{
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    Utils utils;
    PhysicsWorld pWorld = PhysicsWorld();


    sf::RenderWindow window(sf::VideoMode(720, 500), "P6 Test");


    sf::Event event;
    Utils::offset = PhysVector(0, 250);


    //Bullet 1 particle
    PhysParticle bullet;
    bullet.name = "Bullet 1";
    bullet.mass = 5.0f;
    //PhysVector dir = PhysVector(-1, 0);
    //bullet.addForce(dir * 50);
    bullet.velocity = PhysVector(-30, 5);

    bullet.particleShape.setRadius(50.0f);
    bullet.radius = bullet.particleShape.getRadius();
    bullet.particleShape.setFillColor(sf::Color::White);
    bullet.particleShape.setOrigin(bullet.particleShape.getRadius(), bullet.particleShape.getRadius());

    PhysVector renderPoint1 = bullet.toRenderPoint();
    bullet.position = PhysVector(245,20);

    bullet.initialPos = bullet.position;
    bullet.particleShape.setPosition(renderPoint1.x, renderPoint1.y);
    //bullet.particleShape.setPosition(bullet.position.x, bullet.position.y);

    pWorld.addParticle(&bullet);

    //NEEDS WORK
    //DragForceGenerator dF = DragForceGenerator(0.1,0.01);
    //pWorld.registry.add(&bullet, &dF);
    //NEEDS WORK


    //BULLET 2
    PhysParticle bullet2;
    bullet2.name = "Bullet 2";
    bullet2.mass = 1.5;
    //PhysVector dir2 = PhysVector(1, 0);
    //bullet2.addForce(dir2 * 50);
    bullet2.velocity = PhysVector(100, 5);

    bullet2.particleShape.setRadius(50.0f);
    bullet2.radius = bullet2.particleShape.getRadius();
    bullet2.particleShape.setFillColor(sf::Color::Blue);
    bullet2.particleShape.setOrigin(bullet2.particleShape.getRadius(), bullet2.particleShape.getRadius());

    PhysVector renderPoint2 = bullet2.toRenderPoint();
    bullet2.position = PhysVector(160, -30);

    bullet2.initialPos = bullet2.position;
    bullet2.particleShape.setPosition(renderPoint2.x, renderPoint2.y);

    //BungeeSpring bS = BungeeSpring(bullet2.position, 5, 20);
    //AnchoredSpring aS = AnchoredSpring(bullet2.position, 5, 1);

    pWorld.addParticle(&bullet2);
    //pWorld.registry.add(&bullet2, &bS);

    /*
    //BULLET 3
    PhysParticle bullet3;
    bullet3.name = "Bullet 3";
    bullet3.mass = 1.5;
    //PhysVector dir3 = PhysVector(1, 0);
    //bullet3.addForce(dir3 * 50);
    bullet3.velocity = PhysVector(0, -40);

    bullet3.particleShape.setRadius(50.0f);
    bullet3.particleShape.setFillColor(sf::Color::Green);
    bullet3.particleShape.setOrigin(bullet3.particleShape.getRadius(), bullet3.particleShape.getRadius());

    PhysVector renderPoint3 = bullet3.toRenderPoint();
    bullet3.position = PhysVector(160, 300);

    bullet3.initialPos = bullet3.position;
    bullet3.particleShape.setPosition(renderPoint3.x, renderPoint3.y);

    pWorld.addParticle(&bullet3);
    */

    /*
    ParticleContact contact = ParticleContact();
    contact.particles[0] = &bullet;
    contact.particles[1] = &bullet2;
    contact.collisonNormal = bullet.position - bullet2.position;
    contact.collisonNormal = contact.collisonNormal.normalize();
    contact.restitution = 0.6;
    

    PhysVector dir = bullet.position - bullet2.position;
    dir = dir.normalize();
    pWorld.addContact(&bullet, &bullet2, 0.6, dir);
    */

    sf::Clock clock;
    sf::Time timeSinceLast = sf::Time::Zero;

    while (1) {

        timeSinceLast += clock.restart();

        if (timeSinceLast > TimePerFrame) {

            timeSinceLast -= TimePerFrame;


            pWorld.update(TimePerFrame.asMilliseconds() / 1000.0f);
            //contact.resolve(TimePerFrame.asMilliseconds() / 1000.0f);


            //cout << "V of a: " << bullet.velocity.x << ", " << bullet.velocity.y << endl;
            //cout << "V of b: " << bullet2.velocity.x << ", " << bullet2.velocity.y << endl;

            PhysVector renderPoint1 = bullet.toRenderPoint();
            bullet.particleShape.setPosition(renderPoint1.x, renderPoint1.y);

            PhysVector renderPoint2 = bullet2.toRenderPoint();
            bullet2.particleShape.setPosition(renderPoint2.x, renderPoint2.y);

            //PhysVector renderPoint3 = bullet3.toRenderPoint();
            //bullet3.particleShape.setPosition(renderPoint3.x, renderPoint3.y);

            //bullet.particleShape.setPosition(bullet.position.x, bullet.position.y);
            //bullet2.particleShape.setPosition(bullet2.position.x, bullet2.position.y);

            window.pollEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear();

            if (bullet.getIsDestroyed() != true)
            {
                window.draw(bullet.particleShape);
                window.draw(bullet2.particleShape);
                //window.draw(bullet3.particleShape);
            }
                

            window.display();

            /*
            if (bullet.position.x > bullet.initialPos.x && bullet.position.y >= bullet.initialPos.y)
            {
                break;
            }
            */
           
        }
    }

    utils.displayDistanceTravelled(bullet);


    return 0;
}