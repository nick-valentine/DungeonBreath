#ifndef SWORDITEM_H
#define SWORDITEM_H

#include <sstream>
#include <string>
#include <vector>

#include "Files.h"
#include "Item.h"
#include "DamageStruct.h"

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
		Damage_Struct my_damage;
		
		sf::IntRect *get_rect();
		
	private:
		sf::Sprite my_sprite;
		
		static File my_file;
		static std::vector<SwordItem> my_swords;
};

#endif //SWORDITEM_H