#include "../headers/Item.h"

std::vector<Item *> Item::my_items;
std::vector<Item *> Item::all_items;

Item::Item()
{
	uneeded = false;
}

void Item::init(int pos_x, int pos_y, int size_x, int size_y, std::string image_name)
{
	this->rect = sf::IntRect(pos_x, pos_y, size_x, size_y);
	this->tex = my_map.request(image_name);
	this->tex_name = image_name;
}

void Item::kill()
{
	this->uneeded = true;
}

bool Item::dead()
{
	return uneeded;
}

int Item::get_speed()
{
	return speed;
}

sf::IntRect *Item::get_rect()
{
	return &this->rect;
}

Item::Type Item::get_type()
{
	return this->my_type;
}

Item * Item::clone()
{
}

std::vector<Item *> *Item::get_items()
{
	return &my_items;
}

void Item::update_all(int delta)
{
	for(int i = 0; i < my_items.size(); ++i)
	{
		my_items[i]->update(delta);
	}
}

void Item::draw_all(sf::RenderWindow &window)
{
	for(int i = 0; i < my_items.size(); ++i)
	{
		my_items[i]->draw(window);
	}
}

void Item::add_item(Item *x)
{
	my_items.push_back(x);
	all_items.push_back(x);
}

void Item::clear_items()
{
	for(int i = 0; i < all_items.size(); ++i)
	{
		delete all_items[i];
	}
	all_items.clear();
	my_items.clear();
}

void Item::clean_dead_items()
{

	for(int i = 0; i < my_items.size(); ++i)
	{
		if(my_items[i]->dead() == true)
		{
			my_items[i];
			my_items[i] = my_items[my_items.size() - 1];
			my_items.pop_back();
		}
	}
	
}