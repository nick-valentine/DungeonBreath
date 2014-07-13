#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "Actor.h"
#include "Files.h"
#include "TileSet.h"
#include "Scene.h"

class GameScene : public Scene
{
 public:
	GameScene();
    ~GameScene();
    void init(int width, int height);
    
    void update(int delta, sf::RenderWindow &window);
    
    void draw(sf::RenderWindow &window);
	
	void addTileset(sf::IntRect sides, int x_tile = 0, int y_tile = 0, bool clear_set = false);
 private:
	static const unsigned int max_tiles = 100;
 
    bool hero_found;
    Actor *hero;
    
    std::vector<TileSet *> my_tilesets;
    
    sf::View main_window;
    sf::View mini_map;
    
    File my_file;
    std::vector<std::string> file_data;
	
	std::vector<std::string> files;
	std::vector<TileSet *> loading_set;
	std::vector<sf::Vector2i> tiles_to_not_spawn;
	bool HeroSpawned;
};

#endif //GAMESCENE_H
