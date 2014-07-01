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
}

void GameScene::init(int width, int height)
{
	my_status = Nothing;

	main_window.reset(sf::FloatRect(0, 0, width, height));
	
	mini_map.reset(sf::FloatRect(0, 0, width, height));
	mini_map.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
	mini_map.zoom(2.0f);

	my_tilesets.push_back(new TileSet);
	my_tilesets[my_tilesets.size() - 1]->init("./gamedata/levels/level_one.txt", 0, 0);
	
	my_tilesets.push_back(new TileSet);
	//my_tilesets[my_tilesets.size() - 1]->init("./gamedata/levels/level_two.txt", 16 * 50, 0);
	my_tilesets[my_tilesets.size() - 1]->init("./gamedata/levels/level_two.txt", 0, 0);
	my_tilesets[my_tilesets.size() - 1]->move(16 * 50, 0);

	my_tilesets.push_back(new TileSet);
	//my_tilesets[my_tilesets.size() - 1]->init("./gamedata/levels/level_three.txt", 16 * 50 * 2, 0);
	my_tilesets[my_tilesets.size() - 1]->init("./gamedata/levels/level_three.txt", 0, 0);
	my_tilesets[my_tilesets.size() - 1]->move(16 * 50 * 2, 0);
	
	hero_found = false;
	std::vector<Actor *>* all_actors = Actor::get_all_actors();
	for(int i = 0; i < (*all_actors).size(); ++i)
	{
		if((*all_actors)[i]->get_type() == Actor::Player)
		{
			hero = (*all_actors)[i];
			hero_found = true;
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
