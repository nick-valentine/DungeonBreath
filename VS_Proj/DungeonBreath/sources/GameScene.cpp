#include "../headers/GameScene.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::init(int width, int height)
{
	my_status = Nothing;

	main_window.reset(sf::FloatRect(0, 0, width, height));
	
	mini_map.reset(sf::FloatRect(0, 0, width, height));
	mini_map.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
	mini_map.zoom(2.0f);

    srand( time( NULL ) );
	std::vector<Actor *> myActors;
	my_actors.push_back(new Hero);
	dynamic_cast<Hero*>(my_actors[my_actors.size() - 1])->init(100,100,50,50);
	/*
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
	
	for(int i = -15; i < 45; ++i)
	{
		for(int j = -15; j < 45; ++j)
		{
			my_tiles.push_back(new Tile);
			dynamic_cast<Tile*>(my_tiles[my_tiles.size() - 1])->init(50 * i, 50 * j, 50, 50, (i % 2) + 1, 1);
		}
	}
	*/
	my_file.init("./gamedata/levels/level_one.txt", file_data);
	my_file.QueueRead();
	std::cout<<"Queued read"<<std::endl;
	while(!my_file.ready())
	{
		sf::sleep(sf::milliseconds(10));
		std::cout<<"Waiting for read"<<std::endl;
	}
	std::cout<<"Read finished: "<<my_file.get_data().size()<<" lines read"<<std::endl;
	file_data = my_file.get_data();
	
	int i = 0;
	for(; i < file_data.size(); ++i)
	{
		if(file_data[i][0] == '-')
		{
			break;
		}
		
		for(int j = 0; j < file_data[i].size(); ++j)
		{
			if(file_data[i][j] == 'w')
			{
				my_tiles.push_back(new Tile);
				dynamic_cast<Tile*>(my_tiles[my_tiles.size() - 1])->init(50 * j, 50 * i, 50, 50, 1, 1);
			}
			else if(file_data[i][j] == 't')
			{
				my_tiles.push_back(new Tile);
				dynamic_cast<Tile*>(my_tiles[my_tiles.size() - 1])->init(50 * j, 50 * i, 50, 50, 2, 1);
			}
		}
	}
	for(; i < file_data.size(); ++i)
	{
		int start_line;
		int end_line;
		if(file_data[i].find("(") == std::string::npos)
		{
			continue;
		}
		else
		{
			start_line = i;
		}
		for(int j = i; j < file_data.size(); ++j)
		{
			if(file_data[j].find(")") == std::string::npos)
			{
			}
			else
			{
				end_line = j;
				break;	
			}
		}
		
		std::string data = "";
		for(int j = start_line; j <= end_line; ++j)
		{
			data += file_data[j];
		}
		//std::cout<<data<<std::endl;
		
		std::string substr;
		std::stringstream str(data.substr(1, data.size() - 2));
		while(str.good())
		{
			str>>substr;
			std::cout<<substr<<std::endl;
		}
		
	}
	
}

void GameScene::update(int delta, sf::RenderWindow &window)
{
	main_window.setCenter(sf::Vector2f(my_actors[0]->get_rect().left, my_actors[0]->get_rect().top));
	mini_map.setCenter(sf::Vector2f(my_actors[0]->get_rect().left, my_actors[0]->get_rect().top));
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->update(delta);
    }
    //EnemyFactory.update(delta);
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

void GameScene::draw(sf::RenderWindow &window)
{

	window.setView(main_window);
	
    for(int i = 0; i < my_tiles.size(); ++i)
    {
        my_tiles[i]->draw(window);
    }
	
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->draw(window);
    }
    
    //EnemyFactory.draw(window);
    
    window.setView(mini_map);
    for(int i = 0; i < my_tiles.size(); ++i)
    {
        my_tiles[i]->draw(window);
    }
    
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->draw(window);
    }
    
    //EnemyFactory.draw(window);
}
