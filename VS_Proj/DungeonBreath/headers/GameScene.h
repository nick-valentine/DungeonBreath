#ifndef GAMESCENE_H
#define GAMESCENE_H

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
	std::vector<Actor *> my_actors;
    std::vector<Actor *> my_tiles;
    ActorFactory EnemyFactory;
    
    sf::View main_window;
    sf::View mini_map;
};

#endif //GAMESCENE_H
