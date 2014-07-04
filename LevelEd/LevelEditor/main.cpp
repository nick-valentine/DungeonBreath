#include "toolswindow.h"
#include "tileboard.h"

#include <QApplication>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

void sfml(ToolsWindow *tools);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolsWindow *w = new ToolsWindow;
    w->show();

    sf::Thread sfml_thread(&sfml, w);
    sfml_thread.launch();

    int returnval = a.exec();

    sfml_thread.wait();

    return returnval;
}

void sfml(ToolsWindow *tools)
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Level Editor");

    TileBoard my_board;
    my_board.init();

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                exit(0);
            }
        }
        my_board.set_active_tile((TileBoard::Tile)tools->get_active_tile_index());

        my_board.update(window);

        window.clear();
        my_board.draw(window);
        window.display();
    }
}
