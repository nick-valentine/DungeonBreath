#include "../headers/Tile.h"

Tile::Tile()
{
}

void Tile::init(int pos_x, int pos_y, int size_x, int size_y, int SpriteX, int SpriteY)
{
	this->tex = my_map.request("./img/TileSet.png");
	my_sprite.setTexture(*tex);
	my_sprite.setTextureRect(sf::IntRect((SpriteX - 1) * 100, (SpriteY - 1) * 100, 100, 100));
	my_sprite.setPosition(pos_x, pos_y);
	my_sprite.setScale(size_x / 100.0, size_y / 100.0);
	my_rect = sf::IntRect(pos_x, pos_y, size_x, size_y);
}

void Tile::update(int delta)
{

}

void Tile::draw(sf::RenderWindow &window)
{
	if((abs(hero->get_rect().left - my_rect.left) + abs(hero->get_rect().top - my_rect.top)) < min_distance + min_distance)
	{	
		window.draw(my_sprite);
	}
}

void Tile::set_rect(sf::IntRect new_rect)
{
	my_rect = new_rect;
	my_sprite.setPosition(new_rect.left, new_rect.top);
	my_sprite.setScale(new_rect.width / 100.0, new_rect.height / 100.0);
}

sf::IntRect Tile::get_rect()
{
	return my_rect;
}

void Tile::set_hero(Actor *hero)
{
	this->hero = hero;
}

sf::Sprite Tile::get_sprite()
{
	return this->my_sprite;
}