#include "../headers/Button.h"

Button::Button()
{

}

Button::~Button()
{

}

void Button::init(int x, int y, int width, int height, std::string text)
{
	my_pressed = false;
	
	my_rect = sf::Rect<int>(x - 5, y, width, height);
	
	debug_draw = sf::RectangleShape();
	debug_draw.setPosition(sf::Vector2f(x, y));
	debug_draw.setSize(sf::Vector2f(width, height));
	debug_draw.setOutlineColor(sf::Color::Blue);
	debug_draw.setOutlineThickness (1);
	debug_draw.setFillColor(sf::Color::Transparent);
	
	my_font.loadFromFile("./img/Knights Quest.ttf");
	
	my_text = sf::Text(text , my_font);
	my_text.setCharacterSize(30);
	my_text.setStyle(sf::Text::Bold);
	my_text.setColor(sf::Color::Red);
	my_text.setPosition (x, y);
}

void Button::update(int delta, sf::RenderWindow &window)
{
	if(my_rect.contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		my_pressed = true;
	}
	else
	{
		my_pressed = false;
	}
}

void Button::draw(sf::RenderWindow &window)
{
	window.draw(debug_draw);
	window.draw(my_text);
}

bool Button::pressed()
{
	return this->my_pressed;
}
