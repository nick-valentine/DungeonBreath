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
	dynamic_cast<Hero*>(my_actors[my_actors.size() - 1])->init(50,50,50,50);

	my_file.init("./gamedata/levels/level_one.txt", file_data);
	my_file.QueueRead();
	while(!my_file.ready())
	{
		sf::sleep(sf::milliseconds(10));
	}
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
	
	
	std::vector<int> agroups;
	std::vector<Actor *>actors;
	std::vector<int> spawn_intervals;
	std::vector<int> spawn_frequencies;
	
	std::vector<int> fgroups;
	
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
		
		std::string substr;
		std::stringstream str(data.substr(1, data.size() - 2));
		while(str.good())
		{
			str>>substr;
			
			if(substr == "sides")
			{
				int s1, s2;
				str>>s1>>s2;
				std::cout<<s1<<" "<<s2<<std::endl;
			}
			else if(substr == "treasure")
			{
				int x1 = 0,y1 = 0,x2 = 0,y2 = 0;
				
				str>>x1>>y1;
				if(!str.eof())
				{
					str>>x2>>y2;
					if(x2 < x1)
					{
						int temp = x1;
						x1 = x2;
						x2 = temp;
					}
					if(y2 < y1)
					{
						int temp = y1;
						y1 = y2;
						y2 = temp;
					}
				
					for(int j = x1; j <= x2; ++j)
					{
						for(int k = y1; k <= y2; ++k)
						{
							my_actors.push_back(new Wall);
							dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init((j - 1) * 50, (k - 1) * 50, 50, 50, "./img/BrickWall.png");
						}
					}
				}
				else
				{
					my_actors.push_back(new Wall);
					dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init((x1 - 1) * 50, (y1 - 1) * 50, 50, 50, "./img/BrickWall.png");
				}
				
			}
			else if(substr == "enemy_orc")
			{
				int x,y,g,si,sf = -1;
				str>>x>>y;
				if(!str.eof())
				{
					str>>g>>si>>sf;
					
					EnemyFollower *e = new EnemyFollower;
					e->init((x - 1) * 50, (y - 1) * 50, 50, 50);
					
					e->set_collide_type(Actor::Nothing);
					e->unregister();
					
					agroups.push_back(g);
					actors.push_back(e);
					spawn_intervals.push_back(si);
					spawn_frequencies.push_back(sf);
				}
				else
				{
					EnemyFollower *e = new EnemyFollower;
					e->init((x - 1) * 50, (y - 1) * 50, 50, 50);
				
					my_actors.push_back(e);
				}
			}
			else if(substr == "enemy_bat")
			{
				int x,y,g,si,sf = -1;
				str>>x>>y;
				if(!str.eof())
				{
					str>>g>>si>>sf;
					
					EnemyFollower *e = new EnemyFollower;
					e->init((x - 1) * 50, (y - 1) * 50, 50, 50);
					
					e->set_collide_type(Actor::Nothing);
					e->unregister();
					
					agroups.push_back(g);
					actors.push_back(e);
					
					spawn_intervals.push_back(si);
					spawn_frequencies.push_back(sf);
				}
				else
				{
					EnemyFollower *e = new EnemyFollower;
					e->init((x - 1) * 50, (y - 1) * 50, 50, 50);

					my_actors.push_back(e);
				}
			}
			else if(substr == "actor_factory")
			{
				int xs,ys,xe,ye,g,ms,a,tt,at;
				str>>xs>>ys>>xe>>ye>>g>>ms>>a>>tt>>at;
			
				ActorFactory temp;
				temp.init(ms, a);
				Trigger *my_trigger = new Trigger;
				my_trigger->init((xs - 1) * 50, (ys - 1) * 50, 
								std::max((std::max(xe,xs) - std::min(xe,xs) + 1), 1) * 50,
								std::max((std::max(ye,ys) - std::min(ye,ys) + 1), 1) * 50,
								(Trigger::Type)tt, (Actor::ActorType)at);
				temp.set_trigger(my_trigger);
				
				EnemyFactories.push_back(temp);
				fgroups.push_back(g);
			}
		}
	}
	
	for(int i = 0; i < EnemyFactories.size(); ++i)
	{
		for(int j = 0; j < actors.size(); ++j)
		{
			if(agroups[j] == fgroups[i])
			{
				EnemyFactories[i].add_actor(actors[j], spawn_intervals[j], spawn_frequencies[j]);
			}
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
    for(int i = 0; i < EnemyFactories.size(); ++i)
    {
    	EnemyFactories[i].update(delta);
    }
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
    
    for(int i = 0; i < EnemyFactories.size(); ++i)
    {
    	EnemyFactories[i].draw(window);
    }
    
    window.setView(mini_map);
    for(int i = 0; i < my_tiles.size(); ++i)
    {
        my_tiles[i]->draw(window);
    }
    
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->draw(window);
    }
    
    for(int i = 0; i < EnemyFactories.size(); ++i)
    {
    	EnemyFactories[i].draw(window);
    }
}
