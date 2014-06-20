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
	
	sf::RenderWindow window(sf::VideoMode(1280, 720), "DungeonBreath");
	sf::Clock timer;
	
	while(window.isOpen())
	{
		const double delta = timer.restart().asMicroseconds();
		
		handle_events(window);

		my_scene.update(delta);
		
		window.clear(sf::Color::Black);
		my_scene.draw(window);
		window.display();
	}
	
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
