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
#include "Inventory.h"

#include "Item.h"

class GameScene : public Scene
{
 public:
	enum State
	{
		loading,
		playing,
		inventory
	};
 
	GameScene();
    ~GameScene();
    void init(int width, int height);
	void load_level();
    
    void update(int delta, sf::RenderWindow &window);
    
    void draw(sf::RenderWindow &window);
	
	void addTileset(sf::IntRect sides, int x_tile = 0, int y_tile = 0, bool clear_set = false);
 private:
	static const unsigned int max_tiles = 50;
	static const unsigned int state_change_debounce = 500000;
 
    bool hero_found;
    Actor *hero;
    
    std::vector<TileSet *> my_tilesets;
    
    sf::View main_window;
    sf::View mini_map;
	sf::View menu_window;
    
    File my_file;
    std::vector<std::string> file_data;
	
	sf::Thread loading_thread;
	State my_state;
	std::vector<std::string> files;
	std::vector<TileSet *> loading_set;
	std::vector<sf::Vector2i> tiles_to_not_spawn;
	bool HeroSpawned;
	int tiles_spawned;
	
	sf::Font my_font;
	sf::Text loading_text;
	sf::Text tiles_spawned_label;
	sf::Text tiles_spawned_text;
	int loading_count;
	
	Inventory inv_scene;
	int last_state_change;
};

#endif //GAMESCENE_H
