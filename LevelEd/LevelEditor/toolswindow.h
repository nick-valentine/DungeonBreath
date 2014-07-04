#ifndef TOOLSWINDOW_H
#define TOOLSWINDOW_H

#include <QMainWindow>

namespace Ui {
class ToolsWindow;
}

class ToolsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ToolsWindow(QWidget *parent = 0);
    ~ToolsWindow();

private:
    Ui::ToolsWindow *ui;
};

#endif // TOOLSWINDOW_H
