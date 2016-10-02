#include "physics.hpp"
#include <iostream>
#include <math.h>

Physics::Physics()
{

}

Physics::Physics(std::vector<Movable*>& movables, std::vector<Block*>& bounds)
{
    this->movables = movables;
    this->bounds = bounds;
    gravity = 64*4;
}

void Physics::update(float dt)
{


    // Move movables
    for(int i = 0; i < movables.size(); ++i)
    {
        if(movables[i]->walkingLeft)
        {
            movables[i]->sprite.move(-movables[i]->speed*dt, 0);
            for(int j = 0; j < bounds.size(); ++j)
            {
                if(movables[i]->sprite.getGlobalBounds().intersects(bounds[j]->bounds))
                {
                    movables[i]->sprite.move(movables[i]->speed*dt, 0);
                }
            }
        }
        if(movables[i]->walkingRight)
        {
            movables[i]->sprite.move(movables[i]->speed*dt, 0);
            for(int j = 0; j < bounds.size(); ++j)
            {
                if(movables[i]->sprite.getGlobalBounds().intersects(bounds[j]->bounds))
                {
                    movables[i]->sprite.move(-movables[i]->speed*dt, 0);
                }
            }
        }
    }
    // Apply gravity
    for(int i = 0; i < movables.size(); ++i)
    {
        int movement = movables[i]->vertSpeed*dt*1.3;
        if(movement > 16)
            movement = 16;
        if(movement < -16)
            movement = -16;
        movables[i]->sprite.move(0, movement);
        if(movables[i]->vertSpeed >= 0)
        {
            for(int j = 0; j < bounds.size(); ++j)
            {
                if(movables[i]->sprite.getGlobalBounds().intersects(bounds[j]->bounds))
                {
                    if(ceilf(movables[i]->sprite.getGlobalBounds().top) < ceilf(bounds[j]->bounds.top)-10)
                    {
                        movables[i]->sprite.setPosition(movables[i]->sprite.getPosition().x, bounds[j]->bounds.top-movables[i]->height);
                        movables[i]->jumping = 0;
                    }
                }
            }
        }
        movables[i]->vertSpeed += gravity*dt*1.3;
        if(movables[i]->vertSpeed > gravity)
            movables[i]->vertSpeed = gravity;
    }
}
