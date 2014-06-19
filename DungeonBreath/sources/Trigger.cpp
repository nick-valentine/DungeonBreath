#include "../headers/Trigger.h"

Trigger::Trigger()
{
    //default to always on when not initialized
    active = true;
}

void Trigger::init(int pos_x, int pos_y, int size_x, int size_y, Type type, Actor::ActorType actor_type)
{
    Actor::init(pos_x, pos_y, size_x, size_y, "./img/default.png");
    
    add_sprite(0, 0, 100, 100);
    
    my_type = Actor::Trigger;
    
    trigger_type = type;
    
    active = false;
    
    this->actor_type = actor_type;
    
    set_collide_type(Nothing);
    
    last_on_trigger = false;
}

void Trigger::update(int delta)
{
    if(get_alive())
    {
        common_update(delta);
        
        if(trigger_type == Press)
        {
            active = false;
        }
        else if(trigger_type == Latch)
        {
            if(active == true)
            {
                return;
            }
        }
        bool collide_found = false;
        for(int i = 0; i < last_collided.size(); ++i)
        {
            if(actor_type == Null || actor_type == last_collided[i].second->get_type())
            {
                if(trigger_type == Press || trigger_type == Latch)
                {
                    active = true;
                }
                else if(trigger_type == Switch)
                {
                    if(last_on_trigger == false)
                    {
                        active = !active;
                    }
                }
                last_on_trigger = true;
                collide_found = true;
                break;
            }
        }
        if(collide_found == false)
        {
            last_on_trigger = false;
        }
    }
}

void Trigger::draw(sf::RenderWindow &window)
{
    get_sprite(0)->setPosition(get_rect().left, get_rect().top);
    get_sprite(0)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
	window.draw(*get_sprite(0));
}

bool Trigger::get_active()
{
    return this->active;
}

Trigger::Type Trigger::get_trigger_type()
{
    return this->trigger_type;
}

void Trigger::set_trigger_type(Trigger::Type x)
{
    this->trigger_type = x;
}

Actor *Trigger::clone()
{
    return new Trigger(*this);
}
