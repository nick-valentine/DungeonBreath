#include "../headers/Tile.h"

Tile::Tile() : Actor()
{
}

void Tile::init(int pos_x, int pos_y, int size_x, int size_y, int SpriteX, int SpriteY)
{
    Actor::init(pos_x, pos_y, size_x, size_y, "./img/TileSet.png");
    
    add_sprite((SpriteX - 1) * 100, (SpriteY - 1) * 100, 100, 100);
    
	set_alive(true);

    my_type = Actor::Tile;
    
    set_collide_type(Nothing);
}

void Tile::update(int delta)
{

}

void Tile::draw(sf::RenderWindow &window)
{
    get_sprite(0)->setPosition(get_rect().left, get_rect().top);
    get_sprite(0)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
	window.draw(*get_sprite(0));
}

Actor *Tile::clone()
{
    Tile *temp = new Tile(*this);
    return temp;
}
