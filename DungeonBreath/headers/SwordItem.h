#ifndef SWORDITEM_H
#define SWORDITEM_H

#include <sstream>
#include <string>
#include <vector>

#include "Files.h"
#include "Item.h"

class SwordItem : public Item
{
	public:
		SwordItem();
		void init(int pos_x, int pos_y, int size_x, int size_y );
		
		void update(int delta);
		void draw(sf::RenderWindow &window);
		
		static void load_swords();
		static std::vector<SwordItem> *get_swords();
		
		Item *clone();
		
		std::string my_name;
		std::string my_desc;
		std::string my_image;
		int my_level;
		int phys_damage;
		int garlic_damage;
		int silver_damage;
		int fire_damage;
		int water_damage;
		int air_damage;
		int rock_damage;
		int gas_damage;
		int ghost_damage;
		
		sf::IntRect *get_rect();
		
	private:
		sf::Sprite my_sprite;
		
		static File my_file;
		static std::vector<SwordItem> my_swords;
};

#endif //SWORDITEM_H