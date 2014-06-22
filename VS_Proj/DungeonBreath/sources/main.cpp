#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "../headers/Scene.h"

void handle_events(sf::RenderWindow &window);

int main()
{
	
	Scene my_scene;
	my_scene.init(1280, 720);
	
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

		my_scene.update(delta);

		window.clear(sf::Color::Black);
		my_scene.draw(window);
		window.display();
	}

	Actor::clear_all_actors();
	
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
