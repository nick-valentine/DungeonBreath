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
 	void init(int pos_x, int pos_y, int size_x, int size_y);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 	
 	Actor *clone();
 private: 
 	int active_sprite;
 	int update_count;
};

#endif //ENEMYFOLLOWER_H
