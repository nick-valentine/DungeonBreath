#include "../headers/MagicNova.h"

const int MagicNova::lifespan = 200000;
const int MagicNova::num_missiles = 15;

MagicNova::MagicNova() : Attack()
{
	
}

void MagicNova::init(int pos_x, int pos_y, int size_x, int size_y, double vel_x, double vel_y, bool will_be_cloned, std::string img_name)
{
	
	//this itself will not collide with anything, only the
	//missiles contained within will.
	
	Attack::init(pos_x, pos_y, size_x, size_y, 7, img_name);
    add_sprite(0, 0, 100, 100);
    
    set_velocity_x(vel_x);
    set_velocity_y(vel_y);
    my_type = Spell;
    set_collide_type(Nothing);
    
    lifetime = lifespan;
    
    if(!will_be_cloned)
    {
		for(int i = 0; i < num_missiles; ++i)
		{
			MagicMissile *temp = new MagicMissile;
						temp->init(get_rect().left, 
				                                get_rect().top, 
				                                50, 
				                                50, 
				                                cos( (i * (360.0 / (num_missiles + 1)))) * 4, 
				                                sin( (i * (360.0 / (num_missiles + 1)))) * 4, 
				                                "./img/MagicMissile.png");
			missiles.push_back(temp);
		}
    }
}

void MagicNova::update(int delta)
{
	lifetime -= delta;
	if(lifetime >= 0)
	{
		for(int i = 0; i < missiles.size(); ++i)
		{
			missiles[i]->update(delta);
		}
	}
	else
	{
		kill();
	}
}

void MagicNova::draw(sf::RenderWindow &window)
{
	for(int i = 0; i < missiles.size(); ++i)
	{
		missiles[i]->draw(window);
	}
}

Actor *MagicNova::clone()
{
	MagicNova *temp = new MagicNova(*this);
    set_velocities(temp);
    temp->init(get_rect().left, get_rect().top, get_rect().width, get_rect().height, get_velocity_x(), get_velocity_y(), false, get_image_name());
    return temp;
}
