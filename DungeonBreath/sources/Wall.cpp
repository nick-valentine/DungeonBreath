#include "../headers/Wall.h"

Wall::Wall() : Actor()
{
}

Wall::Wall(const Wall &other)
{
	this->set_alive(other.get_alive());
	this->set_collide_type(other.get_collide_type());
	this->set_rect(other.get_rect());
	this->set_texture(other.get_image_name());
	this->set_velocity_x(other.get_velocity_x());
	this->set_velocity_y(other.get_velocity_y());
	//this->set_sprites(other.get_sprites());
	
	init(other.get_rect().left,
			other.get_rect().top,
			other.get_rect().width,
			other.get_rect().height,
			other.sprite_x,
			other.sprite_y,
			other.img_name);
}

void Wall::init(int pos_x, int pos_y, int size_x, int size_y, int sprite_pos_x, int sprite_pos_y, std::string img_name)
{
    Actor::init(pos_x, pos_y, size_x, size_y, img_name);
    
	this->sprite_x = sprite_pos_x;
	this->sprite_y = sprite_pos_y;
	this->img_name = img_name;
	
    add_sprite((sprite_pos_x - 1) * 100, (sprite_pos_y - 1) * 100, 100, 100);
    get_sprite(0)->setPosition(get_rect().left, get_rect().top);
	get_sprite(0)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
		
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
		window.draw(*get_sprite(0));
	}
}

Actor *Wall::clone()
{
    Wall *temp = new Wall(*this);
    return temp;
}
