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
    get_sprite(0)->setPosition(get_pos_x(), get_pos_y());
    get_sprite(0)->setScale(get_size_x() / 100.0, get_size_y() / 100.0);
	window.draw(*get_sprite(0));
}
