#include "../headers/Actor.h"

std::vector<Actor *> Actor::all_actors;
std::vector<Actor *> Actor::actor_list;

Actor::Actor()
{
    //init(0, 0, 0, 0, "./img/default.png");
    all_actors.push_back(this);
	actor_list.push_back(this);
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
	
	this->my_collide = All;
}

void Actor::common_update(int delta)
{
	//this->rect.left += velocity_x;
	//this->rect.top += velocity_y;
	
    this->move_and_resolve_collision();
}

sf::Rect<int> Actor::get_rect() const 
{
	return this->rect;
}

void Actor::set_rect(sf::Rect<int> x)
{
	this->rect = x;
}

double Actor::get_velocity_x() const
{
	return this->velocity_x;
}

double Actor::get_velocity_y() const
{
	return this->velocity_y;
}

void Actor::set_velocity_x(double x)
{
	this->velocity_x = x;
}

void Actor::set_velocity_y(double x)
{
	this->velocity_y = x;
}

std::string Actor::get_image_name() const
{
	return this->texture_name;
}

sf::Texture *Actor::get_texture() const
{
	return this->tex;
}

void Actor::set_texture(std::string image_name)
{
	tex = my_map.request(image_name);
	texture_name = image_name;
}

void Actor::set_sprites(std::vector<sf::Sprite> sprites)
{
	this->sprites.clear();
	for(int i = 0; i < sprites.size(); ++i)
	{
		this->sprites.push_back(sprites[i]);
	}
}

std::vector<sf::Sprite> Actor::get_sprites() const
{
	return this->sprites;
}

sf::Sprite *Actor::get_sprite(int x)
{
	return &this->sprites[x];
}

int Actor::get_num_sprites() const
{
    return this->sprites.size();
}

int Actor::add_sprite(int pos_x, int pos_y, int width, int height)
{
	sf::Sprite temp;
	temp.setTexture(*tex);
	temp.setTextureRect(sf::IntRect(pos_x, pos_y, width, height));
	sprites.push_back(temp);
	
	return sprites.size() - 1;
}

Actor::ActorType Actor::get_type() const
{
    return this->my_type;
}

Actor::CollideResolve Actor::get_collide_type() const
{
    return this->my_collide;
}

void Actor::set_collide_type(CollideResolve x)
{
    this->my_collide = x;
}

bool Actor::get_alive() const
{
    return this->alive;
}

void Actor::set_alive(bool x)
{
    alive = x;
}

void Actor::kill()
{
    this->alive = false;
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

Actor::CollideType Actor::move_and_resolve_collision()
{
    CollideType return_val = C_None;
    last_collided.clear();
    
    std::vector<int> collided;
    this->rect.left += velocity_x;
    for(int i = 0; i < all_actors.size(); ++i)
    {
    	if(i != my_index)
    	{
		    Actor* x = all_actors[i];
		    if(is_colliding(x) && x->get_alive() && get_alive())
		    {
		        sf::Rect<int> intersection;
		        rect.intersects(x->get_rect(), intersection);
		        bool move_me;
		        
		        if(my_collide == All)
		        {
		            if(x->get_collide_type() != Nothing && x->get_collide_type() != BlocksOnly)
		            {
		                move_me = true;
		            }
		            else
		            {
		                move_me = false;
		            }
		        }
		        else if(my_collide == BlocksOnly)
		        {
		            if(x->get_collide_type() == BlocksOnly)
		            {
		                move_me = false;
		            }
		            else
		            {
		                move_me = false;
		            }
		        }
		        else if(my_collide == Nothing)
		        {
		            move_me = false;
		        }
		        
		        if(rect.left < intersection.left)
	        	{
	        	    if(move_me)
	        	    {
	        		    rect.left -= intersection.width;
        		    }
	        		return_val = C_Left;
	        	}
	        	else
	        	{
	        	    
	        	    if(move_me)
	        	    {
	        		    rect.left += intersection.width;
        		    }
	        		return_val = C_Right;
	        	}
		        collided.push_back(i);
        		last_collided.push_back(std::pair<CollideType, Actor*>(return_val, all_actors[i]) );
		    }
		}
	}
	
	this->rect.top += velocity_y;
	for(int i = 0; i < all_actors.size(); ++i)
    {
    	if(i != my_index)
    	{
		    Actor* x = all_actors[i];
		    if(is_colliding(x) && x->get_alive() && get_alive())
		    {
		        sf::Rect<int> intersection;
		        rect.intersects(x->get_rect(), intersection);
		        bool move_me;
		        
		        if(my_collide == All)
		        {
		            if(x->get_collide_type() != Nothing && x->get_collide_type() != BlocksOnly)
		            {
		                move_me = true;
		            }
		            else
		            {
		                move_me = false;
		            }
		        }
		        else if(my_collide == BlocksOnly)
		        {
		            if(x->get_collide_type() == BlocksOnly)
		            {
		                move_me = false;
		            }
		            else
		            {
		                move_me = false;
		            }
		        }
		        else if(my_collide == Nothing)
		        {
		            move_me = false;
		        }
		        
		        if(rect.top < intersection.top)
	        	{
	        	    if(move_me)
	        	    {
	        		    rect.top -= intersection.height;
	        		}
	        		return_val = C_Top;
	        	}
	        	else
	        	{
	        	    if(move_me)
	        	    {
	        		    rect.top += intersection.height;
        		    }
	        		return_val = C_Bottom;
	        	}
	        	bool found = false;
		        for(int k = 0; k < collided.size(); ++k)
		        {
		        	if(collided[k] == i)
		        	{
		        		found = true;
		        		break;
		        	}
		        }
		        if(found == false)
		        {
        			last_collided.push_back(std::pair<CollideType, Actor*>(return_val, all_actors[i]) );
        		}
		    }
		}
	}
    return return_val;
}

void Actor::unregister()
{
    all_actors[my_index] = all_actors[all_actors.size() - 1];
    all_actors.pop_back();
    all_actors[my_index]->set_index(my_index);
}

int Actor::get_index() const
{
    return this->my_index;
}

void Actor::set_index(int x)
{
    this->my_index = x;
}

std::vector<Actor *>* Actor::get_all_actors()
{
    return &all_actors;
}

void Actor::clear_dead()
{
	for(int i = 0; i < all_actors.size(); ++i)
    {
    	if(all_actors[i]->get_alive() == false)
    	{
	    	all_actors[i] = all_actors[all_actors.size() - 1];
	    	all_actors.pop_back();
	    	all_actors[i]->set_index(i);
	    	--i;
    	}
    }
}

void Actor::clear_all_actors()
{
	for(int i = 0; i < actor_list.size(); ++i)
	{
		delete actor_list[i];
	}
}
