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
	Hero *myHero = new Hero;
	myHero->init(10,10,50,50);
	
	StoneWall *myWall = new StoneWall;
	myWall->init(100, 100, 50, 50);
	
	std::vector<Actor *> myActors;
	myActors.push_back(myHero);
	myActors.push_back(myWall);
	
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
