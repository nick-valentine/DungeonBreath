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
#include "Tile.h"

class Scene
{
 public:
 	enum Status
 	{
 		Nothing,
 		Exit_Program,
 		Switch_Scene
 	};
 
    Scene();
    ~Scene();
    virtual void init(int width, int height) = 0;
    
    virtual void update(int delta, sf::RenderWindow &window) = 0;
    
    virtual void draw(sf::RenderWindow &window) = 0;
    
    Status get_status();
    Scene *get_scene_to_switch_to();
 private:
    
 protected:
 	Status my_status;
 	Scene *switch_to;
 	
 	int width;
 	int height;
};

#endif //SCENE_H
