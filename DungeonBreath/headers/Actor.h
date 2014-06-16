#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "TextureMap.h"

class Actor
{
 public:
 	Actor();
 	void init(int pos_x, int pos_y, int size_x, int size_y, std::string image_name);
 	
 	virtual void update(int delta) = 0;
 	virtual void draw(sf::RenderWindow &window) = 0;
 	
 	int get_pos_x() const;
 	int get_pos_y() const;
 	
 	int get_size_x() const;
 	int get_size_y() const;
 	
 	std::string get_image_name() const;
 	sf::Texture *get_texture() const;
 	std::vector<sf::Sprite> get_sprites() const;
 	int get_num_sprites() const;
 	
 	sf::Sprite *get_sprite(int x);
 	
 	void set_pos_x(int x);
 	void set_pos_y(int x);
 	
 	void set_size_x(int x);
 	void set_size_y(int x);
 	
 	void set_texture(std::string image_name);
 	int add_sprite(int pos_x, int pos_y, int width, int height);
 	
 private:
 	int pos_x;
 	int pos_y;
 	
 	int size_x;
 	int size_y;
 	
 	sf::Texture *tex;
 	std::string texture_name;
 	std::vector<sf::Sprite> sprites;
 	
 	TextureMap my_map;
};

#endif //ACTOR_H
