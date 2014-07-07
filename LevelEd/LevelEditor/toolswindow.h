#ifndef TOOLSWINDOW_H
#define TOOLSWINDOW_H

#include <QMainWindow>
#include "actorboard.h"

namespace Ui {
class ToolsWindow;
}

class ToolsWindow : public QMainWindow
{
    Q_OBJECT

public:
    const static unsigned int MODE_NONE = 0;
    const static unsigned int MODE_TILE = 1;
    const static unsigned int MODE_ACTOR = 2;

    explicit ToolsWindow(QWidget *parent = 0);
    ~ToolsWindow();

    int get_active_tile_index();
    int get_active_actor_index();
    int get_active_mode();
    bool get_add_to_factory();
    ActorBoard::factory_info get_factory();

private:
    Ui::ToolsWindow *ui;

    int active_tile_index;
    int active_actor_index;
    int active_mode;
    ActorBoard::factory_info my_info;
    bool add_to_factory;

public slots:
    void TileSelectorChange(int index);
    void ActorSelectorChange(int index);
    void modeNone(bool checked);
    void modeTile(bool checked);
    void modeActor(bool checked);

    void addToFactory(bool checked);
    void setGroup(int group);
    void setTriggerType(int index);
    void setNumToKeepAlive(int num);
    void setNumToSpawn(int num);
    void setSpawnFrequency(int num);

    void Saved();
};

#endif // TOOLSWINDOW_H
