#ifndef STONEWALL_H
#define STONEWALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "Actor.h"

class Wall : public Actor
{
 public:
    Wall();
 	void init(int pos_x, int pos_y, int size_x, int size_y, std::string img_name);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 private:
 
};

#endif //STONEWALL_H
