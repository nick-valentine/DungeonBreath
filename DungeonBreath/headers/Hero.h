#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <algorithm>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Actor.h"

class Hero : public Actor
{
 public:
 	Hero();
 	void init(int pos_x, int pos_y, int size_x, int size_y);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 private:
    static const double accel_x;
    static const double accel_y;
    static const double vel_damp;
 
 	int active_sprite;
 	
 	double acceleration_x;
 	double acceleration_y;
 	
 	double velocity_x;
 	double velocity_y;
};

#endif //HERO_H
