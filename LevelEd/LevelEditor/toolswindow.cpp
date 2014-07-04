#include "toolswindow.h"
#include "ui_toolswindow.h"

ToolsWindow::ToolsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ToolsWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->TileSelector, SIGNAL(currentIndexChanged(int)),
                          this, SLOT(TileSelectorChange(int)));
}

ToolsWindow::~ToolsWindow()
{
    delete ui;
}

int ToolsWindow::get_active_tile_index()
{
    return this->active_tile_index;
}

void ToolsWindow::TileSelectorChange(int index)
{
    this->active_tile_index = index;
}
