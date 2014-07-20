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
}

void Inventory::set_hero(Actor *hero)
{
	this->hero = dynamic_cast<Hero *>(hero);
}