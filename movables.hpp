#ifndef MOVABLES_HPP_INCLUDED
#define MOVABLES_HPP_INCLUDED

#include "entity.hpp"
#include <string>

class Movable : public Entity
{
public:
    float speed;
    float vertSpeed;

    std::string name;
    bool walking;
    bool jumping;
    bool crouching;
    int facing;


};


#endif // MOVABLES_HPP_INCLUDED
