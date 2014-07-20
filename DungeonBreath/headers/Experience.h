#ifndef EXPERIENCE_H
#define EXPERIENCE_H


#include "Item.h"
#include <math.h>
#include <stdlib.h>


class Experience : public Item
{
	public:
		Experience();
		void init(int pos_x, int pos_y, int size_x, int size_y);
		
		void update(int delta);
		void draw(sf::RenderWindow &window);
		
	private:
		const static unsigned int radius = 2;
		const static unsigned int slow_factor = 100000;
	
		sf::Sprite my_sprite;
		int time_alive;
};

#endif //EXPERIENCE_H