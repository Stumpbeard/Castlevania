#include "sta_level1.hpp"
#include <iostream>
#include <string>

Sta_Level1::Sta_Level1(Game* game)
{
    this->game = game;
    bgTex_.loadFromFile("res/backgrounds/level1-2.png");
    background_.setTexture(bgTex_);
    background_.move(0, 40);
    mainView.reset(sf::FloatRect(0, 0, game->windowWidth, game->windowHeight));

    movables.push_back(game->player);
    game->player->sprite.setPosition(16, 50-game->player->height);

    bounds.push_back(new Block(0, 200, 2816, 24));
    bounds.push_back(new Block(688, 136, 48, 16));

    entities.insert(entities.end(), movables.begin(), movables.end());
    entities.insert(entities.end(), bounds.begin(), bounds.end());

    this->physics = new Physics(movables, bounds);

    lucon.loadFromFile("lucon.ttf");
    fps.setFont(lucon);
    fps.setCharacterSize(12);
    fps.setPosition(0, 0);
    fps.setColor(sf::Color::White);
}

void Sta_Level1::update(float dt)
{
    while(game->window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            game->window.close();
        }

    }

    float time = 1.f/dt;
    lastTime = dt;
    fps.setString(std::to_string(time));

    for(int i = 0; i < movables.size(); ++i)
        movables[i]->update(dt);

    physics->update(dt);

    centerView();

    game->window.clear(sf::Color::Black);
    game->window.setView(mainView);
    game->window.draw(background_);
    for(int i = 0; i < movables.size(); ++i)
        game->window.draw(movables[i]->sprite);
    /*for(int i = 0; i < bounds.size(); ++i)
        game->window.draw(bounds[i]->outline);*/
    game->window.draw(fps);
    game->window.display();
}

void Sta_Level1::handleInput(float dt)
{
    /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        mainView.setCenter(game->player->sprite.getGlobalBounds().left + game->player->width/2, mainView.getCenter().y);
        while((mainView.getCenter().x-mainView.getSize().x/2 < 0))
            mainView.move(1, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        mainView.move(64/30, 0);
        while((mainView.getCenter().x+mainView.getSize().x/2 > background_.getGlobalBounds().width))
            mainView.move(-1, 0);
    }*/
}

void Sta_Level1::centerView()
{
    mainView.setCenter(game->player->sprite.getGlobalBounds().left + game->player->width/2, mainView.getCenter().y);
    if((mainView.getCenter().x-mainView.getSize().x/2 < 0))
        mainView.setCenter(0+mainView.getSize().x/2, mainView.getCenter().y);
    if((mainView.getCenter().x+mainView.getSize().x/2 > background_.getGlobalBounds().width))
        mainView.setCenter(background_.getGlobalBounds().width-mainView.getSize().x/2, mainView.getCenter().y);
}
