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

	my_tileset.init("./gamedata/levels/level_one.txt", 0, 0);
	my_tileset.init("./gamedata/levels/level_one.txt", 10 * 50, 0);
	
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
    
    my_tileset.update(delta);
	
	Actor::clear_dead();

}

void GameScene::draw(sf::RenderWindow &window)
{

	window.setView(main_window);
	
    my_tileset.draw(window);
    
    window.setView(mini_map);
    
    my_tileset.draw(window);
}
