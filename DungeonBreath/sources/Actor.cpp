#include "../headers/Actor.h"

std::vector<Actor *> Actor::all_actors;

Actor::Actor()
{
    init(0, 0, 0, 0, "./img/default.png");
    all_actors.push_back(this);
    my_index = all_actors.size() - 1;
}

void Actor::init(int pos_x, int pos_y, int size_x, int size_y, std::string image_name)
{
	this->rect = sf::Rect<int>(pos_x, pos_y, size_x, size_y);
	
	velocity_x = 0;
	velocity_y = 0;
	
	alive = true;
	
	this->tex = my_map.request(image_name);
	this->texture_name = image_name;
}

void Actor::common_update(int delta)
{
	this->rect.left += velocity_x;
	this->rect.top += velocity_y;
	
    this->resolve_collision();
}

sf::Rect<int> Actor::get_rect()
{
	return this->rect;
}

std::vector<Actor *>* Actor::get_all_actors()
{
    return &all_actors;
}

double Actor::get_velocity_x() const
{
	return this->velocity_x;
}

double Actor::get_velocity_y() const
{
	return this->velocity_y;
}

std::string Actor::get_image_name() const
{
	return this->texture_name;
}

sf::Texture *Actor::get_texture() const
{
	return this->tex;
}

std::vector<sf::Sprite> Actor::get_sprites() const
{
	return this->sprites;
}

int Actor::get_num_sprites() const
{
    return this->sprites.size();
}

Actor::ActorType Actor::get_type() const
{
    return this->my_type;
}

int Actor::get_index() const
{
    return this->my_index;
}

bool Actor::get_alive() const
{
    return this->alive;
}

void Actor::set_alive(bool x)
{
    alive = x;
}

sf::Sprite *Actor::get_sprite(int x)
{
	return &this->sprites[x];
}

void Actor::set_rect(sf::Rect<int> x)
{
	this->rect = x;
}

void Actor::set_velocity_x(double x)
{
	this->velocity_x = x;
}

void Actor::set_velocity_y(double x)
{
	this->velocity_y = x;
}

void Actor::set_index(int x)
{
    this->my_index = x;
}

void Actor::kill()
{
    this->alive = false;
    //all_actors[my_index] = all_actors[all_actors.size() - 1];
    //all_actors.pop_back();
    //all_actors[my_index]->set_index(my_index);
}

void Actor::set_texture(std::string image_name)
{
	tex = my_map.request(image_name);
	texture_name = image_name;
}

int Actor::add_sprite(int pos_x, int pos_y, int width, int height)
{
	sf::Sprite temp;
	temp.setTexture(*tex);
	temp.setTextureRect(sf::IntRect(pos_x, pos_y, width, height));
	sprites.push_back(temp);
	
	return sprites.size() - 1;
}

bool Actor::is_colliding(Actor *x) const
{
    
    if(rect.intersects(x->get_rect()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Actor::CollideType Actor::resolve_collision()
{
    CollideType return_val = None;
    last_collided.clear();
    for(int i = 0; i < all_actors.size(); ++i)
    {
    	if(i != my_index)
    	{
		    Actor* x = all_actors[i];
		    if(is_colliding(x) && x->get_alive())
		    {
		        sf::Rect<int> intersection;
		        rect.intersects(x->get_rect(), intersection);
		        
		        if(intersection.height < (intersection.width + 20))
		        {
		        	if(rect.top < intersection.top)
		        	{
		        	    if((my_type != Spell && all_actors[i]->get_type() != Spell) || x->get_type() == Block)
		        	    {
		        		    rect.top -= intersection.height;
		        		}
		        		return_val = Top;
		        	}
		        	else
		        	{
		        	    if((my_type != Spell && all_actors[i]->get_type() != Spell) || x->get_type() == Block)
		        	    {
		        		    rect.top += intersection.height;
	        		    }
		        		return_val = Bottom;
		        	}
		        }
		        else
		        {
		        	if(rect.left < intersection.left)
		        	{
		        	    if((my_type != Spell && all_actors[i]->get_type() != Spell) || x->get_type() == Block)
		        	    {
		        		    rect.left -= intersection.width;
	        		    }
		        		return_val = Left;
		        	}
		        	else
		        	{
		        	    if((my_type != Spell && all_actors[i]->get_type() != Spell) || x->get_type() == Block)
		        	    {
		        		    rect.left += intersection.width;
	        		    }
		        		return_val = Right;
		        	}
		        }
		        
        		last_collided.push_back(std::pair<CollideType, int>(return_val, i) );
		    }
		}
	}
    return return_val;
}

void Actor::clone_common(Actor *newActor)
{
	all_actors.push_back(newActor);
	newActor->set_index(all_actors.size() - 1);
}

void Actor::unregister()
{
    all_actors[my_index] = all_actors[all_actors.size() - 1];
    all_actors.pop_back();
    all_actors[my_index]->set_index(my_index);
}
