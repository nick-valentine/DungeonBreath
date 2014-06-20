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
 	
 	Actor *clone();

	int get_active_sprite() const;
	int get_update_count() const;
 private: 
 	int active_sprite;
 	int update_count;

	int time_to_collide;
};

#endif //ENEMYFOLLOWER_H
