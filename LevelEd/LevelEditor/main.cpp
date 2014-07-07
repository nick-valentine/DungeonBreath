#include "toolswindow.h"
#include "tileboard.h"
#include "actorboard.h"

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

    TileBoard my_tiles;
    my_tiles.init();

    ActorBoard my_actors;
    my_actors.init();

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
        my_tiles.set_active_tile((TileBoard::Tile)tools->get_active_tile_index());
        my_actors.set_active_actor((ActorBoard::actor)tools->get_active_actor_index());
        my_actors.set_add_to_factory(tools->get_add_to_factory());
        my_actors.set_factory_info(tools->get_factory());

        if(tools->get_active_mode() == ToolsWindow::MODE_TILE)
        {
            my_tiles.update(window);
        }
        else if(tools->get_active_mode() == ToolsWindow::MODE_ACTOR)
        {
            my_actors.update(window);
        }

        window.clear();
        my_tiles.draw(window);
        my_actors.draw(window);
        window.display();
    }
}
