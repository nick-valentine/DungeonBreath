#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

#include "../headers/TextureMap.h"
#include "../headers/Hero.h"
#include "../headers/StoneWall.h"

void handle_events(sf::RenderWindow &window);
void update(int delta, std::vector<Actor *> actors);
void draw(sf::RenderWindow &window, std::vector<Actor *> actors);

int main()
{
	
	std::vector<Actor *> myActors;
	myActors.push_back(new Hero);
	dynamic_cast<Hero*>(myActors[myActors.size() - 1])->init(10,10,50,50);
	
	for(int i = 0; i < 50; ++i)
	{
    	myActors.push_back(new StoneWall);
	    dynamic_cast<StoneWall*>(myActors[myActors.size() - 1])->init(100 * i, 380, 50, 50);
	}
	
	sf::RenderWindow window(sf::VideoMode(640, 480), "DungeonBreath");
	sf::Clock timer;
	
	while(window.isOpen())
	{
		const double delta = timer.restart().asMicroseconds();
		
		handle_events(window);
		
		update(delta, myActors);
		
		draw(window, myActors);
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

void update(int delta, std::vector<Actor *> actors)
{
    for(int i = 0; i < actors.size(); ++i)
    {
	    actors[i]->update(delta);
	}
}

void draw(sf::RenderWindow &window, std::vector<Actor *> actors)
{
	window.clear(sf::Color::Black);
	
	//draw everything here
	for(int i = 0; i < actors.size(); ++i)
	{
	    actors[i]->draw(window);
	}
	
	window.display();
}
