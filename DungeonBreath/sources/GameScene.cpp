#include "../headers/GameScene.h"

GameScene::GameScene() : loading_thread(&GameScene::load_level, this)
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
	my_state = loading;
	
	inv_scene.init(width, height);
	
	if(!my_font.loadFromFile("./img/Knights Quest.ttf"))
	{
		std::cout<<"Could Not Load Knights Quest"<<std::endl;
		exit( 1 );
	}
	loading_text = sf::Text("Loading", my_font);
	loading_text.setCharacterSize(45);
	loading_text.setStyle(sf::Text::Bold);
	loading_text.setColor(sf::Color::White);
	loading_text.setOrigin(loading_text.getLocalBounds().width / 2, loading_text.getLocalBounds().height / 2);
	loading_text.setPosition(width / 2, height / 2);
	
	tiles_spawned_label = sf::Text("Tiles Spawned: ", my_font);
	tiles_spawned_label.setCharacterSize(30);
	tiles_spawned_label.setStyle(sf::Text::Bold);
	tiles_spawned_label.setColor(sf::Color::White);
	tiles_spawned_label.setPosition(width - tiles_spawned_label.getLocalBounds().width - 100,
									height - tiles_spawned_label.getLocalBounds().height - 50);
	
	
	tiles_spawned_text = sf::Text("0", my_font);
	tiles_spawned_text.setCharacterSize(30);
	tiles_spawned_text.setStyle(sf::Text::Bold);
	tiles_spawned_text.setColor(sf::Color::White);
	tiles_spawned_text.setPosition(width - tiles_spawned_text.getLocalBounds().width - 50,
									height - tiles_spawned_text.getLocalBounds().height - 50);
	
	main_window.reset(sf::FloatRect(0, 0, width, height));
	menu_window.reset(sf::FloatRect(0, 0, width, height));
	
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
	
	loading_thread.launch();
}

void GameScene::load_level()
{
	srand( time( NULL) );
	while(!HeroSpawned)
	{
		addTileset(sf::IntRect(-1, -1, -1, -1),0,0,true);
	}
	my_state = playing;
	
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
	last_state_change += delta;
	if(my_state == loading)
	{
		loading_count++;
		std::stringstream ss;
		ss<<this->tiles_spawned;
		tiles_spawned_text.setString(ss.str());
	}
	else if(my_state == playing)
	{
		if(hero_found)
		{
			main_window.setCenter(sf::Vector2f(hero->get_rect().left, hero->get_rect().top));
			mini_map.setCenter(sf::Vector2f(hero->get_rect().left, hero->get_rect().top));
			inv_scene.set_hero(hero);
		}
		
		for(int i = 0; i < my_tilesets.size(); ++i)
		{
			my_tilesets[i]->update(delta);
		}
		
		Actor::clear_dead();
		Item::update_all(delta);
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && last_state_change > state_change_debounce)
		{
			my_state = inventory;
			last_state_change = 0;
		}
	}
	else if(my_state == inventory)
	{
		inv_scene.update(delta, window);
		
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::I) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) &&
		last_state_change > state_change_debounce)
		{
			my_state = playing;
			last_state_change = 0;
		}
	}
}

void GameScene::draw(sf::RenderWindow &window)
{
	if(my_state == loading)
	{
		window.draw(loading_text);
		window.draw(tiles_spawned_label);
		window.draw(tiles_spawned_text);
	}
	else if(my_state == playing)
	{
		window.setView(main_window);
		for(int i = 0; i < my_tilesets.size(); ++i)
		{
			my_tilesets[i]->draw_tiles(window);
		}
		Item::draw_all(window);
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
	else if(my_state == inventory)
	{
		window.setView(menu_window);
		inv_scene.draw(window);
	}
}

void GameScene::addTileset(sf::IntRect sides, int x_tile, int y_tile, bool clear_set)
{
	static std::vector<sf::IntRect> all_sides;
	static std::vector<sf::Vector2i> sides_locations;
		
	if(clear_set)
	{
			all_sides.clear();
			sides_locations.clear();
			tiles_spawned = 0;
	}
	
	bool do_nothing = false;
	for(int i = 0; i < tiles_to_not_spawn.size(); ++i)
	{
		if(tiles_to_not_spawn[i].x == x_tile && tiles_to_not_spawn[i].y == y_tile)
		{
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
		my_tilesets.push_back(new TileSet);
		my_tilesets[my_tilesets.size() - 1]->init("./gamedata/levels/" + file_name, x_tile * 15 * 50, y_tile * 15 * 50, HeroSpawned);
		sf::IntRect new_sides = my_tilesets[my_tilesets.size() - 1]->get_sides();
		
		all_sides.push_back(new_sides);
		sides_locations.push_back(sf::Vector2i(x_tile, y_tile));
		
		if(new_sides.left != 1)
		{
			if(tiles_spawned < max_tiles)
			{
				addTileset(sf::IntRect(-1, -1, new_sides.left, -1), x_tile - 1, y_tile);
			}
			else
			{
				addTileset(sf::IntRect(1, 1, -1, 1), x_tile - 1, y_tile);
			}
		}
		if(new_sides.top != 1)
		{
			if(tiles_spawned < max_tiles)
			{
				addTileset(sf::IntRect(-1 , -1, -1, new_sides.top), x_tile, y_tile - 1);
			}
			else
			{
				addTileset(sf::IntRect(1, 1, 1, -1), x_tile, y_tile - 1);
			}
		}
		if(new_sides.width != 1)
		{
			if(tiles_spawned < max_tiles)
			{
				addTileset(sf::IntRect(new_sides.width , -1, -1, -1), x_tile + 1, y_tile);
			}
			else
			{
				addTileset(sf::IntRect(-1, 1, 1, 1), x_tile + 1, y_tile);
			}
		}
		if(new_sides.height != 1)
		{
			if(tiles_spawned < max_tiles)
			{
				addTileset(sf::IntRect(-1 , new_sides.height, -1, -1), x_tile, y_tile + 1);
			}
			else
			{
				addTileset(sf::IntRect(1, -1, 1, 1), x_tile, y_tile + 1);
			}
		}
	}
}