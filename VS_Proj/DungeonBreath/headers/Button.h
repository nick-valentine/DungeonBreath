#ifndef BUTTON_H
#define BUTTON_h

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Button
{
 public:
 	Button();
 	~Button();
 	
 	void init(int x, int y, int width, int height, std::string text);
 	
 	void update(int delta, sf::RenderWindow &window);
 	
 	void draw(sf::RenderWindow &window);
 	
 	bool pressed();
 private:
 	bool my_pressed;
 	sf::Font my_font;
 	sf::Text my_text;
 	sf::Rect<int> my_rect;
 	
 	sf::RectangleShape debug_draw;
};

#endif //BUTTON_H
