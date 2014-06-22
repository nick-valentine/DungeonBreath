#include "../headers/Scene.h"

Scene::Scene()
{
    //init();
}

Scene::~Scene()
{

}

void Scene::init(int width, int height)
{
	main_window.reset(sf::FloatRect(0, 0, width, height));
	
	mini_map.reset(sf::FloatRect(0, 0, width, height));
	mini_map.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
	mini_map.zoom(2.0f);

    srand( time( NULL ) );
	std::vector<Actor *> myActors;
	my_actors.push_back(new Hero);
	dynamic_cast<Hero*>(my_actors[my_actors.size() - 1])->init(100,100,50,50);
	
	EnemyFollower *Dolly = new EnemyFollower;
	Dolly->init(500, 400, 50, 50);
	Dolly->set_collide_type(Actor::Nothing);
	Dolly->unregister();
	EnemyFactory.init(Dolly, 300000, 1500, 30, 10);
	
	EnemyFollower *Dolly2 = new EnemyFollower;
	Dolly2->init(600, 300, 50, 50);
	Dolly2->set_collide_type(Actor::Nothing);
	Dolly2->unregister();
	EnemyFactory.add_actor(Dolly2, 300000, 3000);
	
	Trigger *my_trigger = new Trigger;
	my_trigger->init(500, 100, 100, 100, Trigger::Latch, Actor::Player);
	EnemyFactory.set_trigger(my_trigger);
	
	EnemyFollower *test = new EnemyFollower;
	test->init(800, 200, 50, 50);
	my_actors.push_back(test);

	my_actors.push_back(test->clone());

	for(int i = 0; i < 10; ++i)
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
	main_window.setCenter(sf::Vector2f(my_actors[0]->get_rect().left, my_actors[0]->get_rect().top));
	mini_map.setCenter(sf::Vector2f(my_actors[0]->get_rect().left, my_actors[0]->get_rect().top));
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->update(delta);
    }
    EnemyFactory.update(delta);
    for(int i = 0; i < my_actors.size(); ++i)
	{
	    if(my_actors[i]->get_alive() == false)
	    {
	        my_actors[i] = my_actors[my_actors.size() - 1];
	        my_actors.pop_back();
	        --i;
        }
	}
	
	Actor::clear_dead();

}

void Scene::draw(sf::RenderWindow &window)
{

	window.setView(main_window);
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->draw(window);
    }
    EnemyFactory.draw(window);
    
    window.setView(mini_map);
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->draw(window);
    }
    EnemyFactory.draw(window);
}
