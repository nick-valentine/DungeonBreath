#include "../headers/TileSet.h"

TileSet::TileSet()
{

}

void TileSet::init(std::string filename, int xpos, int ypos)
{
	this->my_ready = false;
	
	my_file.init(filename, std::vector<std::string>());
	my_file.QueueRead();
	
	this->top = ypos;
	this->left = xpos;
	
	while(!my_file.ready())
	{
		sf::sleep(sf::milliseconds(10));
	}
	
	std::vector<std::string> data = my_file.get_data();
	
	int i = 0;
	for(;i < data.size(); ++i)
	{
		if(data[i][0] == '-')
		{
			break;
		}
		
		for(int j = 0; j < data[i].size(); ++j)
		{
			if(data[i][j] == 'w')
			{
				my_tiles.push_back(new Tile);
				dynamic_cast<Tile*>(my_tiles[my_tiles.size() - 1])->init((50 * j) + this->left, (50 * i) + this->top, 50, 50, 1, 1);
			}
			else if(data[i][j] == 't')
			{
				my_tiles.push_back(new Tile);
				dynamic_cast<Tile*>(my_tiles[my_tiles.size() - 1])->init((50 * j) + this->left, (50 * i) + this->top, 50, 50, 2, 1);
			}
		}
	}
	
	std::vector<int> actor_groups;
	std::vector<Actor *> actors;
	std::vector<int> spawn_intervals;
	std::vector<int> spawn_frequencies;
	
	std::vector<int> factory_groups;
	
	for(; i < data.size(); ++i)
	{
		int start_line;
		int end_line;
		if(data[i].find("(") == std::string::npos)
		{
			continue;
		}
		else
		{
			start_line = i;
		}
		for(int j = i; j < data.size(); ++j)
		{
			if(data[j].find(")") == std::string::npos)
			{
			
			}
			else
			{
				end_line = j;
				break;
			}
		}
		
		std::string line = "";
		for(int j = start_line; j <= end_line; ++j)
		{
			line += data[j];
		}
		
		std::string substr;
		std::stringstream str(line.substr(1, line.size() - 2));
		while(str.good())
		{
			str>>substr;
			if(substr == "sides")
			{
				int s1, s2, s3, s4;
				str>>s1>>s2>>s3>>s4;
				left_door_type = s1;
				top_door_type = s2;
				right_door_type = s3;
				bottom_door_type = s4;
			}
			else if(substr == "hero")
			{
				int xpos, ypos;
				str>>xpos>>ypos;
				my_actors.push_back(new Hero);
				dynamic_cast<Hero *>(my_actors[my_actors.size() - 1])->init(((xpos - 1) * 50) + this->left, ((ypos - 1) * 50) + this->top, 50, 50);
			}
			else if(substr == "wall")
			{
				int sx = 0, sy = 0;
				int x1 = 0,y1 = 0,x2 = 0,y2 = 0;
				
				str>>sx>>sy>>x1>>y1;
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
							dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init(((j - 1) * 50) + this->left, ((k - 1) * 50) + this->top, 50, 50, sx, sy,  "./img/WallSheet.png");
						}
					}
				}
				else
				{
					my_actors.push_back(new Wall);
					dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init(((x1 - 1) * 50) + this->left, ((y1 - 1) * 50) + this->top, 50, 50, sx, sy, "./img/WallSheet.png");
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
					e->init(((x - 1) * 50) + this->left, ((y - 1) * 50) + this->top, 50, 50);
					
					e->set_collide_type(Actor::Nothing);
					e->unregister();
					
					actor_groups.push_back(g);
					actors.push_back(e);
					spawn_intervals.push_back(si);
					spawn_frequencies.push_back(sf);
				}
				else
				{
					EnemyFollower *e = new EnemyFollower;
					e->init(((x - 1) * 50) + this->left, ((y - 1) * 50) + this->top, 50, 50);
				
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
					e->init(((x - 1) * 50) + this->left, ((y - 1) * 50) + this->top, 50, 50);
					
					e->set_collide_type(Actor::Nothing);
					e->unregister();
					
					actor_groups.push_back(g);
					actors.push_back(e);
					
					spawn_intervals.push_back(si);
					spawn_frequencies.push_back(sf);
				}
				else
				{
					EnemyFollower *e = new EnemyFollower;
					e->init(((x - 1) * 50) + this->left, ((y - 1) * 50) + this->top, 50, 50);

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
				my_trigger->init(((xs - 1) * 50) + this->left, ((ys - 1) * 50) + this->top, 
								std::max((std::max(xe,xs) - std::min(xe,xs) + 1), 1) * 50,
								std::max((std::max(ye,ys) - std::min(ye,ys) + 1), 1) * 50,
								(Trigger::Type)tt, (Actor::ActorType)at);
				temp.set_trigger(my_trigger);
				
				 my_factories.push_back(temp);
				factory_groups.push_back(g);
			}
		}
		
		for(int i = 0; i <  my_factories.size(); ++i)
		{
			for(int j = 0; j < actors.size(); ++j)
			{
				if(actor_groups[j] == factory_groups[i])
				{
					 my_factories[i].add_actor(actors[j], spawn_intervals[j], spawn_frequencies[j]);
				}
			}
		}
	}
	my_ready = true;
}

void TileSet::update(int delta)
{
	for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->update(delta);
    }
    for(int i = 0; i < my_factories.size(); ++i)
    {
    	 my_factories[i].update(delta);
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
}

void TileSet::draw_tiles(sf::RenderWindow &window)
{
    for(int i = 0; i < my_tiles.size(); ++i)
    {
        my_tiles[i]->draw(window);
    }
}

void TileSet::draw_actors(sf::RenderWindow &window)
{
    for(int i = 0; i < my_actors.size(); ++i)
    {
        my_actors[i]->draw(window);
    }
    
    for(int i = 0; i < my_factories.size(); ++i)
    {
    	my_factories[i].draw(window);
    }
}

void TileSet::move(int dx, int dy)
{
	for(int i = 0; i < my_tiles.size(); ++i)
	{
		my_tiles[i]->set_rect(
				sf::Rect<int>(
					my_tiles[i]->get_rect().left + dx,
					my_tiles[i]->get_rect().top + dy,
					my_tiles[i]->get_rect().width,
					my_tiles[i]->get_rect().height
					)
				      );
	}
	for(int i = 0; i < my_actors.size(); ++i)
	{
		my_actors[i]->set_rect(
				sf::Rect<int>(
					my_actors[i]->get_rect().left + dx,
					my_actors[i]->get_rect().top + dy,
					my_actors[i]->get_rect().width,
					my_actors[i]->get_rect().height
					 )
					);
	}

	for(int i = 0; i < my_factories.size(); ++i)
	{
		my_factories[i].move(dx, dy);
	}
}

bool TileSet::ready() const
{
	return this->my_ready;
}
