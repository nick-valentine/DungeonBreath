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
	update_count = 0;
	
	acceleration_x = 0;
	acceleration_y = 0;
	
	my_type = Player;
}

void Hero::update(int delta)
{
    if(get_alive())
    {
	    update_count++;
	
	    if(update_count%5 == 0)
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
	        acceleration_y = 0;
	    }

        set_velocity_x(get_velocity_x() - get_velocity_x() / vel_damp);
        set_velocity_y(get_velocity_y() - get_velocity_y() / vel_damp);
	
	    if((get_velocity_x() < 1 && get_velocity_x() > 0)
	        || (get_velocity_x() > -1 && get_velocity_x() < 0))
	    {
	        set_velocity_x(0);
	    }
	
	    if((get_velocity_y() < 1 && get_velocity_y() > 0)
	        || (get_velocity_y() > -1 && get_velocity_y() < 0))
	    {
	        set_velocity_y(0);
	    }
	
	    set_velocity_x(get_velocity_x() + acceleration_x);
	    set_velocity_y(get_velocity_y() + acceleration_y);

        common_update(delta);
        
        //sword and all that stuff here
        for(int i = 0; i < last_collided.size(); ++i)
        {
            if(all_actors[last_collided[i].second]->get_type() == Enemy)
            {
                all_actors[last_collided[i].second]->kill();
            }
            
        }
    }
}

void Hero::draw(sf::RenderWindow &window)
{
    if(get_alive())
    {
	    if(active_sprite != -1)
	    {
	        get_sprite(active_sprite)->setPosition(get_rect().left, get_rect().top);
	        get_sprite(active_sprite)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
		    window.draw(*get_sprite(active_sprite));
	    }
	}
}
