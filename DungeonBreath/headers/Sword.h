#ifndef SWORD_H
#define SWORD_H

#include <string>
#include "Actor.h"
#include "Attack.h"

class Sword : public Attack
{
	public:
		Sword();
		void init(int pos_x, int pos_y, int size_x, int size_y, std::string img_name);
		
		void update(int delta);
		void draw(sf::RenderWindow &window);
		
		Actor *clone();
	private:
		const static unsigned int anim_time = 30000;
		
		int anim_timer;
		int active_sprite;
		int rotation;
		
		bool first_run;
		
};

#endif //SWORD_H