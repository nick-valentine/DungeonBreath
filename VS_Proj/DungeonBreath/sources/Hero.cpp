#include "../headers/Hero.h"

const double Hero::accel_x = 1.5;
const double Hero::accel_y = 1.5;
const double Hero::vel_damp = 10;

Hero::Hero() : Actor()
{
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
	facing_dir = D_Down;
	
	last_space_pressed = false;
	last_one_pressed = false;
	
	set_collide_type(All);
	
	magic_missile = new MagicMissile;
	magic_missile->init(500, 500, 50, 50, 0, 0, "img/MagicMissile.png");
	magic_missile->unregister();
	missile_factory.init(magic_missile, 0, 300000, 0, 0);
	
	magic_nova = new MagicNova;
	magic_nova->init(500, 500, 50, 50, 0, 0, true, "img/MagicMissile.png");
	missile_factory.add_actor(magic_nova, 0, 300000);
	
}

void Hero::update(int delta)
{
    if(get_alive())
    {
        missile_factory.update(delta);
        magic_missile->set_rect(get_rect());
        magic_missile->set_facing(facing_dir);
        magic_nova->set_rect(get_rect());
        magic_nova->set_facing(facing_dir);
        
	    update_count++;
	
	    if(update_count%5 == 0)
	    {
		    active_sprite = (active_sprite + 1) % 3;
	    }
	
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	    {
	        acceleration_x = accel_x;
	        facing_dir = D_Right;
	    }
	    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	    {
	        acceleration_x = -accel_x;
	        facing_dir = D_Left;
	    }
	    else
	    {
	        acceleration_x = 0;
	    }   
	
	
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	    {
	        acceleration_y = -accel_y;
	        facing_dir = D_Up;
	    }
	    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	    {
	        acceleration_y = accel_y;
	        facing_dir = D_Down;
	    }
	    else
	    {
	        acceleration_y = 0;
	    }
	    
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	    {
	    	if(last_one_pressed == false)
	    	{
	    		/*
			    double num_pugs = 15.0;
			    for(double i = 0; i < num_pugs; ++i)
			    {
					MagicMissile *temp = new MagicMissile;
					temp->init(get_rect().left, 
		                                    get_rect().top, 
		                                    50, 
		                                    50, 
		                                    cos( (i * (360.0 / (num_pugs + 1)))) * 4, 
		                                    sin( (i * (360.0 / (num_pugs + 1)))) * 4, 
		                                    "./img/MagicMissile.png");
					Spells.push_back(temp);

			    }
			    */
			    missile_factory.spawn(1);
	        }
	        last_one_pressed = true;
	    }
	    else
	    {
	    	last_one_pressed = false;
	    }
	    
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	    {
	        if(last_space_pressed == false)
	        {
                missile_factory.spawn(0);
	        }
	        last_space_pressed = true;
	    }
	    else
	    {
	        last_space_pressed = false;
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
        for(int i = 0; i < Spells.size(); ++i)
        {
            Spells[i]->update(delta);
        }
        for(int i = 0; i < Spells.size(); ++i)
        {
        	if(Spells[i]->get_alive() == false)
        	{
		    	Spells[i] = Spells[Spells.size() - 1];
		    	Spells.pop_back();
		    	--i;
        	}
        }
    }
}

void Hero::draw(sf::RenderWindow &window)
{
    if(get_alive())
    {
        missile_factory.draw(window);
	    if(active_sprite != -1)
	    {
	        get_sprite(active_sprite)->setPosition(get_rect().left, get_rect().top);
	        get_sprite(active_sprite)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
		    window.draw(*get_sprite(active_sprite));
		    
		    for(int i = 0; i < Spells.size(); ++i)
		    {
		        Spells[i]->draw(window);
	        }
	    }
	}
}

Actor *Hero::clone()
{
    Hero *temp = new Hero(*this);
    return temp;
}
