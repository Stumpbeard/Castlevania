#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "game_states.hpp"
#include "simon.hpp"
#include <stack>

class GameState;

class Game
{
public:

    std::stack<GameState*> states;
    sf::RenderWindow window;
    float dt;
    sf::Clock clock;

    float windowWidth;
    float windowHeight;

    Game();

    void play();

    Simon* player;
};

#endif // GAME_HPP_INCLUDED
