#include "toolswindow.h"
#include "ui_toolswindow.h"

ToolsWindow::ToolsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ToolsWindow)
{
    ui->setupUi(this);

    this->active_mode = 0;
    this->active_tile_index = 0;
    this->active_actor_index = 0;

    QObject::connect(ui->TileSelector, SIGNAL(currentIndexChanged(int)),
                          this, SLOT(TileSelectorChange(int)));

    QObject::connect(ui->ModeNone, SIGNAL(clicked(bool)),
                            this, SLOT(modeNone(bool)));

    QObject::connect(ui->ModeTiles, SIGNAL(clicked(bool)),
                            this, SLOT(modeTile(bool)));

    QObject::connect(ui->ActorSelector, SIGNAL(currentIndexChanged(int)),
                            this, SLOT(ActorSelectorChange(int)));

    QObject::connect(ui->ModeActors, SIGNAL(clicked(bool)),
                            this, SLOT(modeActor(bool)));

    QObject::connect(ui->AddToFactory, SIGNAL(clicked(bool)),
                            this, SLOT(addToFactory(bool)));

    QObject::connect(ui->Group, SIGNAL(valueChanged(int)),
                            this, SLOT(setGroup(int)));

    QObject::connect(ui->TriggerSelector, SIGNAL(currentIndexChanged(int)),
                            this, SLOT(setTriggerType(int)));

    QObject::connect(ui->NumToKeepAlive, SIGNAL(valueChanged(int)),
                            this, SLOT(setNumToKeepAlive(int)));

    QObject::connect(ui->NumToSpawn, SIGNAL(valueChanged(int)),
                            this, SLOT(setNumToSpawn(int)));

    QObject::connect(ui->Frequency, SIGNAL(valueChanged(int)),
                            this, SLOT(setSpawnFrequency(int)));

    QObject::connect(ui->actionSave, SIGNAL(triggered()),
                            this, SLOT(Saved()));
}

ToolsWindow::~ToolsWindow()
{
    delete ui;
}

int ToolsWindow::get_active_tile_index()
{
    return this->active_tile_index;
}

int ToolsWindow::get_active_actor_index()
{
    return this->active_actor_index;
}

int ToolsWindow::get_active_mode()
{
    return this->active_mode;
}

bool ToolsWindow::get_add_to_factory()
{
    return add_to_factory;
}

ActorBoard::factory_info ToolsWindow::get_factory()
{
    return this->my_info;
}

void ToolsWindow::TileSelectorChange(int index)
{
    this->active_tile_index = index;
}

void ToolsWindow::ActorSelectorChange(int index)
{
    this->active_actor_index = index;
}

void ToolsWindow::modeNone(bool checked)
{
    if(checked)
    {
        active_mode = MODE_NONE;
    }
}

void ToolsWindow::modeTile(bool checked)
{
    if(checked)
    {
        active_mode = MODE_TILE;
    }
}

void ToolsWindow::modeActor(bool checked)
{
    if(checked)
    {
        active_mode = MODE_ACTOR;
    }
}

void ToolsWindow::addToFactory(bool checked)
{
    this->add_to_factory = checked;
}

void ToolsWindow::setGroup(int group)
{
    this->my_info.group = group;
}

void ToolsWindow::setTriggerType(int index)
{
    this->my_info.trigger = (ActorBoard::trigger_type)index;
}

void ToolsWindow::setNumToKeepAlive(int num)
{
    this->my_info.num_to_keep_alive = num;
}

void ToolsWindow::setNumToSpawn(int num)
{
    this->my_info.num_to_spawn = num;
}

void ToolsWindow::setSpawnFrequency(int num)
{
    this->my_info.spawn_frequency = num;
}

void ToolsWindow::Saved()
{
    std::cout<<"Saved!\n";
}
