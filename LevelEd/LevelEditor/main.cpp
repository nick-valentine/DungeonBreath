#include <QApplication>
#include <QFrame>
#include "mainwindow.h"
#include "MyCanvas.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFrame *w = new QFrame;
    w->setWindowTitle("Level editor");
    w->resize(440, 440);
    w->show();

    MyCanvas SFMLview(w, QPoint(10, 10), QSize(420, 420));
    SFMLview.show();
    
    return a.exec();
}
