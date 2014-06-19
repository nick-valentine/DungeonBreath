#include "../headers/Scene.h"

Scene::Scene()
{
    init();
}

Scene::~Scene()
{
    for(int i = 0; i < my_actors.size(); ++i)
    {
        delete my_actors[i];
    }
}

void Scene::init()
{
    srand( time( NULL ) );
	std::vector<Actor *> myActors;
	my_actors.push_back(new Hero);
	dynamic_cast<Hero*>(my_actors[my_actors.size() - 1])->init(100,100,50,50);
	
	EnemyFollower *Dolly = new EnemyFollower;
	Dolly->init(500, 400, 50, 50);
	Dolly->unregister();
	EnemyFactory.init(Dolly, 300000, 1500, 30, 10);
	
	EnemyFollower *Dolly2 = new EnemyFollower;
	Dolly2->init(600, 300, 50, 50);
	Dolly2->unregister();
	EnemyFactory.add_actor(Dolly2, 300000, 3000);
	
	Trigger *my_trigger = new Trigger;
	my_trigger->init(500, 500, 100, 100, Trigger::Latch, Actor::Player);
	EnemyFactory.set_trigger(my_trigger);
	
	for(int i = 0; i < 30; ++i)
	{
	    my_actors.push_back(new Wall);
	    dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init(50 * i, 0, 50, 50, "./img/BrickWall.png");
	
    	my_actors.push_back(new Wall);
	    dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init(50 * i, 650, 50, 50, "./img/BrickWall.png");
	    
	    my_actors.push_back(new Wall);
	    dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init(1230, i * 50, 50, 50, "./img/BrickWall.png");
	    
	    my_actors.push_back(new Wall);
	    dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init(0, i * 50, 50, 50, "./img/BrickWall.png");
	}
}

void Scene::update(int delta)
{
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->update(delta);
    }
    EnemyFactory.update(delta);
    for(int i = 0; i < my_actors.size(); ++i)
	{
	    if(my_actors[i]->get_alive() == false)
	    {
	        delete my_actors[i];
	        my_actors[i] = my_actors[my_actors.size() - 1];
	        my_actors.pop_back();
	        --i;
        }
	}
	
	Actor::clear_dead();
}

void Scene::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->draw(window);
    }
    EnemyFactory.draw(window);
}
