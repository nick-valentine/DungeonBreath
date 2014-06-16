#ifndef TEXTUREMAP_H
#define TEXTUREMAP_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

class TextureMap
{
 public:
 	TextureMap();
 	~TextureMap();
 	
 	sf::Texture* request(std::string file_name);
 	void clear();
 private:
 	static std::map<std::string, sf::Texture> tex_map;
 	//static std::map<int, int> tex_map;
 
};

#endif //TEXTUREMAP_H
