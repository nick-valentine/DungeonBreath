#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <string>
#include <sstream>
#include <algorithm>

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
 private:
    bool hero_found;
    Actor *hero;
    
    std::vector<TileSet *> my_tilesets;
    
    sf::View main_window;
    sf::View mini_map;
    
    File my_file;
    std::vector<std::string> file_data;
};

#endif //GAMESCENE_H
