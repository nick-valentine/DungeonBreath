#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "Actor.h"

class Tile : public Actor
{
 public:
    Tile();
 	void init(int pos_x, int pos_y, int size_x, int size_y, int SpriteX, int SpriteY);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 	
 	Actor *clone();
 private:
 
};

#endif //TILE_H
