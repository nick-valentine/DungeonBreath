#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "../headers/Actor.h"
#include "../headers/GameScene.h"
#include "../headers/MainMenuScene.h"
#include "../headers/Scene.h"

void handle_events(sf::RenderWindow &window);

int main()
{
	
	//Scene *my_scene = new GameScene;
	Scene *my_scene = new MainMenuScene;
	my_scene->init(1280, 720);
	
	sf::RenderWindow window(sf::VideoMode(1280, 720), "DungeonBreath");
	sf::Clock timer;
	int frame_frequency = 33333; //1/30 of a second
	
	while(window.isOpen())
	{
		double delta = timer.restart().asMicroseconds();
		
		while(delta < frame_frequency)
		{
			delta += timer.restart().asMicroseconds();
		}

		handle_events(window);

		my_scene->update(delta, window);

		window.clear(sf::Color::Black);
		my_scene->draw(window);
		window.display();
		
		Scene::Status my_status = my_scene->get_status();
		
		if(my_status == Scene::Exit_Program)
		{
			break;
		}
		else if(my_status == Scene::Switch_Scene)
		{
			Scene *newScene = my_scene->get_scene_to_switch_to();
			delete my_scene;
			my_scene = newScene;
		}
	}

	Actor::clear_all_actors();
	delete my_scene;
	
	return 0;
}

void handle_events(sf::RenderWindow &window)
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}
