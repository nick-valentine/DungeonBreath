#ifndef TILEBOARD_H
#define TILEBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

class TileBoard
{
public:
    enum Tile
    {
        wood,
        stone
    };

    TileBoard();
    ~TileBoard();

    void init();

    std::vector<std::string> getBoardText();
    Tile get_active_tile();
    void set_active_tile(Tile newTile);

    void update(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);
private:
    static const int width = 16;
    static const int height = 16;
    static const int area = width * height;


    sf::Texture my_tex;
    std::vector<sf::Sprite> my_board;
    std::vector<Tile> board_labels;

    Tile active_tile;
};

#endif // TILEBOARD_H
