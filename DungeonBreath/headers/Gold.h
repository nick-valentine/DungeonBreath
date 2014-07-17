#ifndef GOLD_H
#define GOLD_H

#include "Item.h"

class Gold : public Item
{
	public:
		Gold();
		void init(int pos_x, int pos_y, int size_x, int size_y);
		
		void update(int delta);
		void draw(sf::RenderWindow &window);
	private:
		sf::Sprite my_sprite;
};

#endif