#include "MyCanvas.h"
#include <string>
#include <QDir>
#include <iostream>

MyCanvas::MyCanvas(QWidget *parent, const QPoint &position, const QSize &size) : SFMLCanvas(parent, position, size)
{

}

void MyCanvas::OnInit()
{
    QString dir = QDir::currentPath();
    std::string utf8_dir = dir.toUtf8().constData();
    if(!myTex.loadFromFile(utf8_dir + "/img/TileSet.png"))
    {
        std::cout<<"Failed to load image: "<<utf8_dir<<"/img/TileSet.png"<<std::endl;
        exit( 1 );
    }

    for(int i = 0; i < area; ++i)
    {
        mySprite.push_back(sf::Sprite());
    }

    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            mySprite[(j * width) + i].setTexture(myTex);
            mySprite[(j * width) + i].setPosition(i * 25, j * 25);
            mySprite[(j * width) + i].setScale(sf::Vector2f(0.25f, 0.25f));
            mySprite[(j * width) + i].setTextureRect(sf::IntRect(0, 0, 100, 100));
        }
    }
    myClock.restart();
}

void MyCanvas::OnUpdate()
{
    RenderWindow::clear(sf::Color(255, 255, 255));
    for(int i = 0; i < area; ++i)
    {
        RenderWindow::draw(mySprite[i]);
    }
    myClock.restart();
}
