#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "../headers/TextureMap.h"
#include "../headers/Hero.h"

void handle_events(sf::RenderWindow &window);
void update(int delta, Actor *actor);
void draw(sf::RenderWindow &window, Actor *actor);

int main()
{
	Hero myHero(10,10,50,50);
	
	sf::RenderWindow window(sf::VideoMode(640, 480), "DungeonBreath");
	sf::Clock timer;
	
	while(window.isOpen())
	{
		const double delta = timer.restart().asMicroseconds();
		
		handle_events(window);
		
		update(delta, &myHero);
		
		draw(window, &myHero);
	}
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

void update(int delta, Actor *actor)
{
	actor->update(delta);
}

void draw(sf::RenderWindow &window, Actor *actor)
{
	window.clear(sf::Color::Black);
	
	//draw everything here
	actor->draw(window);
	
	window.display();
}
