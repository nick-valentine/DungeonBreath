#include "../headers/Wall.h"

Wall::Wall()
{
}

void Wall::init(int pos_x, int pos_y, int size_x, int size_y, std::string img_name)
{
    Actor::init(pos_x, pos_y, size_x, size_y, img_name);
    
    add_sprite(0, 0, 100, 100);
    
    my_type = Block;
}

void Wall::update(int delta)
{

}

void Wall::draw(sf::RenderWindow &window)
{
    get_sprite(0)->setPosition(get_rect().left, get_rect().top);
    get_sprite(0)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
	window.draw(*get_sprite(0));
}

Actor *Wall::clone()
{
    Wall *temp = new Wall(*this);
    clone_common(temp);
    return temp;
}
