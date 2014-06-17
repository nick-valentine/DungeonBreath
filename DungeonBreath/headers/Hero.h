#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Actor.h"
#include "MagicMissile.h"

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
    static const int magic_missile_speed;
    static const int magic_missile_fire_rate;
 
 	int active_sprite;
 	int update_count;
 	
 	double acceleration_x;
 	double acceleration_y;
 	
 	MagicMissile my_missile;
 	
 	std::vector<Actor *> Spells;
 	bool last_space_pressed;
 	int magic_missile_timer;
 	
 	
 	enum Direction
 	{
 	    up,
 	    down,
 	    left,
 	    right
 	};
 	
 	Direction facing_dir;
 	
 	sf::Clock timer;
};

#endif //HERO_H
