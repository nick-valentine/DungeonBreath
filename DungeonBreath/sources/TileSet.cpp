#include "../headers/TileSet.h"

bool TileSet::HeroSpawned = false;

TileSet::TileSet()
{
}

TileSet::~TileSet()
{
	if(!this->derived_type)
	{
		delete this->all_tiles;
		delete this->all_walls;
	}
	for(int i = 0; i < my_tiles.size(); ++i)
	{
		delete my_tiles[i];
	}
}

TileSet::TileSet(const TileSet &other)
{
	this->top = other.top;
	this->left = other.left;
	this->derived_type = true;
	
	this->top_door_type = other.top_door_type;
	this->bottom_door_type = other.bottom_door_type;
	this->left_door_type = other.left_door_type;
	this->right_door_type = other.right_door_type;
	
	this->my_ready = true;
	
	this->hero = other.hero;
	this->hero_in_this = other.hero_in_this;
	//this->my_actors = other.my_actors;
	if(other.hero_in_this == true && !HeroSpawned)
	{
		HeroSpawned = true;
		for(int i = 0; i < other.my_actors.size(); ++i)
		{
			this->my_actors.push_back(other.my_actors[i]->clone());
		}
	}else if(other.hero_in_this == true && HeroSpawned)
	{
		for(int i = 0; i < other.my_actors.size(); ++i)
		{
			std::string name = typeid(*(other.my_actors[i])).name();
			if(name.find("Hero") != std::string::npos)
			{
				//std::cout<<typeid(*(other->my_actors[i])).name()<<std::endl;
			}
			else
			{
				this->my_actors.push_back(other.my_actors[i]->clone());
			}
		}
	}else
	{
		this->my_actors = other.my_actors;
	}
	
	for(int i = 0; i < other.my_walls.size(); ++i)
	{
		this->my_walls.push_back(other.my_walls[i]->clone());
	}
	
	for(int i = 0; i < other.my_tiles.size(); ++i)
	{
		this->my_tiles.push_back(new Tile(*other.my_tiles[i]));
	}
	
	//this->my_tiles = other.my_tiles;
	this->all_tile_sprites = other.all_tile_sprites;
	this->all_wall_sprites = other.all_wall_sprites;
	this->my_factories = other.my_factories;
}

TileSet::TileSet(const TileSet *other)
{
	this->top = other->top;
	this->left = other->left;
	this->derived_type = true;
	
	this->top_door_type = other->top_door_type;
	this->bottom_door_type = other->bottom_door_type;
	this->left_door_type = other->left_door_type;
	this->right_door_type = other->right_door_type;
	
	this->my_ready = true;
	this->hero_in_this = other->hero_in_this;
	this->hero = other->hero;
	
	if(other->hero_in_this == true && !HeroSpawned)
	{
		HeroSpawned = true;
		for(int i = 0; i < other->my_actors.size(); ++i)
		{
			this->my_actors.push_back(other->my_actors[i]->clone());
		}
	}else if(other->hero_in_this == true && HeroSpawned)
	{
		for(int i = 0; i < other->my_actors.size(); ++i)
		{
			std::string name = typeid(*(other->my_actors[i])).name();
			if(name.find("Hero") != std::string::npos)
			{
				//std::cout<<typeid(*(other->my_actors[i])).name()<<std::endl;
			}
			else
			{
				this->my_actors.push_back(other->my_actors[i]->clone());
			}
		}	
	}else
	{
		for(int i = 0; i < other->my_actors.size(); ++i)
		{
			this->my_actors.push_back(other->my_actors[i]->clone());
		}
	}
	
	for(int i = 0; i < other->my_walls.size(); ++i)
	{
		this->my_walls.push_back(other->my_walls[i]->clone());
	}
	
	for(int i = 0; i < other->my_tiles.size(); ++i)
	{
		this->my_tiles.push_back(new Tile(*other->my_tiles[i]));
	}
	
	//this->my_tiles = other->my_tiles;
	this->all_tile_sprites = other->all_tile_sprites;
	this->all_wall_sprites = other->all_wall_sprites;
	this->my_factories = other->my_factories;
}

void TileSet::init(std::string filename, int xpos, int ypos, bool &HeroSpawned_, bool LoadingSet)
{
	this->my_ready = false;
	
	this->derived_type = false;
	this->hero_in_this = false;
	
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
				my_tiles[my_tiles.size() - 1]->init((50 * j)/* + this->left*/, (50 * i) /*+ this->top*/, 50, 50, 1, 1);
			}
			else if(data[i][j] == 't')
			{
				my_tiles.push_back(new Tile);
				my_tiles[my_tiles.size() - 1]->init((50 * j)/* + this->left*/, (50 * i)/* + this->top*/, 50, 50, 2, 1);
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
				//if(!this->HeroSpawned)
				//{
					int xpos, ypos;
					str>>xpos>>ypos;
					my_actors.push_back(new Hero);
					dynamic_cast<Hero *>(my_actors[my_actors.size() - 1])->init(((xpos - 1) * 50) + this->left, ((ypos - 1) * 50) + this->top, 50, 50);
					hero_in_this = true;
					//HeroSpawned = true;
				//	this->HeroSpawned = true;
				//}
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
							/*
							my_actors.push_back(new Wall);
							dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init(((j - 1) * 50) + this->left, ((k - 1) * 50) + this->top, 50, 50, sx, sy,  "./img/WallSheet.png");
							*/
							my_walls.push_back(new Wall);
							dynamic_cast<Wall*>(my_walls[my_walls.size() - 1])->init(((j - 1) * 50) + this->left, ((k - 1) * 50) + this->top, 50, 50, sx, sy,  "./img/WallSheet.png");
							
						}
					}
				}
				else
				{
					/*
					my_actors.push_back(new Wall);
					dynamic_cast<Wall*>(my_actors[my_actors.size() - 1])->init(((x1 - 1) * 50) + this->left, ((y1 - 1) * 50) + this->top, 50, 50, sx, sy, "./img/WallSheet.png");
					*/
					my_walls.push_back(new Wall);
					dynamic_cast<Wall*>(my_walls[my_walls.size() - 1])->init(((x1 - 1) * 50) + this->left, ((y1 - 1) * 50) + this->top, 50, 50, sx, sy, "./img/WallSheet.png");
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
			else if(substr == "enemy_vampire")
			{
				int x,y,g,si,sf = -1;
				str>>x>>y;
				if(!str.eof())
				{
					str>>g>>si>>sf;
					
					Enemy_Vampire *e = new Enemy_Vampire;
					e->init(((x - 1) * 50) + this->left, ((y - 1) * 50) + this->top, 50, 100);
					
					e->set_collide_type(Actor::Nothing);
					e->unregister();
					
					actor_groups.push_back(g);
					actors.push_back(e);
					
					spawn_intervals.push_back(si);
					spawn_frequencies.push_back(sf);
				}
				else
				{
					Enemy_Vampire *e = new Enemy_Vampire;
					e->init(((x - 1) * 50) + this->left, ((y - 1) * 50) + this->top, 50, 100);

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
	
	//draw all static items to the render textures
	//starting with tiles
	all_tiles = new sf::RenderTexture;
	if(!all_tiles->create(16 * 50, 16 * 50))
	{
		std::cout<<"Could not create rendertexture"<<std::endl;
		exit( 1 );
	}
	all_tiles->clear(sf::Color::White);
	//draw all tiles
	for(int i = 0; i < my_tiles.size(); ++i)
	{
		all_tiles->draw(my_tiles[i]->get_sprite());
	}
	
	all_tiles->display();
	all_tile_sprites = sf::Sprite(all_tiles->getTexture());
	all_tile_sprites.setPosition(this->left, this->top);
	
	//now the walls
	all_walls = new sf::RenderTexture;
	if(!all_walls->create(16 * 50, 16 * 50))
	{
		std::cout<<"Could not create rendertexture"<<std::endl;
		exit( 1 );
	}
	all_walls->clear(sf::Color::Transparent);
	
	//draw all walls
	for(int i = 0; i < my_walls.size(); ++i)
	{
		all_walls->draw(*(my_walls[i]->get_sprite(0)));
	}
	
	
	all_walls->display();
	all_wall_sprites = sf::Sprite(all_walls->getTexture());
	all_wall_sprites.setPosition(this->left, this->top);
	
	if(LoadingSet)
	{
		for(int i = 0; i < my_actors.size(); ++i)
		{
			my_actors[i]->set_collide_type(Actor::Nothing);
			my_actors[i]->unregister();
		}
		for(int i = 0; i < my_walls.size(); ++i)
		{
			my_walls[i]->set_collide_type(Actor::Nothing);
			my_walls[i]->unregister();
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
	/*
    for(int i = 0; i < my_tiles.size(); ++i)
    {
        my_tiles[i]->draw(window);
    }
	*/
	window.draw(all_tile_sprites);
}

void TileSet::draw_actors(sf::RenderWindow &window)
{
	window.draw(all_wall_sprites);
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
	top += dy;
	left += dx;
	
	all_tile_sprites.move(dx, dy);
	all_wall_sprites.move(dx, dy);
	
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
	for(int i = 0; i < my_walls.size(); ++i)
	{
		my_walls[i]->set_rect(
				sf::Rect<int>(
					my_walls[i]->get_rect().left + dx,
					my_walls[i]->get_rect().top + dy,
					my_walls[i]->get_rect().width,
					my_walls[i]->get_rect().height
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

void TileSet::set_hero(Actor *hero)
{
	this->hero = hero;
	
	for(int i = 0; i < my_tiles.size(); ++i)
	{
		my_tiles[i]->set_hero(hero);
	}
}

sf::Vector2i TileSet::get_pos()
{
	return sf::Vector2i(left, top);
}

sf::IntRect TileSet::get_sides()
{
	return sf::IntRect(left_door_type, top_door_type, right_door_type, bottom_door_type);
}


bool TileSet::hero_spawned()
{
	return HeroSpawned;
}

void TileSet::reset_hero_spawned()
{
	HeroSpawned = false;
}