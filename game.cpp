#include "game.hpp"
#include "sta_level1.hpp"
#include <iostream>

Game::Game()
{
    windowWidth = 256;
    windowHeight = 224;
    window.create(sf::VideoMode(windowWidth*4, windowHeight*4), "Castlevania");
    //window.setFramerateLimit(60);
    player = new Simon();

}

void Game::play()
{
    states.push(new Sta_Level1(this));

    while(window.isOpen())
    {
        dt = clock.restart().asSeconds();
        states.top()->update(dt);
    }
}
