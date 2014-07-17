#include "../headers/Gold.h"

Gold::Gold() : Item()
{
	
}

void Gold::init(int pos_x, int pos_y, int size_x, int size_y)
{
	Item::init(pos_x, pos_y, size_x, size_y, "./img/Gold.png");
	my_sprite.setTexture(*tex);
	my_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	
	this->my_type = Item::Gold;
}

void Gold::update(int delta)
{

}

void Gold::draw(sf::RenderWindow &window)
{
	if(!uneeded)
	{
		my_sprite.setPosition(rect.left, rect.top);
		my_sprite.setScale(rect.width / 50.0, rect.height / 50.0);
		window.draw(my_sprite);
	}
}
