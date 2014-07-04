#include "SFMLCanvas.h"

SFMLCanvas::SFMLCanvas(QWidget *parent, const QPoint &position, const QSize &size, unsigned int FrameTime) : QWidget(parent), myInitialized(false)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

    move(position);
    resize(size);

    myTimer.setInterval(FrameTime);
}

SFMLCanvas::~SFMLCanvas(){}

void SFMLCanvas::showEvent(QShowEvent *)
{
    if(!myInitialized)
    {
        RenderWindow::create((sf::WindowHandle)QWidget::winId());
        OnInit();

        connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
        myTimer.start();
        myInitialized = true;
    }
}

QPaintEngine *SFMLCanvas::paintEngine() const
{
    return 0;
}

void SFMLCanvas::paintEvent(QPaintEvent *)
{
    OnUpdate();
    RenderWindow::display();
}

void SFMLCanvas::OnInit() {}

void SFMLCanvas::OnUpdate() {}
