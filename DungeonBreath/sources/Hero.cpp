#include "../headers/Hero.h"

Hero::Hero() : Actor()
{
	active_sprite = -1;
	
	velocity_x = 0;
	velocity_y = 0;
	
	acceleration_x = 0;
	acceleration_y = 0;
}

Hero::Hero(int pos_x, int pos_y, int size_x, int size_y)
	: Actor(pos_x, pos_y, size_x, size_y, "./img/Hero.png")
{
	add_sprite(0,0,100,100);
	add_sprite(100,0,100,100);
	add_sprite(0,100,100,100);

	active_sprite = 0;
	
	velocity_x = 0;
	velocity_y = 0;
	
	acceleration_x = 0;
	acceleration_y = 0;
}

void Hero::update(int delta)
{
	static int x = 0;
	x++;
	
	if(x%5 == 0)
	{
	    std::cout<<active_sprite<<std::endl;
		active_sprite = (active_sprite + 1) % 3;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
	    acceleration_x = 5;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	    acceleration_x = -5;
	}
	else
	{
	    acceleration_x = 0;
	}   
	
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	    acceleration_y = -5;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	    acceleration_y = 5;
	}
	else
	{
	    acceleration_y = 0;
	}

    std::cout<<acceleration_x<<" "<<acceleration_y<<std::endl;
    std::cout<<velocity_x<<" "<<velocity_y<<std::endl;

    velocity_x = velocity_x / 2;
    velocity_y = velocity_y / 2;
	
	velocity_x += acceleration_x;
	velocity_y += acceleration_y;
	
	set_pos_x(get_pos_x() + velocity_x);
	set_pos_y(get_pos_y() + velocity_y);
}

void Hero::draw(sf::RenderWindow &window)
{
	if(active_sprite != -1)
	{
	    get_sprite(active_sprite)->setPosition(get_pos_x(), get_pos_y());
	    get_sprite(active_sprite)->setScale(get_size_x() / 100.0, get_size_y() / 100.0);
		window.draw(*get_sprite(active_sprite));
	}
}
