#include "../headers/MagicMissile.h"

MagicMissile::MagicMissile() : Attack()
{
    //init(0, 0, 0, 0, 0, 0, "");
}

void MagicMissile::init(int pos_x, int pos_y, int size_x, int size_y, double vel_x, double vel_y, std::string img_name)
{
    Attack::init(pos_x, pos_y, size_x, size_y, 7, img_name);
    add_sprite(0, 0, 100, 100);
    
    set_velocity_x(vel_x);
    set_velocity_y(vel_y);
    my_type = Spell;
    set_collide_type(BlocksOnly);
    
	knockback = 20;
    lifetime = lifespan;
}

void MagicMissile::update(int delta)
{
    if(get_alive())
    {
        lifetime -= delta;
        if(lifetime <= 0)
        {
            kill();
        }
        common_update(delta);
        
        for(int i = 0; i < last_collided.size(); ++i)
        {
            if(last_collided[i].second->get_type() == Enemy)
            {
				last_collided[i].second->hurt(1, last_collided[i].first, this, knockback);
				kill();
                //last_collided[i].second->kill();
                //kill();
                //break;
            }
            else if(last_collided[i].second->get_type() == Block)
            {
                kill();
                break;
            } 
        }
		
    }
}

void MagicMissile::draw(sf::RenderWindow &window)
{
    if(get_alive())
    {
		if((abs(hero->get_rect().left - get_rect().left) + abs(hero->get_rect().top - get_rect().top)) < min_distance + min_distance)
		{
			get_sprite(0)->setPosition(get_rect().left, get_rect().top);
			get_sprite(0)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
			window.draw(*get_sprite(0));
		}
	}
}

Actor *MagicMissile::clone()
{
    MagicMissile *temp = new MagicMissile(*this);
    set_velocities(temp);
    return temp;
}
