#include <SFML/Graphics.hpp>
#include <iostream>

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

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "DungeonBreath");
	
	while(window.isOpen())
	{
		handle_events(window);
	}
}
