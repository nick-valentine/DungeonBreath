#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <string>

#include "TextureMap.h"

class Item
{
	public:
		enum Type
		{
			Gold,
			Exp
		};
	
		Item();
		void init(int pos_x, int pos_y, int size_x, int size_y, std::string image_name);
		
		virtual void update(int delta) = 0;
		virtual void draw(sf::RenderWindow &window) = 0;
		
		bool dead();
		void kill();
		
		int get_speed();
		sf::IntRect *get_rect();
		
		Type get_type();
		
		static std::vector<Item *> *get_items();
		static void update_all(int delta);
		static void draw_all(sf::RenderWindow &window);
		static void add_item(Item *x);
		static void clear_items();
		static void clean_dead_items();
	protected:
		const static unsigned int speed = 10;
		
		sf::IntRect rect;
		
		sf::Texture *tex;
		std::string tex_name;
		TextureMap my_map;
		
		bool uneeded;
		Type my_type;
		
		static std::vector<Item *> my_items;
		static std::vector<Item *> all_items;
};


#endif //ITEM_H