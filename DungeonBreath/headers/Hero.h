#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
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
 	
 	int acceleration_x;
 	int acceleration_y;
 	
 	int velocity_x;
 	int velocity_y;
};

#endif //HERO_H
