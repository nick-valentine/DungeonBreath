#include "../headers/ActorFactory.h"

ActorFactory::ActorFactory(Actor *toClone, int spawn_interval, int max_spawn_frequency)
{
    init(toClone, spawn_interval, max_spawn_frequency);
}

void ActorFactory::init(Actor *toClone, int spawn_interval, int max_spawn_frequency)
{
    actors_to_clone.push_back(toClone);
    spawn_intervals.push_back(spawn_interval);
    max_spawn_rate.push_back(max_spawn_frequency);
}

void ActorFactory::update(int delta)
{
    for(int i = 0; i < actors_to_clone.size(); ++i)
    {
        time_since_spawn[i] += timer.restart().asMicroseconds();
        
        if(time_since_spawn[i] > max_spawn_rate[i])
        {
            my_actors.push_back(actors_to_clone[i]->clone());
            time_since_spawn[i] = 0;
        }
    }
    
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->update(delta);
    }
}

void ActorFactory::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->draw(window);
    }
}

void ActorFactory::spawn(int i)
{

}

void ActorFactory::kill(int i)
{

}

void ActorFactory::add_actor(Actor *toClone, int spawn_interval, int max_spawn_frequency)
{

}
