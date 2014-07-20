#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <sstream>

#include "Scene.h"
#include "Actor.h"
#include "Hero.h"
#include "Item.h"

class Inventory : public Scene
{
	public:
		Inventory();
		~Inventory();
		void init(int width, int height);
		
		void update(int delta, sf::RenderWindow &window);
		
		void draw(sf::RenderWindow &window);
	
		void set_hero(Actor *hero);
	private:
		Hero *hero;
		
		std::string gold;
		std::string exp;
		
		sf::Font my_font;
		sf::Text gold_text;
		sf::Text exp_text;
};

#endif //INVENTORY_H