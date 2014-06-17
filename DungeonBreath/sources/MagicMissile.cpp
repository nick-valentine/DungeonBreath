#include "../headers/MagicMissile.h"

MagicMissile::MagicMissile()
{
    init(0, 0, 0, 0, 0, 0, "");
}

void MagicMissile::init(int pos_x, int pos_y, int size_x, int size_y, double vel_x, double vel_y, std::string img_name)
{
    Actor::init(pos_x, pos_y, size_x, size_y, "./img/default.png");
    
    add_sprite(0, 0, 100, 100);
    
    set_velocity_x(vel_x);
    set_velocity_y(vel_y);
}

void MagicMissile::update(int delta)
{
    if(get_alive())
    {
        common_update(delta);
        
        for(int i = 0; i < last_collided.size(); ++i)
        {
            if(all_actors[last_collided[i].second]->get_type() == Enemy)
            {
                all_actors[last_collided[i].second]->kill();
            }
                
        }
    }
}

void MagicMissile::draw(sf::RenderWindow &window)
{
    if(get_alive())
    {
        get_sprite(0)->setPosition(get_rect().left, get_rect().top);
        get_sprite(0)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
	    window.draw(*get_sprite(0));
	}
}
