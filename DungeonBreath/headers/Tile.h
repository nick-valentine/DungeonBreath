#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <math.h>

#include "Actor.h"
#include "TextureMap.h"

class Tile
{
 public:
    Tile();
	Tile(const Tile &other);
 	void init(int pos_x, int pos_y, int size_x, int size_y, int SpriteX, int SpriteY);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
	
	void set_rect(sf::IntRect new_rect);
	sf::IntRect get_rect();
	void set_hero(Actor *);
	
	sf::Sprite get_sprite();
 private:
	const static unsigned int min_distance = 50 * 11;
 
	sf::Sprite my_sprite;
	TextureMap my_map;
	sf::Texture *tex;
	sf::IntRect my_rect;
	Actor *hero;
};

#endif //TILE_H
