#ifndef GAME_STATES_HPP_INCLUDED
#define GAME_STATES_HPP_INCLUDED

#include "game.hpp"
#include "simon.hpp"

class Game;

class GameState
{
public:

    Game* game;
    sf::View mainView;
    sf::Event event;

    virtual void update(float dt) = 0;
};



#endif // GAME_STATES_HPP_INCLUDED
