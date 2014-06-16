#include "../headers/Hero.h"

Hero::Hero() : Actor()
{
	active_sprite = -1;
}

Hero::Hero(int pos_x, int pos_y, int size_x, int size_y)
	: Actor(pos_x, pos_y, size_x, size_y, "./img/Hero.png")
{
	add_sprite(0,0,100,100);
	add_sprite(100,0,100,200);
	add_sprite(0,100,100,200);

	active_sprite = 0;
}

void Hero::update(int delta)
{
	static int x = 0;
	x++;
	
	if(x%20 == 0)
	{
		active_sprite = (active_sprite + 1) % 3;
	}
}

void Hero::draw(sf::RenderWindow &window)
{
	if(active_sprite != -1)
	{
		window.draw(*get_sprite(active_sprite));
	}
}
