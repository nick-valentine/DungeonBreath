#include "../headers/Experience.h"

Experience::Experience() : Item()
{

}

void Experience::init(int pos_x, int pos_y, int size_x, int size_y)
{
	Item::init(pos_x, pos_y, size_x, size_y, "./img/Exp.png");
	my_sprite.setTexture(*tex);
	my_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	
	this->time_alive = rand(); //not 0 so that exp created at the same time will not spin in the same way
	
	this->my_type = Item::Exp;
}

void Experience::update(int delta)
{
	time_alive += delta;
	
	rect = sf::IntRect(
						rect.left + 0.25 + (cos(time_alive / slow_factor) * radius),
						rect.top + 0.25 + (sin(time_alive / slow_factor) * radius),
						rect.width,
						rect.height
						);
	
}

void Experience::draw(sf::RenderWindow &window)
{
	if(!uneeded)
	{
		my_sprite.setPosition(rect.left, rect.top);
		my_sprite.setScale(rect.width / 50.0, rect.height / 50.0);
		window.draw(my_sprite);
	}
}