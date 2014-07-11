#include "../headers/Wall.h"

Wall::Wall() : Actor()
{
}

void Wall::init(int pos_x, int pos_y, int size_x, int size_y, int sprite_pos_x, int sprite_pos_y, std::string img_name)
{
    Actor::init(pos_x, pos_y, size_x, size_y, img_name);
    
    add_sprite((sprite_pos_x - 1) * 100, (sprite_pos_y - 1) * 100, 100, 100);
    
	set_alive(true);

    my_type = Block;
    
    set_collide_type(All);
}

void Wall::update(int delta)
{

}

void Wall::draw(sf::RenderWindow &window)
{
	if((abs(hero->get_rect().left - get_rect().left) + abs(hero->get_rect().top - get_rect().top)) < min_distance + min_distance)
	{
		get_sprite(0)->setPosition(get_rect().left, get_rect().top);
		get_sprite(0)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
		window.draw(*get_sprite(0));
	}
}

Actor *Wall::clone()
{
    Wall *temp = new Wall(*this);
    return temp;
}
