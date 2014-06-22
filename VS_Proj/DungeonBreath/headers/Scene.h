#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <iostream>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "ActorFactory.h"

#include "Actor.h"
#include "Hero.h"
#include "MagicMissile.h"
#include "Wall.h"
#include "EnemyFollower.h"
#include "Trigger.h"

class Scene
{
 public:
    Scene();
    ~Scene();
    void init(int width, int height);
    
    void update(int delta);
    
    void draw(sf::RenderWindow &window);
 private:
    std::vector<Actor *> my_actors;
    ActorFactory EnemyFactory;
    
    sf::View main_window;
    sf::View mini_map;
};

#endif //SCENE_H
