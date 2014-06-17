#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "../headers/TextureMap.h"
#include "../headers/Hero.h"
#include "../headers/Wall.h"
#include "../headers/EnemyFollower.h"

void handle_events(sf::RenderWindow &window);
void update(int delta, std::vector<Actor *> actors);
void draw(sf::RenderWindow &window, std::vector<Actor *> actors);

int main()
{
	
	srand( time( NULL ) );
	std::vector<Actor *> myActors;
	myActors.push_back(new Hero);
	dynamic_cast<Hero*>(myActors[myActors.size() - 1])->init(100,100,50,50);
	
	for(int i = 0; i < 200; ++i)
	{
	    myActors.push_back(new EnemyFollower);
	    dynamic_cast<EnemyFollower*>(myActors[myActors.size() - 1])->init((rand() % 1200) + 50, (rand() % 640) + 50, (rand() % 25) + 25, (rand() % 25) + 25);
	}
	
	for(int i = 0; i < 30; ++i)
	{
	    myActors.push_back(new Wall);
	    dynamic_cast<Wall*>(myActors[myActors.size() - 1])->init(50 * i, 0, 50, 50, "./img/BrickWall.png");
	
    	myActors.push_back(new Wall);
	    dynamic_cast<Wall*>(myActors[myActors.size() - 1])->init(50 * i, 580, 50, 50, "./img/BrickWall.png");
	    
	    myActors.push_back(new Wall);
	    dynamic_cast<Wall*>(myActors[myActors.size() - 1])->init(1230, i * 50, 50, 50, "./img/BrickWall.png");
	    
	    myActors.push_back(new Wall);
	    dynamic_cast<Wall*>(myActors[myActors.size() - 1])->init(0, i * 50, 50, 50, "./img/BrickWall.png");
	}
	
	sf::RenderWindow window(sf::VideoMode(1280, 720), "DungeonBreath");
	sf::Clock timer;
	
	while(window.isOpen())
	{
		const double delta = timer.restart().asMicroseconds();
		
		handle_events(window);
		
		update(delta, myActors);
		
		draw(window, myActors);
		
		for(int i = 0; i < myActors.size(); ++i)
		{
		    if(myActors[i]->get_alive() == false)
		    {
		        myActors[i] = myActors[myActors.size() - 1];
		        myActors.pop_back();
            }
		}
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
