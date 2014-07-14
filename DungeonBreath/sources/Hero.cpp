#include "../headers/Hero.h"

Hero::Hero() : Actor()
{
}

void Hero::init(int pos_x, int pos_y, int size_x, int size_y)
{
    Actor::init(pos_x, pos_y, size_x, size_y, "./img/Hero.png");

    add_sprite(0,0,100,100);
	add_sprite(100,0,100,100);
	add_sprite(0,100,100,100);
	
	hero = this;

	health = 5;
	
	active_sprite = 0;
	update_count = 0;
	
	acceleration_x = 0;
	acceleration_y = 0;
	
	my_type = Player;
	facing_dir = D_Down;
	
	set_collide_type(All);
	
	Keys.push_back(sf::Keyboard::Num1);
	Keys_last_pressed.push_back(false);
	Spells.push_back(new MagicMissile);
	dynamic_cast<MagicMissile *>(Spells[Spells.size() - 1])->init(500, 500, 50, 50, 0, 0, "img/MagicMissile.png");
	Spells[Spells.size() - 1]->unregister();
	missile_factory.init(Spells[Spells.size() - 1], 0, 300000, 0, 0);
	
	Keys.push_back(sf::Keyboard::Num2);
	Keys_last_pressed.push_back(false);
	Spells.push_back(new MagicNova);
	dynamic_cast<MagicNova *>(Spells[Spells.size() - 1])->init(500, 500, 50, 50, 0, 0, true, "img/MagicMissile.png");
	Spells[Spells.size() - 1]->unregister();
	missile_factory.add_actor(Spells[Spells.size() - 1],0, 300000);
	
	Keys.push_back(sf::Keyboard::Num3);
	Keys_last_pressed.push_back(false);
	Spells.push_back(new Sword);
	dynamic_cast<Sword *>(Spells[Spells.size() - 1])->init(500, 500, 200, 200, "img/Sword.png");
	Spells[Spells.size() - 1]->unregister();
	missile_factory.add_actor(Spells[Spells.size() - 1], 0, 30000);
}

void Hero::update(int delta)
{
    if(get_alive())
    {
		hurt_timer -= delta;
		//std::cout<<health<<std::endl;
        missile_factory.update(delta);
        for(int i = 0; i < Spells.size(); ++i)
        {
        	Spells[i]->set_rect(get_rect());
        	Spells[i]->set_facing(facing_dir);
        }
        
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
	    
	    for(int i = 0; i < Keys.size(); ++i)
	    {
	    	if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(Keys[i])))
	    	{
	    		if(Keys_last_pressed[i] == false)
	    		{
	    			missile_factory.spawn(i);
	    		}
	    		Keys_last_pressed[i] = true;
	    	}
	    	else
	    	{
	    		Keys_last_pressed[i] = false;
	    	}
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
		    
	    }
	}
}

void Hero::hurt(int raw_dmg, CollideType direction, Actor *attacker)
{
	if(hurt_timer <= 0)
	{
		hurt_timer = hurt_debounce;
		health -= raw_dmg;
		if(direction == C_Top)
		{
			set_velocity_y( -jump_speed );
		}
		else if(direction == C_Bottom)
		{
			set_velocity_y( jump_speed );
		}
		else if(direction == C_Left)
		{
			set_velocity_x( jump_speed );
		}
		else if(direction == C_Right)
		{
			set_velocity_x( -jump_speed );
		}
	}
}

Actor *Hero::clone()
{
    Hero *temp = new Hero(*this);
    return temp;
}
