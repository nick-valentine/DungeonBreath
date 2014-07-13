#ifndef ENEMY_VAMPIRE_H
#define ENEMY_VAMPIRE_H

#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Actor.h"

class Enemy_Vampire : public Actor
{
	public:
		enum State
		{
			idle,
			chasing,
			attacking
		};
		
		Enemy_Vampire();
		Enemy_Vampire(const Enemy_Vampire &other);
		void init(int pos_x, int pos_y, int size_x, int size_y);
		
		void update(int delta);
		void draw(sf::RenderWindow &window);
		
		Actor *clone();
	private:
		const static unsigned int idle_anim_time = 300000;
		const static unsigned int chasing_anim_time = 300000;
		const static unsigned int attacking_anim_time = 120000;
		const static unsigned int distance_before_chase = 1000;
		const static unsigned int distance_before_attack = 75;
	
		Actor *hero;
	
		int active_sprite;
		unsigned long int update_count;
		unsigned long int time_alive;
		
		State my_state;
		std::vector<int> idle_anim;
		int idle_index;
		int idle_anim_timer;
		std::vector<int> chasing_anim;
		int chasing_index;
		int chasing_anim_timer;
		std::vector<int> attacking_anim;
		int attacking_index;
		int attacking_anim_timer;
		
		bool look_left;
};

#endif //ENEMY_VAMPIRE_H
