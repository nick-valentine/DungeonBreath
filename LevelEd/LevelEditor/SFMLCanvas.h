#ifndef SFMLCANVAS_H
#define SFMLCANVAS_H

#include <SFML/Graphics.hpp>
#include <QWidget>
#include <QTimer>

class SFMLCanvas : public QWidget, public sf::RenderWindow
{
public:
    explicit SFMLCanvas(QWidget *parent, const QPoint &position, const QSize &size, unsigned int FrameTime = 0);
    virtual void showEvent(QShowEvent *);
    virtual QPaintEngine * paintEngine() const;
    virtual void paintEvent(QPaintEvent *);
    virtual ~SFMLCanvas();
    virtual void OnInit();
    virtual void OnUpdate();
private:
    QTimer myTimer;
    bool myInitialized;
};

#endif // SFMLCANVAS_H
