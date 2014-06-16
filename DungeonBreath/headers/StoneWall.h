#ifndef STONEWALL_H
#define STONEWALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Actor.h"

class StoneWall : public Actor
{
 public:
    StoneWall();
 	void init(int pos_x, int pos_y, int size_x, int size_y);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 private:
 
};

#endif //STONEWALL_H
