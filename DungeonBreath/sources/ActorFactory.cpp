#include "../headers/ActorFactory.h"

ActorFactory::ActorFactory()
{

}

ActorFactory::~ActorFactory()
{
    for(int i = 0; i < actors_to_clone.size(); ++i)
    {
        delete actors_to_clone[i];
    }
    for(int i = 0; i < my_actors.size(); ++i)
    {
    	delete my_actors[i];
    }
}

void ActorFactory::init(Actor *toClone, int spawn_interval, int max_spawn_frequency)
{
    actors_to_clone.push_back(toClone);
    spawn_intervals.push_back(spawn_interval);
    max_spawn_rate.push_back(max_spawn_frequency);
    time_since_spawn.push_back(0);
}

void ActorFactory::update(int delta)
{
    for(int i = 0; i < actors_to_clone.size(); ++i)
    {
        time_since_spawn[i] += delta;
        if(spawn_intervals[i] != 0)
        {
            if(time_since_spawn[i] > max_spawn_rate[i] && time_since_spawn[i] > spawn_intervals[i])
            {
                my_actors.push_back(actors_to_clone[i]->clone());
                time_since_spawn[i] = 0;
            }
        }
    }
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->update(delta);
        if(my_actors[i]->get_alive() == false)
        {
            my_actors[i] = my_actors[my_actors.size() - 1];
            my_actors.pop_back();
            i--;
        }
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
    if(time_since_spawn[i] > max_spawn_rate[i])
    {
        my_actors.push_back(actors_to_clone[i]->clone());
        time_since_spawn[i] = 0;
    }
}

void ActorFactory::kill(int i)
{
    my_actors[i]->kill();
}

void ActorFactory::add_actor(Actor *toClone, int spawn_interval, int max_spawn_frequency)
{
    actors_to_clone.push_back(toClone);
    spawn_intervals.push_back(spawn_interval);
    max_spawn_rate.push_back(max_spawn_frequency);
    time_since_spawn.push_back(0);
}
