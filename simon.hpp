#ifndef SIMON_HPP_INCLUDED
#define SIMON_HPP_INCLUDED

#include "movables.hpp"
#include <vector>

class Simon : public Movable
{
enum spriteStates {fL, fR, wL, wR, jL, jR, cL, cR};

public:
    Simon();
    void update(float dt);
    void updateSprite(float dt);

    bool devMode = 1;

private:
    sf::IntRect spriteRect;
    int currentState;
    std::vector< std::vector<sf::IntRect> > stateRects;
    float frameTimer;
};

#endif // SIMON_HPP_INCLUDED
