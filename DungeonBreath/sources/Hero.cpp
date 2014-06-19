#include "../headers/Hero.h"

const double Hero::accel_x = 1.5;
const double Hero::accel_y = 1.5;
const double Hero::vel_damp = 10;
const int Hero::magic_missile_speed = 20;
const int Hero::magic_missile_fire_rate = 300000;
const int Hero::pug_nova_speed = 20;
const int Hero::pug_nova_fire_rate = 300000;

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
	facing_dir = down;
	
	timer.restart();
	
	magic_missile_timer = magic_missile_fire_rate;
	
	last_space_pressed = false;
	last_one_pressed = false;
	
	set_collide_type(All);
}

void Hero::update(int delta)
{
    if(get_alive())
    {
        magic_missile_timer -= delta;
        pug_nova_timer -= delta;
	    update_count++;
	
	    if(update_count%5 == 0)
	    {
		    active_sprite = (active_sprite + 1) % 3;
	    }
	
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	    {
	        acceleration_x = accel_x;
	        facing_dir = right;
	    }
	    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	    {
	        acceleration_x = -accel_x;
	        facing_dir = left;
	    }
	    else
	    {
	        acceleration_x = 0;
	    }   
	
	
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	    {
	        acceleration_y = -accel_y;
	        facing_dir = up;
	    }
	    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	    {
	        acceleration_y = accel_y;
	        facing_dir = down;
	    }
	    else
	    {
	        acceleration_y = 0;
	    }
	    
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	    {
	    	if(last_one_pressed == false && pug_nova_timer <= 0)
	    	{
			    double num_pugs = 15.0;
			    for(double i = 0; i < num_pugs; ++i)
			    {
			        Spells.push_back(new MagicMissile);
		            dynamic_cast<MagicMissile *>(Spells[Spells.size() - 1])->init(get_rect().left, 
		                                                                            get_rect().top, 
		                                                                            50, 
		                                                                            50, 
		                                                                            cos( (i * (360.0 / (num_pugs + 1)))) * 4, 
		                                                                            sin( (i * (360.0 / (num_pugs + 1)))) * 4, 
		                                                                            "./img/default.png");
			    }
			    pug_nova_timer = pug_nova_fire_rate;
	        }
	        last_one_pressed = true;
	    }
	    else
	    {
	    	last_one_pressed = false;
	    }
	    
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	    {
	        if(last_space_pressed == false && magic_missile_timer <= 0)
	        {
	            if(facing_dir == down)
	            {
	                Spells.push_back(new MagicMissile);
	                dynamic_cast<MagicMissile *>(Spells[Spells.size() - 1])->init(get_rect().left, 
	                                                                                get_rect().top, 
	                                                                                50, 50, 0, 
	                                                                                magic_missile_speed, 
	                                                                                "./img/default.png");
	            }
	            else if(facing_dir == up)
	            {
	                Spells.push_back(new MagicMissile);
	                dynamic_cast<MagicMissile *>(Spells[Spells.size() - 1])->init(get_rect().left, 
	                                                                                get_rect().top, 
	                                                                                50, 50, 0, 
	                                                                                -magic_missile_speed, 
	                                                                                "./img/default.png");
	            }
	            else if(facing_dir == left)
	            {
	                Spells.push_back(new MagicMissile);
	                dynamic_cast<MagicMissile *>(Spells[Spells.size() - 1])->init(get_rect().left, 
	                                                                                get_rect().top, 
	                                                                                50, 50, 
	                                                                                -magic_missile_speed, 0, 
	                                                                                "./img/default.png");
	            }
	            else if(facing_dir == right)
	            {
	                Spells.push_back(new MagicMissile);
	                dynamic_cast<MagicMissile *>(Spells[Spells.size() - 1])->init(get_rect().left, 
	                                                                               get_rect().top, 
	                                                                               50, 50, 
	                                                                               magic_missile_speed, 0, 
	                                                                               "./img/default.png");
	            }
	            
	            magic_missile_timer = magic_missile_fire_rate;
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
        /*for(int i = 0; i < last_collided.size(); ++i)
        {
            if(all_actors[last_collided[i].second]->get_type() == Enemy)
            {
                all_actors[last_collided[i].second]->kill();
            }
            
        }*/
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
    clone_common(temp);
    return temp;
}
