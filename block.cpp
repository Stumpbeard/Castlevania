#include "block.hpp"

Block::Block(int x, int y, int w, int h)
{
    bounds = sf::FloatRect(x, y, w, h);
    outline = sf::RectangleShape(sf::Vector2f(bounds.width, bounds.height));
    outline.setPosition(bounds.left, bounds.top);
    outline.setOutlineThickness(1);
    outline.setOutlineColor(sf::Color::Red);
}

void Block::update(float dt)
{

}
