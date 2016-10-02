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
            movables[i]->sprite.move(-movables[i]->speed/60, 0);
            for(int j = 0; j < bounds.size(); ++j)
            {
                if(movables[i]->sprite.getGlobalBounds().intersects(bounds[j]->bounds))
                {
                    movables[i]->sprite.setPosition(bounds[j]->bounds.left+bounds[j]->bounds.width, movables[i]->sprite.getPosition().y);
                }
            }
        }
        if(movables[i]->walkingRight)
        {
            movables[i]->sprite.move(movables[i]->speed/60, 0);
            for(int j = 0; j < bounds.size(); ++j)
            {
                if(movables[i]->sprite.getGlobalBounds().intersects(bounds[j]->bounds))
                {
                    movables[i]->sprite.setPosition(bounds[j]->bounds.left-movables[i]->sprite.getGlobalBounds().width, movables[i]->sprite.getPosition().y);
                }
            }
        }
    }
    // Apply gravity
    for(int i = 0; i < movables.size(); ++i)
    {
        movables[i]->sprite.move(0, movables[i]->vertSpeed/60*1.3);
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
        movables[i]->vertSpeed += gravity/60*1.3;
        if(movables[i]->vertSpeed > gravity)
            movables[i]->vertSpeed = gravity;
    }
}
