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
#include "P6 Components/Collision/ContactResolver.h"
#include "P6 Components/Links/ParticleLink.h"
#include "P6 Components/Links/Rod.h"

#define PI 3.14159

using namespace std;


int main()
{
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    Utils utils;
    PhysicsWorld pWorld = PhysicsWorld();


    sf::RenderWindow window(sf::VideoMode(720, 500), "P6 Test");


    sf::Event event;
    sf::Texture shurikenTexture;
    sf::Sprite shurikenSprite;

    Utils::offset = PhysVector(0, 250);

    shurikenTexture.loadFromFile("Images/shuriken.png");
    shurikenSprite.setTexture(shurikenTexture);
    


    //Bullet 1 particle
    PhysParticle bullet;
    bullet.name = "Bullet 1";
    bullet.mass = 50.0f;
    //PhysVector dir = PhysVector(-1, 0);
    //bullet.addForce(dir * 50);
    bullet.velocity = PhysVector(0,0);
    bullet.addForce(PhysVector(-20000, 0));
    bullet.damping = 1.0f;

    bullet.particleShape.setRadius(20.0f);
    bullet.radius = bullet.particleShape.getRadius();
    bullet.particleShape.setFillColor(sf::Color::White);
    bullet.particleShape.setOrigin(bullet.particleShape.getRadius(), bullet.particleShape.getRadius());

    PhysVector renderPoint1 = bullet.toRenderPoint();
    bullet.position = PhysVector(360,0);

    bullet.initialPos = bullet.position;
    bullet.particleShape.setPosition(renderPoint1.x, renderPoint1.y);
    //bullet.particleShape.setPosition(bullet.position.x, bullet.position.y);

    pWorld.addParticle(&bullet);


    //SHURIKEN 
    shurikenSprite.setOrigin(shurikenTexture.getSize().x / 2, shurikenTexture.getSize().y / 2);
    PhysVector shurikenPos = Utils::p6ToSFMLPoint(bullet.position);

    //BULLET 2
    PhysParticle bullet2;
    bullet2.name = "Bullet 2";
    bullet2.mass = 0.1f;
    //PhysVector dir2 = PhysVector(1, 0);
    //bullet2.addForce(dir2 * 50);
    //bullet2.velocity = PhysVector(100, -50);
    bullet2.addForce(PhysVector(20000, 0));
    bullet2.damping = 0.8f;

    bullet2.particleShape.setRadius(15.0f);
    bullet2.radius = bullet2.particleShape.getRadius();
    bullet2.particleShape.setFillColor(sf::Color::Blue);
    bullet2.particleShape.setOrigin(bullet2.particleShape.getRadius(), bullet2.particleShape.getRadius());

    PhysVector renderPoint2 = bullet2.toRenderPoint();
    bullet2.position = PhysVector(360, 100);

    bullet2.initialPos = bullet2.position;
    bullet2.particleShape.setPosition(renderPoint2.x, renderPoint2.y);

    pWorld.addParticle(&bullet2);

    
    //BULLET 3
    PhysParticle bullet3;
    bullet3.name = "Bullet 3";
    bullet3.mass = 0.1f;
    //PhysVector dir3 = PhysVector(1, 0);
    //bullet3.addForce(dir3 * 50);
    bullet3.velocity = PhysVector(0, 0);
    bullet3.damping = 0.8f;

    bullet3.particleShape.setRadius(15.0f);
    bullet3.particleShape.setFillColor(sf::Color::Blue);
    bullet3.particleShape.setOrigin(bullet3.particleShape.getRadius(), bullet3.particleShape.getRadius());

    PhysVector renderPoint3 = bullet3.toRenderPoint();
    bullet3.position = PhysVector(460, 0);

    bullet3.initialPos = bullet3.position;
    bullet3.particleShape.setPosition(renderPoint3.x, renderPoint3.y);

    pWorld.addParticle(&bullet3);

    //BULLET 4
    PhysParticle bullet4;
    bullet4.name = "Bullet 4";
    bullet4.mass = 0.1f;
    //PhysVector dir3 = PhysVector(1, 0);
    //bullet3.addForce(dir3 * 50);
    bullet4.velocity = PhysVector(0, 0);
    bullet4.damping = 0.8f;

    bullet4.particleShape.setRadius(15.0f);
    bullet4.particleShape.setFillColor(sf::Color::Blue);
    bullet4.particleShape.setOrigin(bullet4.particleShape.getRadius(), bullet4.particleShape.getRadius());

    PhysVector renderPoint4 = bullet4.toRenderPoint();
    bullet4.position = PhysVector(360, -100);

    bullet4.initialPos = bullet4.position;
    bullet4.particleShape.setPosition(renderPoint4.x, renderPoint4.y);

    pWorld.addParticle(&bullet4);

    
    //BULLET 5
    PhysParticle bullet5;
    bullet5.name = "Bullet 5";
    bullet5.mass = 0.1f;
    //PhysVector dir3 = PhysVector(1, 0);
    //bullet3.addForce(dir3 * 50);
    bullet5.velocity = PhysVector(0, 0);
    bullet5.damping = 0.8f;

    bullet5.particleShape.setRadius(15.0f);
    bullet5.particleShape.setFillColor(sf::Color::Blue);
    bullet5.particleShape.setOrigin(bullet5.particleShape.getRadius(), bullet5.particleShape.getRadius());

    PhysVector renderPoint5 = bullet5.toRenderPoint();
    bullet5.position = PhysVector(260, 0);

    bullet5.initialPos = bullet5.position;
    bullet5.particleShape.setPosition(renderPoint5.x, renderPoint5.y);

    pWorld.addParticle(&bullet5);
    
    PhysVector temp(0, 0);

    //ADD RODS
    Rod* bearToTop = new Rod();
    bearToTop->particles[0] = &bullet; //bearing
    bearToTop->particles[1] = &bullet2;  //top bullet
    bearToTop->length = 100;
    pWorld.links.push_back(bearToTop);

    Rod* bearToRight = new Rod();
    bearToRight->particles[0] = &bullet; //bearing 
    bearToRight->particles[1] = &bullet3;  //right bullet
    bearToRight->length = 100;
    pWorld.links.push_back(bearToRight);

    Rod* topToRight = new Rod();
    topToRight->particles[0] = &bullet2; //top bullet
    topToRight->particles[1] = &bullet3;  //right bullet
    topToRight->length = temp.getDistanceBetweenPoints(bullet2.position, bullet3.position);
    pWorld.links.push_back(topToRight);

    Rod* bearToBot = new Rod();
    bearToBot->particles[0] = &bullet; //bearing
    bearToBot->particles[1] = &bullet4; //bot bullet
    bearToBot->length = 100;
    pWorld.links.push_back(bearToBot);

    Rod* botToRight = new Rod();
    botToRight->particles[0] = &bullet4; //bot bullet
    botToRight->particles[1] = &bullet3; //right bullet
    botToRight->length = temp.getDistanceBetweenPoints(bullet4.position, bullet3.position);
    pWorld.links.push_back(botToRight);

    Rod* botToLeft = new Rod();
    botToLeft->particles[0] = &bullet4; //bot bullet
    botToLeft->particles[1] = &bullet5; //left bullet
    botToLeft->length = temp.getDistanceBetweenPoints(bullet4.position, bullet5.position);
    pWorld.links.push_back(botToLeft);

    Rod* bearToLeft = new Rod();
    bearToLeft->particles[0] = &bullet; //bearing
    bearToLeft->particles[1] = &bullet5; //left bullet
    bearToLeft->length = 100;
    pWorld.links.push_back(bearToLeft);

    Rod* topToLeft = new Rod();
    topToLeft->particles[0] = &bullet2; 
    topToLeft->particles[1] = &bullet5;
    topToLeft->length = temp.getDistanceBetweenPoints(bullet2.position, bullet5.position);
    pWorld.links.push_back(topToLeft);
    
    /////////////////////////////////////////////////////////////////////

    sf::Clock clock;
    sf::Time timeSinceLast = sf::Time::Zero;

    while (1) {

        timeSinceLast += clock.restart();

        if (timeSinceLast > TimePerFrame) {

            timeSinceLast -= TimePerFrame;


            pWorld.update(TimePerFrame.asMilliseconds() / 1000.0f);



            PhysVector renderPoint1 = bullet.toRenderPoint();
            bullet.particleShape.setPosition(renderPoint1.x, renderPoint1.y);

            PhysVector renderPoint2 = bullet2.toRenderPoint();
            bullet2.particleShape.setPosition(renderPoint2.x, renderPoint2.y);

            PhysVector renderPoint3 = bullet3.toRenderPoint();
            bullet3.particleShape.setPosition(renderPoint3.x, renderPoint3.y);

            PhysVector renderPoint4 = bullet4.toRenderPoint();
            bullet4.particleShape.setPosition(renderPoint4.x, renderPoint4.y);

            PhysVector renderPoint5 = bullet5.toRenderPoint();
            bullet5.particleShape.setPosition(renderPoint5.x, renderPoint5.y);

 

            window.pollEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear();

            shurikenPos = Utils::p6ToSFMLPoint(bullet.position);
            shurikenSprite.setPosition(shurikenPos.x, shurikenPos.y);

            float rad_Angle1 = atan2f(bullet2.position.y - bullet.position.y, bullet2.position.x - bullet.position.x);
            
            float deg = rad_Angle1 * (180 / PI);

            shurikenSprite.setRotation(-deg + 90);

            if (bullet.getIsDestroyed() != true)
            {
                window.draw(shurikenSprite);
                window.draw(bullet.particleShape);
                window.draw(bullet2.particleShape);
                window.draw(bullet3.particleShape);
                window.draw(bullet4.particleShape);
                window.draw(bullet5.particleShape);
            }
                

            window.display();

            cout << bullet.velocity.x << ", " << bullet.velocity.y << endl;


            
            /*
            if (bullet.position.x > bullet.initialPos.x && bullet.position.y >= bullet.initialPos.y)
            {
                break;
            }
            */
           
        }
    }

    //utils.displayDistanceTravelled(bullet);


    return 0;
}