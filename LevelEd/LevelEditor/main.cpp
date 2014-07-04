#include "toolswindow.h"
#include <QApplication>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

void sfml();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolsWindow w;
    w.show();

    sf::Thread sfml_thread(&sfml);
    sfml_thread.launch();

    int returnval = a.exec();

    sfml_thread.wait();

    return returnval;
}

void sfml()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Level Editor");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                exit(1);
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
