#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "SFMLCanvas.h"
#include <vector>

class MyCanvas : public SFMLCanvas
{
public:
    MyCanvas(QWidget *parent, const QPoint &position, const QSize &size);
    void OnInit();
    void OnUpdate();
private:
    static const int height = 16;
    static const int width = 16;
    static const int area = 16 * 16;

    sf::Clock myClock;
    sf::Texture myTex;
    std::vector<sf::Sprite> mySprite;
};

#endif // MYCANVAS_H
