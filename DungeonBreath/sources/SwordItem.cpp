#include "../headers/SwordItem.h"

File SwordItem::my_file;
std::vector<SwordItem> SwordItem::my_swords;

SwordItem::SwordItem() : Item()
{

}

void SwordItem::init(int pos_x, int pos_y, int size_x, int size_y)
{
	Item::init(pos_x, pos_y, size_x, size_y, "./img/Sword.png");
	my_sprite.setTexture(*tex);
	my_sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
	
	this->my_type = Item::Entity;
	
	my_name = "";
	my_desc = "";
	my_image = "./img/Sword.png";
	my_level = 0;
	my_damage.phys = 0;
	my_damage.garlic = 0;
	my_damage.silver = 0;
	my_damage.fire = 0;
	my_damage.water = 0;
	my_damage.air = 0;
	my_damage.rock = 0;
	my_damage.gas = 0;
	my_damage.ghost = 0;
	my_damage.holy = 0;
	my_damage.arcane = 0;
}

void SwordItem::update(int delta)
{

}

void SwordItem::draw(sf::RenderWindow &window)
{
	my_sprite.setPosition(rect.left, rect.top);
	my_sprite.setScale(rect.width / 100.0, rect.height / 100.0);
	window.draw(my_sprite);
}

std::vector<SwordItem>* SwordItem::get_swords()
{
	return &my_swords;
}

void SwordItem::load_swords()
{
	my_file.init("./gamedata/swords.txt", std::vector<std::string>());
	my_file.QueueRead();
	
	while(!my_file.ready())
	{
		sf::sleep(sf::milliseconds(10));
	}
	
	std::vector<std::string> data = my_file.get_data();
	
	for(int i = 0; i < data.size(); ++i)
	{
		int start_sword;
		int end_sword;
		if(data[i].find("{") == std::string::npos)
		{
			continue;
		}
		else
		{
			start_sword = i;
		}
		for(int j = i; j < data.size(); ++j)
		{
			if(data[j].find("}") == std::string::npos)
			{
			
			}
			else
			{
				end_sword = j;
				break;
			}
		}
		
		std::vector<std::string> sword;
		for(int j = start_sword; j < end_sword; ++j)
		{
			sword.push_back(data[j]);
		}
		
		/*
		for(int j = 0 ; j < sword.size(); ++j)
		{
			std::cout<<sword[j]<<std::endl;
		}
		*/
	
		SwordItem temp;
		temp.init(0, 0, 100, 100);
		for(int j = 0; j < sword.size(); ++j)
		{
			int start_line;
			int end_line;
			if(sword[j].find("(") == std::string::npos)
			{
				continue;
			}
			else
			{
				start_line = j;
			}
			for(int k = j; k < sword.size(); ++k)
			{
				if(sword[k].find(")") == std::string::npos)
				{
				
				}
				else
				{
					end_line = k;
					break;
				}
			}
			
			std::string line = "";
			for(int k = start_line; k <= end_line; ++k)
			{
				line += sword[k];
			}
			
			std::string substr;
			std::stringstream ss(line.substr(1, line.size() - 2));
			while(ss.good())
			{
				ss>>substr;
				if(substr == "name")
				{
					getline(ss, temp.my_name);
					temp.my_name = temp.my_name.substr(1, temp.my_name.size() - 1);
				}
				else if(substr == "desc")
				{
					getline(ss, temp.my_desc);
					temp.my_desc = temp.my_desc.substr(1, temp.my_desc.size() - 1);
				}
				else if(substr == "image")
				{
				
					getline(ss, temp.my_image);
					temp.my_image = temp.my_image.substr(1, temp.my_image.size() - 1);
					temp.tex = temp.my_map.request(temp.my_image);
					temp.tex_name = temp.my_image;
					temp.my_sprite.setTexture(*temp.tex);
					temp.my_sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
					
				}
				else if(substr == "level")
				{
					ss>>temp.my_level;
				}
				else if(substr == "physical")
				{
					ss>>temp.my_damage.phys;
				}
				else if(substr == "garlic")
				{
					ss>>temp.my_damage.garlic;
				}
				else if(substr == "silver")
				{
					ss>>temp.my_damage.silver;
				}
				else if(substr == "fire")
				{
					ss>>temp.my_damage.fire;
				}
				else if(substr == "water")
				{
					ss>>temp.my_damage.water;
				}
				else if(substr == "air")
				{
					ss>>temp.my_damage.air;
				}
				else if(substr == "rock")
				{
					ss>>temp.my_damage.rock;
				}
				else if(substr == "gas")
				{
					ss>>temp.my_damage.gas;
				}
				else if(substr == "ghost")
				{
					ss>>temp.my_damage.ghost;
				}
				else if(substr == "holy")
				{
					ss>>temp.my_damage.holy;
				}
				else if(substr == "arcane")
				{
					ss>>temp.my_damage.arcane;
				}
			}
		}
		my_swords.push_back(temp);
	}
}

Item *SwordItem::clone()
{
	SwordItem *temp = new SwordItem(*this);
	Item::add_item(temp);
	return temp;
}

sf::IntRect *SwordItem::get_rect()
{
	return &this->rect;
}