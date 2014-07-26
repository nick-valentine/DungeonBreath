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
#include "Sword.h"
#include "ActorFactory.h"
#include "Direction.h"
#include "Item.h"
#include "Gold.h"
#include "Experience.h"
#include "SwordItem.h"

class Hero : public Actor
{
 public:
 	Hero();
	~Hero();
	Hero(const Hero &other);
 	void init(int pos_x, int pos_y, int size_x, int size_y);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
	void hurt(int raw_dmg, CollideType direction, Actor *attacker, int knockback);
 	
 	Actor *clone();
	
	int get_vacuum_radius() const;
	void set_vacuum_radius(int x);
	
	int get_gold() const;
	int get_exp() const;
	
	std::vector<Item *>* get_inventory();
 private:
    const static double accel_x = 1.5;
    const static double accel_y = 1.5;
    const static double vel_damp = 10;
	const static double hurt_debounce = 600000;
	const static unsigned int max_inventory_size = 30;
	
	int health;
	int hurt_timer;
	
	int vacuum_radius;
	int pickup_radius;
 
	int gold;
	int exp;
	
	std::vector<Item *> inventory;
 
 	int active_sprite;
 	int update_count;
 	
 	double acceleration_x;
 	double acceleration_y;

	std::vector<Attack *> Spells;
	std::vector<int> Keys; 	
	std::vector<bool> Keys_last_pressed;
 	ActorFactory missile_factory;
 	
 	Direction facing_dir;
};

#endif //HERO_H
