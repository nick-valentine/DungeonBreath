#include "../headers/StoneWall.h"

StoneWall::StoneWall()
{
    init(0, 0, 0, 0);
}

void StoneWall::init(int pos_x, int pos_y, int size_x, int size_y)
{
    Actor::init(pos_x, pos_y, size_x, size_y, "./img/default.png");
    
    add_sprite(0, 0, 100, 100);
}

void StoneWall::update(int delta)
{

}

void StoneWall::draw(sf::RenderWindow &window)
{
    get_sprite(0)->setPosition(get_rect().left, get_rect().top);
    get_sprite(0)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
	window.draw(*get_sprite(0));
}
