#include "simon.hpp"
#include <iostream>
#include <math.h>

Simon::Simon()
{
    width = 16;
    height = 32;
    speed = 64;
    vertSpeed = 0;
    walking = 0;
    facing = 0;
    jumping = 0;
    crouching = 0;
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

    // cL
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
    // Walking
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !jumping && !crouching)
    {
        walking = 1;
        facing = 0;
        currentState = wL;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !jumping && !crouching)
    {
        walking = 1;
        facing = 1;
        currentState = wR;
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !jumping)
    {
        walking = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !jumping && !crouching)
    {
        crouching = 1;
        sprite.move(0, 8);
        if(facing == 0)
            currentState = cL;
        if(facing == 1)
            currentState = cR;
        walking = 0;
    } else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && crouching)
    {
        crouching = 0;
    }

    // Standing still
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && facing == 0 && !jumping && !crouching)
    {
        currentState = fL;
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && facing == 1 && !jumping && !crouching)
    {
        currentState = fR;
    }

    // Jumping
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

    updateSprite(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && devMode)
        speed = 640;
}

void Simon::updateSprite(float dt)
{
    frameTimer += 0.142;
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
    case cL:
        sprite.setTextureRect(stateRects[cL][0]);
        break;
    case cR:
        sprite.setTextureRect(stateRects[cR][0]);
        break;
    default:
        break;
    }
}
