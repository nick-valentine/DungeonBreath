#ifndef TILESET_H
#define TILESET_H

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Files.h"
#include "Actor.h"
#include "Tile.h"
#include "Hero.h"
#include "EnemyFollower.h"
#include "Wall.h"
#include "ActorFactory.h"
#include "Enemy_Vampire.h"

class TileSet
{
 public:
 	TileSet();
	~TileSet();
 	void init(std::string filename, int xpos, int ypos, bool &HeroSpawned, bool OnlyLoadSides = false);
 	
 	void update(int delta);
 	
 	void draw_tiles(sf::RenderWindow &window);
 	void draw_actors(sf::RenderWindow &window);
 	
	void move(int dx, int dy);

 	bool ready() const;
	
	void set_hero(Actor *hero);
	
	sf::Vector2i get_pos();
	sf::IntRect get_sides();
 private:
 	int top;
 	int left;
 	
 	int top_door_type;
	int bottom_door_type;
 	int left_door_type;
	int right_door_type;
 	
 	bool my_ready;
 	
	Actor *hero;
	
 	std::vector<Actor *> my_actors;
 	std::vector<Tile *> my_tiles;
	sf::RenderTexture *all_tiles;
	sf::Sprite all_tile_sprites;
	
 	std::vector<ActorFactory> my_factories;
 	
 	File my_file;
};

#endif //TILESET_H
