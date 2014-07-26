#ifndef TILESET_H
#define TILESET_H

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <typeinfo>

#include "Files.h"
#include "Actor.h"
#include "Tile.h"
#include "Hero.h"
#include "EnemyFollower.h"
#include "Wall.h"
#include "ActorFactory.h"
#include "Enemy_Vampire.h"

#include "Item.h"
#include "Gold.h"

class TileSet
{
 public:
 	TileSet();
	~TileSet();
	TileSet(const TileSet &other);
	TileSet(const TileSet *other);
 	void init(std::string filename, int xpos, int ypos, bool &HeroSpawned, bool LoadingSet = false);
 	
 	void update(int delta);
 	
 	void draw_tiles(sf::RenderWindow &window);
 	void draw_actors(sf::RenderWindow &window);
 	
	void move(int dx, int dy);

 	bool ready() const;
	
	void set_hero(Actor *hero);
	
	sf::Vector2i get_pos();
	sf::IntRect get_sides();
	
	static bool hero_spawned();
	static void reset_hero_spawned();
 private:
 	int top;
 	int left;
 	
 	int top_door_type;
	int bottom_door_type;
 	int left_door_type;
	int right_door_type;
 	
 	bool my_ready;
 	
	Actor *hero;
	bool hero_in_this;
	static bool HeroSpawned;
	
	bool derived_type;
	
 	std::vector<Actor *> my_actors;
	std::vector<Actor *> my_walls;
 	std::vector<Tile *> my_tiles;
	
	sf::RenderTexture *all_tiles;
	sf::Sprite all_tile_sprites;
	
	sf::RenderTexture *all_walls;
	sf::Sprite all_wall_sprites;
	
 	std::vector<ActorFactory> my_factories;
 	
 	File my_file;
};

#endif //TILESET_H
