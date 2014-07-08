#include "tileboard.h"

TileBoard::TileBoard()
{
}

TileBoard::~TileBoard()
{
}

void TileBoard::init()
{
    my_tex.loadFromFile("img/TileSet.png");
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            sf::Sprite temp(my_tex, sf::IntRect(0, 0, 100, 100));
            temp.setPosition(sf::Vector2f(i * 25, j * 25));
            temp.setScale(0.25f, 0.25f);
            my_board.push_back(temp);
            board_labels.push_back(wood);
        }
    }

    active_tile = stone;
}

std::vector<std::string> TileBoard::getBoardText()
{
    std::vector<std::string> return_val;
    std::string temp = "";

    for(int j = 0; j < height; ++j)
    {
        for(int i = 0; i < width; ++i)
        {
            if(board_labels[(i * width) + j] == wood)
            {
                temp += "w";
            }
            else if(board_labels[(i * width) + j] == stone)
            {
                temp += "t";
            }
        }
        temp += "\n";
        return_val.push_back(temp);
        temp = "";
    }

    return return_val;
}

TileBoard::Tile TileBoard::get_active_tile()
{
    return active_tile;
}

void TileBoard::set_active_tile(Tile newTile)
{
    this->active_tile = newTile;
}

void TileBoard::update(sf::RenderWindow &window)
{
    for(int i = 0; i < area; ++i)
    {
        if(my_board[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if(active_tile == wood)
                {
                    my_board[i].setTextureRect(sf::IntRect(0, 0, 100, 100));
                    board_labels[i] = wood;
                }
                else if(active_tile == stone)
                {
                    my_board[i].setTextureRect(sf::IntRect(100, 0, 100, 100));
                    board_labels[i] = stone;
                }
            }
        }
    }

}

void TileBoard::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < area; ++i)
    {
        window.draw(my_board[i]);
    }
}
