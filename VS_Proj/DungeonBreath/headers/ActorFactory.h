#ifndef ACTORFACTORY_H
#define ACTORFACTORY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <vector>

#include "Actor.h"
#include "Trigger.h"

class ActorFactory
{
 public:
    ActorFactory();
    ~ActorFactory();
    void init(Actor *toClone, int spawn_interval, int max_spawn_frequency, int max_spawns, int keep_alive);
    void init(int max_spawns, int keep_alive);
    
    void update(int delta);
    void draw(sf::RenderWindow &window);
    
    void spawn(int i = 0);
    void kill(int i);
    
    void add_actor(Actor *toClone, int spawn_interval, int max_spawn_frequency);
    
    int get_max_spawns() const;
    int get_spawn_count() const;
    int get_num_to_keep_alive() const;
    Trigger *get_trigger() const;
    
    void set_max_spawns(int x);
    void reset_spawn_count();
    void set_num_to_keep_alive(int x);
    void set_trigger(Trigger* x);
 private:
    std::vector<Actor *> actors_to_clone;
    std::vector<int> spawn_intervals; //0 for no auto-spawning
    std::vector<int> max_spawn_rate;
    std::vector<int> time_since_spawn;
    
    Trigger *my_trigger;
    
    std::vector<Actor *> my_actors;
    
    sf::Clock timer;
    
    int max_spawns;
    int spawn_count;
    
    int num_to_keep_alive;
};

#endif //ACTORFACTORY_H
