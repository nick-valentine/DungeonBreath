#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Actor.h"

class Hero : public Actor
{
 public:
 	Hero();
 	Hero(int pos_x, int pos_y, int size_x, int size_y);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 private:
 	int active_sprite;
};

#endif //HERO_H
