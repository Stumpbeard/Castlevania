#include "simon.hpp"
#include <iostream>
#include <math.h>

Simon::Simon()
{
    width = 16;
    height = 32;
    speed = 64;
    vertSpeed = 0;
    walkingLeft = 0;
    walkingRight = 0;
    jumping = 0;
    currentState = fL;
    name = "Simon";
    frameTimer = 0;
    tex.loadFromFile("res/entities/simon_sheet.png");
    sprite.setTexture(tex);
    std::vector<sf::IntRect> holder;

    // fL
    holder.push_back(sf::IntRect(0, 0, 16, 32));
    stateRects.push_back(holder);
    holder.clear();

    // fR
    holder.push_back(sf::IntRect(0, 32, 16, 32));
    stateRects.push_back(holder);
    holder.clear();

    // wL
    holder.push_back(sf::IntRect(0, 0, 16, 32));
    holder.push_back(sf::IntRect(16, 0, 16, 32));
    holder.push_back(sf::IntRect(32, 0, 16, 32));
    holder.push_back(sf::IntRect(16, 0, 16, 32));
    stateRects.push_back(holder);
    holder.clear();

    // wR
    holder.push_back(sf::IntRect(0, 32, 16, 32));
    holder.push_back(sf::IntRect(16, 32, 16, 32));
    holder.push_back(sf::IntRect(32, 32, 16, 32));
    holder.push_back(sf::IntRect(16, 32, 16, 32));
    stateRects.push_back(holder);
    holder.clear();

    // jL
    holder.push_back(sf::IntRect(48, 8, 16, 24));
    stateRects.push_back(holder);
    holder.clear();

    // jR
    holder.push_back(sf::IntRect(48, 40, 16, 24));
    stateRects.push_back(holder);
    holder.clear();
}

void Simon::update(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !jumping)
    {
        walkingLeft = 1;
        facing = 0;
        currentState = wL;
    } else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !jumping) {
        walkingLeft = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !jumping)
    {
        walkingRight = 1;
        facing = 1;
        currentState = wR;
    } else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !jumping){
        walkingRight = 0;
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && facing == 0 && !jumping)
    {
        currentState = fL;
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && facing == 1 && !jumping)
    {
        currentState = fR;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !jumping && facing == 0)
    {
        vertSpeed = -128;
        jumping = 1;
        currentState = jL;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !jumping && facing == 1)
    {
        vertSpeed = -128;
        jumping = 1;
        currentState = jR;
    }


    /*
    if(walkingLeft)
    {
        sprite.move(-speed*dt, 0);
    }
    if(walkingRight)
    {
        sprite.move(speed*dt, 0);
    }*/

    updateSprite(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && devMode)
        speed = 640;
}

void Simon::updateSprite(float dt)
{
    frameTimer += dt*8;
    switch(currentState)
    {
    case fL:
        sprite.setTextureRect(stateRects[fL][0]);
        break;
    case fR:
        sprite.setTextureRect(stateRects[fR][0]);
        break;
    case wL:
        sprite.setTextureRect(stateRects[wL][int(floorf(frameTimer))%4]);
        break;
    case wR:
        sprite.setTextureRect(stateRects[wR][int(floorf(frameTimer))%4]);
        break;
    case jL:
        if(vertSpeed > -96 && vertSpeed < 64)
            sprite.setTextureRect(stateRects[jL][0]);
        else
            sprite.setTextureRect(stateRects[fL][0]);
        break;
    case jR:
        if(vertSpeed > -96 && vertSpeed < 64)
            sprite.setTextureRect(stateRects[jR][0]);
        else
            sprite.setTextureRect(stateRects[fR][0]);
        break;
    default:
        break;
    }
}
