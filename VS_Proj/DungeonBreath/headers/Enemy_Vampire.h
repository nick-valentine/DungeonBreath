#ifndef ENEMY_VAMPIRE_H
#define ENEMY_VAMPIRE_H

#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Actor.h"

class Enemy_Vampire : public Actor
{
	public:
		Enemy_Vampire();
		Enemy_Vampire(const Enemy_Vampire &other);
		void init(int pos_x, int pos_y, int size_x, int size_y);
		
		void update(int delta);
		void draw(sf::RenderWindow &window);
		
		Actor *clone();
	private:
		int active_sprite;
		unsigned long int update_count;
};

#endif //ENEMY_VAMPIRE_H
