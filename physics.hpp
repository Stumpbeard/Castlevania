#ifndef PHYSICS_HPP_INCLUDED
#define PHYSICS_HPP_INCLUDED

#include <vector>
#include "movables.hpp"
#include "block.hpp"

class Physics
{
public:
    Physics();
    Physics(std::vector<Movable*>& movables, std::vector<Block*>& bounds);
    void update(float dt);

    std::vector<Movable*> movables;
    std::vector<Block*> bounds;
    float gravity;
};


#endif // PHYSICS_HPP_INCLUDED
