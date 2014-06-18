#include "../headers/Scene.h"

Scene::Scene()
{
    init();
}

void Scene::init()
{
    srand( time( NULL ) );
	std::vector<Actor *> myActors;
	my_actors.push_back(new Hero);
	dynamic_cast<Hero*>(my_actors[my_actors.size() - 1])->init(100,100,50,50);
	
	for(int i = 0; i < 200; ++i)
	{
	    my_actors.push_back(new EnemyFollower);
	    dynamic_cast<EnemyFollower*>(my_actors[my_actors.size() - 1])->init((rand() % 1200) + 50, (rand() % 640) + 50, (rand() % 25) + 25, (rand() % 25) + 25);
	}
	
	for(int i = 0; i < 30; ++i)
	{
	    my_actors.push_back(new Wall);
	    dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init(50 * i, 0, 50, 50, "./img/BrickWall.png");
	
    	my_actors.push_back(new Wall);
	    dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init(50 * i, 580, 50, 50, "./img/BrickWall.png");
	    
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
    
    for(int i = 0; i < my_actors.size(); ++i)
	{
	    if(my_actors[i]->get_alive() == false)
	    {
	        my_actors[i] = my_actors[my_actors.size() - 1];
	        my_actors.pop_back();
        }
	}
}

void Scene::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->draw(window);
    }
}