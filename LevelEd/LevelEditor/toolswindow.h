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

    int get_active_tile_index();

private:
    Ui::ToolsWindow *ui;

    int active_tile_index;

public slots:
    void TileSelectorChange(int index);
};

#endif // TOOLSWINDOW_H
