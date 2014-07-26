#include "../headers/ActorFactory.h"

ActorFactory::ActorFactory()
{

}

ActorFactory::~ActorFactory()
{

}

ActorFactory::ActorFactory(const ActorFactory &other)
{
	for(int i = 0; i < other.actors_to_clone.size(); ++i)
	{
		this->actors_to_clone.push_back(other.actors_to_clone[i]->clone());;
		this->actors_to_clone[i]->unregister();
		this->actors_to_clone[i]->set_collide_type(Actor::Nothing);
	}
	
	this->spawn_intervals = other.spawn_intervals;
	this->max_spawn_rate = other.max_spawn_rate;
	this->time_since_spawn = other.time_since_spawn;
	
	this->my_trigger = dynamic_cast<Trigger *>(other.my_trigger->clone());
	this->timer = other.timer;
	this->max_spawns = other.max_spawns;
	this->spawn_count = other.spawn_count;
	this->num_to_keep_alive = other.num_to_keep_alive;
}

void ActorFactory::init(int max_spawns, int num_to_keep_alive)
{
    this->max_spawns = max_spawns;
    spawn_count = 0;
    this->num_to_keep_alive = num_to_keep_alive;
    
    this->my_trigger = new Trigger();
}

void ActorFactory::init(Actor *toClone, int spawn_interval, int max_spawn_frequency, int max_spawns, int num_to_keep_alive)
{
    actors_to_clone.push_back(toClone);
    spawn_intervals.push_back(spawn_interval);
    max_spawn_rate.push_back(max_spawn_frequency);
    time_since_spawn.push_back(0);
    this->max_spawns = max_spawns;
    spawn_count = 0;
    this->num_to_keep_alive = num_to_keep_alive;
    
    this->my_trigger = new Trigger();
}

void ActorFactory::update(int delta)
{
    my_trigger->update(delta);
    if(my_trigger->get_active())
    {
        if(num_to_keep_alive == 0 || num_to_keep_alive > my_actors.size())
        {
            if(spawn_count < max_spawns || max_spawns == 0)
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
                            spawn_count++;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->update(delta);
        
    }
	for(int i = 0; i < my_actors.size(); ++i)
    {
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
    //my_trigger->draw(window);
}

void ActorFactory::spawn(int i)
{
    if(num_to_keep_alive == 0 || num_to_keep_alive < my_actors.size())
    {
        if(spawn_count < max_spawns || max_spawns == 0)
        {
            if(time_since_spawn[i] > max_spawn_rate[i])
            {
                my_actors.push_back(actors_to_clone[i]->clone());
                time_since_spawn[i] = 0;
                spawn_count++;
            }
        }
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


int ActorFactory::get_max_spawns() const
{
    return this->max_spawns;
}

int ActorFactory::get_spawn_count() const
{
    return this->spawn_count;
}

int ActorFactory::get_num_to_keep_alive() const
{
    return this->num_to_keep_alive;
}

Trigger *ActorFactory::get_trigger() const
{
    return this->my_trigger;
}

void ActorFactory::set_max_spawns(int x)
{
    this->max_spawns = x;
}

void ActorFactory::reset_spawn_count()
{
    this->spawn_count = 0;
}

void ActorFactory::set_num_to_keep_alive(int x)
{
    this->num_to_keep_alive = x;
}

void ActorFactory::set_trigger(Trigger* x)
{
    this->my_trigger = x;
}

void ActorFactory::move(int dx, int dy)
{
	for(int i = 0; i < actors_to_clone.size(); ++i)
	{
		actors_to_clone[i]->set_rect(
					sf::Rect<int>(
						actors_to_clone[i]->get_rect().left + dx,
						actors_to_clone[i]->get_rect().top + dy,
						actors_to_clone[i]->get_rect().width,
						actors_to_clone[i]->get_rect().height
						)
					);
	}

	my_trigger->set_rect(
                    sf::Rect<int>(
                        	my_trigger->get_rect().left + dx,
                       		my_trigger->get_rect().top + dy,
		                my_trigger->get_rect().width,
                        	my_trigger->get_rect().height
                        	    )
			            );
}

