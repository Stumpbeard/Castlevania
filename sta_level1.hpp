#ifndef STA_LEVEL1_HPP_INCLUDED
#define STA_LEVEL1_HPP_INCLUDED

#include "game_states.hpp"
#include "block.hpp"
#include "physics.hpp"
#include <vector>


class Sta_Level1 : public GameState
{
public:
    Sta_Level1(Game* game);

    void update(float dt);
    void handleInput(float dt);
    void centerView();

    std::vector<Entity*> entities;
    std::vector<Movable*> movables;
    std::vector<Block*> bounds;
    Physics* physics;


private:
    sf::Texture bgTex_;
    sf::Sprite background_;
};

#endif // STA_LEVEL1_HPP_INCLUDED
