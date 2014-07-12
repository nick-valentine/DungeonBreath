#include "../headers/GameScene.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{
	for(int i = 0; i < my_tilesets.size(); ++i)
	{
		delete my_tilesets[i];
	}
	
	for(int i = 0; i < loading_set.size() ; ++i)
	{
		delete loading_set[i];
	}
}

void GameScene::init(int width, int height)
{
	my_status = Nothing;

	main_window.reset(sf::FloatRect(0, 0, width, height));
	
	mini_map.reset(sf::FloatRect(0, 0, width, height));
	mini_map.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
	mini_map.zoom(2.0f);

	std::ifstream ifile;
	ifile.open("./gamedata/levels/levels.txt");
	std::string temp;
	ifile>>temp;
	while(ifile.good())
	{
		files.push_back(temp);
		ifile>>temp;
	}
	
	for(int i = 0; i < files.size(); ++i)
	{
		bool temp = false;
		loading_set.push_back(new TileSet);
		loading_set[loading_set.size() - 1]->init("./gamedata/levels/" + files[i], 0, 0, temp, true);
	}
	
	srand( time( NULL ) );
	
	HeroSpawned = false;

	std::cout<<"Loading Level"<<std::endl;
	
	while(!HeroSpawned)
	{
		addTileset(sf::IntRect(-1, -1, -1, -1),0,0,true);
	}
	
	hero_found = false;
	std::vector<Actor *>* all_actors = Actor::get_all_actors();
	for(int i = 0; i < (*all_actors).size(); ++i)
	{
		if((*all_actors)[i]->get_type() == Actor::Player)
		{
			hero = (*all_actors)[i];
			hero_found = true;
			
			for(int i = 0; i < my_tilesets.size(); ++i)
			{
				my_tilesets[i]->set_hero(hero);
			}
		}
	}
}

void GameScene::update(int delta, sf::RenderWindow &window)
{
	if(hero_found)
	{
		main_window.setCenter(sf::Vector2f(hero->get_rect().left, hero->get_rect().top));
		mini_map.setCenter(sf::Vector2f(hero->get_rect().left, hero->get_rect().top));
	}
    
    for(int i = 0; i < my_tilesets.size(); ++i)
    {
    	my_tilesets[i]->update(delta);
	}
	
	Actor::clear_dead();

}

void GameScene::draw(sf::RenderWindow &window)
{
	window.setView(main_window);
	for(int i = 0; i < my_tilesets.size(); ++i)
	{
		my_tilesets[i]->draw_tiles(window);
	}
	for(int i = 0; i < my_tilesets.size(); ++i)
	{
		my_tilesets[i]->draw_actors(window);
	}
    window.setView(mini_map);
	for(int i = 0; i < my_tilesets.size(); ++i)
	{
		my_tilesets[i]->draw_tiles(window);
	}
	for(int i = 0; i < my_tilesets.size(); ++i)
	{
		my_tilesets[i]->draw_actors(window);
	}
}

void GameScene::addTileset(sf::IntRect sides, int x_tile, int y_tile, bool clear_set)
{
	std::cout<<"Loading: "<<x_tile<<" "<<y_tile<<std::endl;
	
	static std::vector<sf::IntRect> all_sides;
	static std::vector<sf::Vector2i> sides_locations;
	static int tiles_spawned = 0;
	
		
	if(clear_set)
	{
			all_sides.clear();
			sides_locations.clear();
			tiles_spawned = 0;
	}
	
	if(tiles_spawned < max_radius)
	{
		bool do_nothing = false;
		for(int i = 0; i < tiles_to_not_spawn.size(); ++i)
		{
			if(tiles_to_not_spawn[i].x == x_tile && tiles_to_not_spawn[i].y == y_tile)
			{
				std::cout<<"do nothing"<<std::endl;
				do_nothing = true;
				break;
			}
		}
		if(!do_nothing)
		{
			tiles_spawned++;
			tiles_to_not_spawn.push_back(sf::Vector2i(x_tile, y_tile));
			std::vector<int> files_that_fit;
			
			for(int i = 0; i < loading_set.size(); ++i)
			{
				if(((loading_set[i]->get_sides().left == sides.left) || sides.left == -1) &&
					((loading_set[i]->get_sides().top == sides.top) || sides.top == -1) &&
					((loading_set[i]->get_sides().width == sides.width) || sides.width == -1) &&
					((loading_set[i]->get_sides().height == sides.height) || sides.height == -1)
					)
				{
					files_that_fit.push_back(i);
				}
			}
			
			
			if(files_that_fit.size() == 0)
			{
				for(int i = 0; i < loading_set.size(); ++i)
				{
					if((loading_set[i]->get_sides().left == 0) &&
					(loading_set[i]->get_sides().top == 0) &&
					(loading_set[i]->get_sides().width == 0) &&
					(loading_set[i]->get_sides().height == 0)
					)
					{
						files_that_fit.push_back(i);
					}
				}
			}
			
			std::string file_name = files[files_that_fit[rand() % files_that_fit.size()]];
			std::cout<<"./gamedata/levels/" + file_name<<std::endl;
			my_tilesets.push_back(new TileSet);
			my_tilesets[my_tilesets.size() - 1]->init("./gamedata/levels/" + file_name, x_tile * 15 * 50, y_tile * 15 * 50, HeroSpawned);
			std::cout<<"done initializing tileset"<<std::endl;
			sf::IntRect new_sides = my_tilesets[my_tilesets.size() - 1]->get_sides();
			
			all_sides.push_back(new_sides);
			sides_locations.push_back(sf::Vector2i(x_tile, y_tile));
			
			std::cout<<"Now Calling add on all sides"<<std::endl;
			if(new_sides.left != 1  /*&& x_tile - 1 > -max_radius*/)
			{
				addTileset(sf::IntRect(-1, -1, new_sides.left, -1), x_tile - 1, y_tile);
			}
			if(new_sides.top != 1 /*&& y_tile - 1 > -max_radius*/)
			{
				addTileset(sf::IntRect(-1 , -1, -1, new_sides.top), x_tile, y_tile - 1);
			}
			if(new_sides.width != 1 /*&& x_tile + 1 < max_radius*/)
			{
				addTileset(sf::IntRect(new_sides.width , -1, -1, -1), x_tile + 1, y_tile);
			}
			if(new_sides.height != 1 /*&& y_tile + 1 < max_radius*/)
			{
				addTileset(sf::IntRect(-1 , new_sides.height, -1, -1), x_tile, y_tile + 1);
			}
		}
	}
	else
	{
		std::cout<<"\t\t\tBlock Limit Reached"<<std::endl;
	}
}