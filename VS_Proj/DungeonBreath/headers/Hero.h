#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Actor.h"
#include "MagicMissile.h"
#include "MagicNova.h"
#include "ActorFactory.h"
#include "Direction.h"

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
 
 	int active_sprite;
 	int update_count;
 	
 	double acceleration_x;
 	double acceleration_y;

	std::vector<Attack *> Spells;
	std::vector<int> Keys; 	
	std::vector<bool> Keys_last_pressed;
 	//MagicMissile *magic_missile;
 	//MagicNova *magic_nova;
 	ActorFactory missile_factory;
 	
 	//bool last_space_pressed;
 	//bool last_one_pressed;
 	
 	Direction facing_dir;
};

#endif //HERO_H
