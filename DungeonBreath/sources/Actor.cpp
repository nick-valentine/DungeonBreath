#include "../headers/Actor.h"

Actor::Actor()
{
	init(0, 0, 0, 0, "./img/default.png");
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

bool is_colliding(Actor *x) const
{
    return (abs(pos_x - x.get_pos_x()) * 2 < (size_x + x.get_size_x()) &&
            (abs(pos_y - x.get_pos_y()) * 2 < (size_y + x.get_size_y());
}

bool resolve_collision(Actor *x)
{
    if(is_colliding(x))
    {
        /*
          left_intersect;
          right_intersect;
          top_intersect;
          bottom_intersect;
        */
        int intersect[4];
        
        if(pos_x > x.get_pos_x() && pos_x < x.get_pos_x() + x.get_size_x())
        {
            intersect[0] = x.get_pos_x() + x.get_size_x() - pos_x;
        }
        if(pos_x + size_x > x.get_pos_x() && pos_x + size_x < x.get_pos_x() + x.get_size_x())
        {
            intersect[1] = pos_x + size_x < x.get_pos_x() + x.get_size_x()
        }
        
        if(pos_y > x.get_pos_y() && pos_y < x.get_pos_y() + x.get_size_y())
        {
            intersect[2] = x.get_pos_y() + x.get_size_y() - pos_y;
        }
        if(pos_y + size_y > x.get_pos_y() && pos_y + size_y < x.get_pos_y() + x.get_size_y())
        {
            intersect[3] = pos_y + size_y < x.get_pos_y() + x.get_size_y()
        }
        
        int min = 0;
        for(int i = 1; i < 4; ++i)
        {
            if(intersect[i] < intersect[min])
            {
                min = i;
            }
        }
        
        //fix smallest offender
        if(min == 0)
        {
            //left
            pos_x -= intersect[0];
        }
        else if(min == 1)
        {
            //right
            pos_x += intersect[1];
        }
        else if(min == 2)
        {
            //top
            pos_y -= intersect[2];
        }
        else if(min == 3)
        {
            //bottom
            pos_y += intersect[3];
        }
        
    }
}

