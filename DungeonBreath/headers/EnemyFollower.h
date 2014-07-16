#ifndef ENEMYFOLLOWER_H
#define ENEMYFOLLOWER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Actor.h"

class EnemyFollower : public Actor
{
 public:
 	EnemyFollower();
	EnemyFollower(const EnemyFollower &other);
 	void init(int pos_x, int pos_y, int size_x, int size_y);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
	void hurt(int raw_dmg, CollideType direction, Actor *attacker, int knockback);
 	
 	Actor *clone();

	int get_active_sprite() const;
	int get_update_count() const;
 private: 
	const static unsigned int jump_speed = 10;
	const static double hurt_debounce = 600000;
	
	int health;
	int hurt_timer;
 	int active_sprite;
 	int update_count;
};

#endif //ENEMYFOLLOWER_H
