#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "Actor.h"

class Wall : public Actor
{
 public:
    Wall();
	Wall(const Wall &other);
 	void init(int pos_x, int pos_y, int size_x, int size_y,int sprite_pos_x, int sprite_pos_y, std::string img_name);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 	
 	Actor *clone();
 private:
	std::string img_name;
	int sprite_x;
	int sprite_y;
};

#endif //WALL_H
