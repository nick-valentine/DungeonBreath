#include "../headers/Inventory.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}

void Inventory::init(int width, int height)
{
	this->width = width;
	this->height = height;

	gold = "Gold: ";
	exp = "Exp: ";

	if(!my_font.loadFromFile("./img/Knights Quest.ttf"))
	{
		std::cout<<"Could Not Load Knights Quest"<<std::endl;
		exit( 1 );
	}
	
	gold_text = sf::Text(gold, my_font);
	gold_text.setCharacterSize(45);
	gold_text.setStyle(sf::Text::Bold);
	gold_text.setColor(sf::Color::White);
	gold_text.setOrigin(gold_text.getLocalBounds().width / 2, gold_text.getLocalBounds().height / 2);
	gold_text.setPosition(width / 2 - gold_text.getLocalBounds().width, height - gold_text.getLocalBounds().top - 50);
	
	exp_text = sf::Text(exp, my_font);
	exp_text.setCharacterSize(45);
	exp_text.setStyle(sf::Text::Bold);
	exp_text.setColor(sf::Color::White);
	exp_text.setOrigin(exp_text.getLocalBounds().width / 2, exp_text.getLocalBounds().height / 2);
	exp_text.setPosition(width / 2, height - exp_text.getLocalBounds().top - 50);
}

void Inventory::update(int delta, sf::RenderWindow &window)
{
	std::stringstream ss;
	ss<<hero->get_gold();
	gold = "Gold: " + ss.str();
	
	ss.str("");
	ss<<hero->get_exp();
	exp = "Exp: " + ss.str();

	gold_text.setString(gold);
	gold_text.setPosition((width / 2) - gold_text.getLocalBounds().width, height - gold_text.getLocalBounds().top - 50);
	
	exp_text.setString(exp);
	exp_text.setPosition(width / 2, height - exp_text.getLocalBounds().top - 50);
}


void Inventory::draw(sf::RenderWindow &window)
{
	window.draw(gold_text);
	window.draw(exp_text);
	
	for(int i = 0; i < hero->get_inventory()[0].size(); ++i)
	{
		 *(hero->get_inventory()[0][i]->get_rect()) = sf::IntRect((i % 6) * 50, (i / 6) * 50, 50, 50);
		hero->get_inventory()[0][i]->draw(window);
		
		if(hero->get_inventory()[0][i]->get_rect()->contains(sf::Mouse::getPosition(window)) && dynamic_cast<SwordItem *>(hero->get_inventory()[0][i]) != NULL)
		{
			display_sword_stats(dynamic_cast<SwordItem *>(hero->get_inventory()[0][i]), window);
		}
	}
}

void Inventory::set_hero(Actor *hero)
{
	this->hero = dynamic_cast<Hero *>(hero);
}

void Inventory::display_sword_stats(SwordItem *item, sf::RenderWindow &window)
{
	std::stringstream ss;
	ss<<"Name: "<<item->my_name<<"\n";
	ss<<"Desc: "<<item->my_desc<<"\n";
	ss<<"Level: "<<item->my_level<<"\n";
	ss<<"Damage: \n";
	if(item->phys_damage != 0)
	{
		ss<<"Physical: "<<item->phys_damage<<"\n";
	}
	if(item->garlic_damage != 0)
	{
		ss<<"Garlic: "<<item->garlic_damage<<"\n";
	}
	if(item->silver_damage != 0)
	{
		ss<<"Silver: "<<item->silver_damage<<"\n";
	}
	if(item->fire_damage != 0)
	{
		ss<<"Fire: "<<item->fire_damage<<"\n";
	}
	if(item->water_damage != 0)
	{
		ss<<"Water: "<<item->water_damage<<"\n";
	}
	if(item->air_damage != 0)
	{
		ss<<"Air: "<<item->air_damage<<"\n";
	}
	if(item->rock_damage != 0)
	{
		ss<<"Rock: "<<item->rock_damage<<"\n";
	}
	if(item->gas_damage != 0)
	{
		ss<<"Gas: "<<item->gas_damage<<"\n";
	}
	if(item->ghost_damage != 0)
	{
		ss<<"Ghost: "<<item->ghost_damage<<"\n";
	}

	sf::Text info_text;
	info_text = sf::Text(ss.str(), my_font);
	info_text.setCharacterSize(25);
	info_text.setStyle(sf::Text::Bold);
	info_text.setColor(sf::Color::White);
	info_text.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	
	window.draw(info_text);
}