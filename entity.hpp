#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Entity
{
public:
    sf::Texture tex;
    sf::Sprite sprite;
    int width;
    int height;

    virtual void update(float dt) = 0;
};

#endif // ENTITY_HPP_INCLUDED
