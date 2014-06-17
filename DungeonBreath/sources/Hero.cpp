#include "../headers/Hero.h"

const double Hero::accel_x = 1.5;
const double Hero::accel_y = 1.5;
const double Hero::vel_damp = 10;

Hero::Hero() : Actor()
{
	init(0, 0, 0, 0);
}

void Hero::init(int pos_x, int pos_y, int size_x, int size_y)
{
    Actor::init(pos_x, pos_y, size_x, size_y, "./img/Hero.png");

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
	
	update_old_pos();
	
	if(x%5 == 0)
	{
		active_sprite = (active_sprite + 1) % 3;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
	    acceleration_x = accel_x;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	    acceleration_x = -accel_x;
	}
	else
	{
	    acceleration_x = 0;
	}   
	
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	    acceleration_y = -accel_y;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	    acceleration_y = accel_y;
	}
	else
	{
	    acceleration_y = 2;
	}

    velocity_x -= velocity_x / vel_damp;
    velocity_y -= velocity_y / vel_damp;
	
	if((velocity_x < 1 && velocity_x > 0)
	    || (velocity_x > -1 && velocity_x < 0))
	{
	    velocity_x = 0;
	}
	
	if((velocity_y < 1 && velocity_y > 0)
	    || (velocity_y > -1 && velocity_y < 0))
	{
	    velocity_y = 0;
	}
	
	velocity_x += acceleration_x;
	velocity_y += acceleration_y;
	
	set_pos_x(get_pos_x() + velocity_x);
	set_pos_y(get_pos_y() + velocity_y);

    if(resolve_collision())
    {
        //velocity_x = 0;
        velocity_y = 0;
    }

    
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
