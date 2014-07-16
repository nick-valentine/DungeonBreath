#ifndef MAGICMISSILE_H
#define MAGICMISSILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>
#include "Actor.h"
#include "Attack.h"

class MagicMissile : public Attack
{
 public:
    MagicMissile();
 	void init(int pos_x, int pos_y, int size_x, int size_y, double vel_x, double vel_y, std::string img_name);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 	
 	Actor *clone();
 private:
    const static int lifespan = 3000000;
	
	int knockback;
    
    int lifetime;
 
};

#endif //MAGICMISSILE_H
