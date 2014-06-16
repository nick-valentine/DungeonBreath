#include "../headers/Actor.h"

Actor::Actor()
{
	pos_x = pos_y = size_x = size_y = 0;
}

Actor::Actor(int pos_x, int pos_y, int size_x, int size_y, std::string image_name)
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

void Actor::add_sprite(int pos_x, int pos_y, int width, int height)
{
	sf::Sprite temp;
	temp.setTexture(*tex);
	temp.setTextureRect(sf::IntRect(pos_x, pos_y, width, height));
	sprites.push_back(temp);
}
