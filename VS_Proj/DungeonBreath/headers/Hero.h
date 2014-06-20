#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Actor.h"
#include "MagicMissile.h"
#include "ActorFactory.h"

class Hero : public Actor
{
 public:
 	Hero();
 	void init(int pos_x, int pos_y, int size_x, int size_y);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 	
 	Actor *clone();
 private:
    static const double accel_x;
    static const double accel_y;
    static const double vel_damp;
    static const int magic_missile_speed;
    static const int magic_missile_fire_rate;
    static const int pug_nova_speed;
    static const int pug_nova_fire_rate;
 
 	int active_sprite;
 	int update_count;
 	
 	double acceleration_x;
 	double acceleration_y;
 	
 	//MagicMissile my_missile;
 	
 	MagicMissile *to_clone;
 	ActorFactory missile_factory;
 	
 	std::vector<Actor *> Spells;
 	bool last_space_pressed;
 	bool last_one_pressed;
 	int magic_missile_timer;
 	int pug_nova_timer;
 	
 	
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