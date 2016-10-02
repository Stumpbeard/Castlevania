#ifndef BLOCK_HPP_INCLUDED
#define BLOCK_HPP_INCLUDED

#include "entity.hpp"

class Block : public Entity
{
public:
    Block(int x, int y, int w, int h);
    void update(float dt);
    sf::FloatRect bounds;
    sf::RectangleShape outline;
};

#endif // BLOCK_HPP_INCLUDED
