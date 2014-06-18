#ifndef ACTORFACTORY_H
#define ACTORFACTORY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <vector>

#include "Actor.h"

class ActorFactory
{
 public:
    ActorFactory();
    ~ActorFactory();
    void init(Actor *toClone, int spawn_interval, int max_spawn_frequency);
    
    void update(int delta);
    void draw(sf::RenderWindow &window);
    
    void spawn(int i = 0);
    void kill(int i);
    
    void add_actor(Actor *toClone, int spawn_interval, int max_spawn_frequency);
 private:
    std::vector<Actor *> actors_to_clone;
    std::vector<int> spawn_intervals; //0 for no auto-spawning
    std::vector<int> max_spawn_rate;
    std::vector<int> time_since_spawn;
    
    std::vector<Actor *> my_actors;
    
    sf::Clock timer;
};

#endif //ACTORFACTORY_H
