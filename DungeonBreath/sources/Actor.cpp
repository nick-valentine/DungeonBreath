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
    this->pos_x = pos_x;
	this->pos_y = pos_y;
	
	this->size_x = size_x;
	this->size_y = size_y;
	
	this->tex = my_map.request(image_name);
	this->texture_name = image_name;
}

int Actor::get_pos_x() const
{
	return this->pos_x;
}

int Actor::get_pos_y() const
{
	return this->pos_y;
}

int Actor::get_size_x() const
{
	return this->size_x;
}

int Actor::get_size_y() const
{
	return this->size_y;
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

sf::Sprite *Actor::get_sprite(int x)
{
	return &this->sprites[x];
}

void Actor::set_pos_x(int x)
{
	this->pos_x = x;
}

void Actor::set_pos_y(int x)
{
	this->pos_y = x;
}

void Actor::set_size_x(int x)
{
	this->size_x = x;
}

void Actor::set_size_y(int x)
{
	this->size_y = x;
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
        //(pos_x + size_x > x->get_pos_x() && pos_x + size_x < x->get_pos_x() + x->get_size_x()) &&
        if(((pos_x > x->get_pos_x() && pos_x < x->get_pos_x() + x->get_size_x()) ||
        (pos_x + size_x > x->get_pos_x() && pos_x + size_x < x->get_pos_x() + x->get_size_x())) 
        && (
        (pos_y > x->get_pos_y() && pos_y < x->get_pos_y() + x->get_size_y()) ||
        (pos_y + size_y > x->get_pos_y() && pos_y + size_y < x->get_pos_y() + x->get_size_y())))
        {
            return true;
        }
}

bool Actor::resolve_collision()
{
    for(int i = 0; i < all_actors.size(); ++i)
    {
        Actor* x = all_actors[i];
        if(is_colliding(x))
        {
            pos_x = old_pos_x;
            pos_y = old_pos_y;
        }
        
    }
}

void Actor::update_old_pos()
{
    old_pos_x = pos_x;
    old_pos_y = pos_y;
}

