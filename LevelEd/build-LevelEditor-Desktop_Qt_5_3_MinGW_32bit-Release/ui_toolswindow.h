/********************************************************************************
** Form generated from reading UI file 'toolswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSWINDOW_H
#define UI_TOOLSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolsWindow
{
public:
    QAction *actionSave;
    QWidget *centralWidget;
    QComboBox *TileSelector;
    QComboBox *ActorSelector;
    QLabel *SetTileLabel;
    QLabel *AddActorLabel;
    QGroupBox *Mode;
    QRadioButton *ModeTiles;
    QRadioButton *ModeActors;
    QRadioButton *ModeNone;
    QSpinBox *Group;
    QLabel *GroupLabel;
    QLabel *ActorFactoryLabel;
    QFrame *line;
    QLabel *SpawnFrequencyLabel;
    QSpinBox *Frequency;
    QLabel *MicrosecondsLabel;
    QLabel *TriggerTypeLabel;
    QComboBox *TriggerSelector;
    QLabel *NumToKeepAliveLabel;
    QSpinBox *NumToKeepAlive;
    QLabel *NumToSpawnLabel;
    QSpinBox *NumToSpawn;
    QCheckBox *AddToFactory;
    QLabel *SensitivityLabel;
    QComboBox *TriggerSensitivity;
    QLabel *SidesLabel;
    QSpinBox *TopInput;
    QLabel *TopLabel;
    QSpinBox *RightInput;
    QLabel *RightLabel;
    QSpinBox *LeftInput;
    QLabel *LeftLabel;
    QSpinBox *BottomInput;
    QLabel *BottomLabel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuOptions;

    void setupUi(QMainWindow *ToolsWindow)
    {
        if (ToolsWindow->objectName().isEmpty())
            ToolsWindow->setObjectName(QStringLiteral("ToolsWindow"));
        ToolsWindow->resize(238, 900);
        actionSave = new QAction(ToolsWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(ToolsWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TileSelector = new QComboBox(centralWidget);
        TileSelector->setObjectName(QStringLiteral("TileSelector"));
        TileSelector->setGeometry(QRect(10, 20, 201, 27));
        ActorSelector = new QComboBox(centralWidget);
        ActorSelector->setObjectName(QStringLiteral("ActorSelector"));
        ActorSelector->setGeometry(QRect(10, 70, 201, 27));
        SetTileLabel = new QLabel(centralWidget);
        SetTileLabel->setObjectName(QStringLiteral("SetTileLabel"));
        SetTileLabel->setGeometry(QRect(10, 0, 67, 17));
        AddActorLabel = new QLabel(centralWidget);
        AddActorLabel->setObjectName(QStringLiteral("AddActorLabel"));
        AddActorLabel->setGeometry(QRect(10, 50, 67, 17));
        Mode = new QGroupBox(centralWidget);
        Mode->setObjectName(QStringLiteral("Mode"));
        Mode->setGeometry(QRect(10, 100, 161, 111));
        ModeTiles = new QRadioButton(Mode);
        ModeTiles->setObjectName(QStringLiteral("ModeTiles"));
        ModeTiles->setGeometry(QRect(0, 50, 117, 22));
        ModeActors = new QRadioButton(Mode);
        ModeActors->setObjectName(QStringLiteral("ModeActors"));
        ModeActors->setGeometry(QRect(0, 80, 117, 22));
        ModeNone = new QRadioButton(Mode);
        ModeNone->setObjectName(QStringLiteral("ModeNone"));
        ModeNone->setGeometry(QRect(0, 20, 117, 22));
        ModeNone->setChecked(true);
        Group = new QSpinBox(centralWidget);
        Group->setObjectName(QStringLiteral("Group"));
        Group->setGeometry(QRect(10, 450, 211, 27));
        Group->setMaximum(99999);
        GroupLabel = new QLabel(centralWidget);
        GroupLabel->setObjectName(QStringLiteral("GroupLabel"));
        GroupLabel->setGeometry(QRect(10, 430, 67, 17));
        ActorFactoryLabel = new QLabel(centralWidget);
        ActorFactoryLabel->setObjectName(QStringLiteral("ActorFactoryLabel"));
        ActorFactoryLabel->setGeometry(QRect(10, 370, 181, 16));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 360, 231, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        SpawnFrequencyLabel = new QLabel(centralWidget);
        SpawnFrequencyLabel->setObjectName(QStringLiteral("SpawnFrequencyLabel"));
        SpawnFrequencyLabel->setGeometry(QRect(10, 730, 121, 16));
        Frequency = new QSpinBox(centralWidget);
        Frequency->setObjectName(QStringLiteral("Frequency"));
        Frequency->setGeometry(QRect(10, 770, 211, 27));
        Frequency->setMaximum(999999);
        MicrosecondsLabel = new QLabel(centralWidget);
        MicrosecondsLabel->setObjectName(QStringLiteral("MicrosecondsLabel"));
        MicrosecondsLabel->setGeometry(QRect(10, 750, 111, 17));
        TriggerTypeLabel = new QLabel(centralWidget);
        TriggerTypeLabel->setObjectName(QStringLiteral("TriggerTypeLabel"));
        TriggerTypeLabel->setGeometry(QRect(10, 550, 121, 17));
        TriggerSelector = new QComboBox(centralWidget);
        TriggerSelector->setObjectName(QStringLiteral("TriggerSelector"));
        TriggerSelector->setGeometry(QRect(10, 570, 211, 27));
        NumToKeepAliveLabel = new QLabel(centralWidget);
        NumToKeepAliveLabel->setObjectName(QStringLiteral("NumToKeepAliveLabel"));
        NumToKeepAliveLabel->setGeometry(QRect(10, 610, 151, 17));
        NumToKeepAlive = new QSpinBox(centralWidget);
        NumToKeepAlive->setObjectName(QStringLiteral("NumToKeepAlive"));
        NumToKeepAlive->setGeometry(QRect(10, 630, 211, 27));
        NumToKeepAlive->setMaximum(99999);
        NumToSpawnLabel = new QLabel(centralWidget);
        NumToSpawnLabel->setObjectName(QStringLiteral("NumToSpawnLabel"));
        NumToSpawnLabel->setGeometry(QRect(10, 670, 131, 17));
        NumToSpawn = new QSpinBox(centralWidget);
        NumToSpawn->setObjectName(QStringLiteral("NumToSpawn"));
        NumToSpawn->setGeometry(QRect(10, 690, 211, 27));
        NumToSpawn->setMaximum(99999);
        AddToFactory = new QCheckBox(centralWidget);
        AddToFactory->setObjectName(QStringLiteral("AddToFactory"));
        AddToFactory->setGeometry(QRect(10, 400, 131, 22));
        SensitivityLabel = new QLabel(centralWidget);
        SensitivityLabel->setObjectName(QStringLiteral("SensitivityLabel"));
        SensitivityLabel->setGeometry(QRect(10, 490, 131, 17));
        TriggerSensitivity = new QComboBox(centralWidget);
        TriggerSensitivity->setObjectName(QStringLiteral("TriggerSensitivity"));
        TriggerSensitivity->setGeometry(QRect(10, 510, 211, 27));
        SidesLabel = new QLabel(centralWidget);
        SidesLabel->setObjectName(QStringLiteral("SidesLabel"));
        SidesLabel->setGeometry(QRect(10, 220, 67, 17));
        TopInput = new QSpinBox(centralWidget);
        TopInput->setObjectName(QStringLiteral("TopInput"));
        TopInput->setGeometry(QRect(70, 270, 151, 27));
        TopLabel = new QLabel(centralWidget);
        TopLabel->setObjectName(QStringLiteral("TopLabel"));
        TopLabel->setGeometry(QRect(10, 280, 31, 17));
        RightInput = new QSpinBox(centralWidget);
        RightInput->setObjectName(QStringLiteral("RightInput"));
        RightInput->setGeometry(QRect(70, 300, 151, 27));
        RightLabel = new QLabel(centralWidget);
        RightLabel->setObjectName(QStringLiteral("RightLabel"));
        RightLabel->setGeometry(QRect(10, 310, 41, 17));
        LeftInput = new QSpinBox(centralWidget);
        LeftInput->setObjectName(QStringLiteral("LeftInput"));
        LeftInput->setGeometry(QRect(70, 240, 151, 27));
        LeftLabel = new QLabel(centralWidget);
        LeftLabel->setObjectName(QStringLiteral("LeftLabel"));
        LeftLabel->setGeometry(QRect(10, 250, 31, 17));
        BottomInput = new QSpinBox(centralWidget);
        BottomInput->setObjectName(QStringLiteral("BottomInput"));
        BottomInput->setGeometry(QRect(70, 330, 151, 27));
        BottomLabel = new QLabel(centralWidget);
        BottomLabel->setObjectName(QStringLiteral("BottomLabel"));
        BottomLabel->setGeometry(QRect(10, 340, 67, 17));
        ToolsWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(ToolsWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ToolsWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ToolsWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ToolsWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(ToolsWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 238, 25));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        ToolsWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionSave);

        retranslateUi(ToolsWindow);

        QMetaObject::connectSlotsByName(ToolsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ToolsWindow)
    {
        ToolsWindow->setWindowTitle(QApplication::translate("ToolsWindow", "ToolsWindow", 0));
        actionSave->setText(QApplication::translate("ToolsWindow", "save", 0));
        TileSelector->clear();
        TileSelector->insertItems(0, QStringList()
         << QApplication::translate("ToolsWindow", "Wood", 0)
         << QApplication::translate("ToolsWindow", "Stone", 0)
        );
        ActorSelector->clear();
        ActorSelector->insertItems(0, QStringList()
         << QApplication::translate("ToolsWindow", "ActorFactory", 0)
         << QApplication::translate("ToolsWindow", "Player", 0)
         << QApplication::translate("ToolsWindow", "EnemyFollower", 0)
         << QApplication::translate("ToolsWindow", "StoneWallBottom", 0)
         << QApplication::translate("ToolsWindow", "StoneWallSide", 0)
         << QApplication::translate("ToolsWindow", "StoneWallCorner", 0)
         << QApplication::translate("ToolsWindow", "Treasure", 0)
         << QApplication::translate("ToolsWindow", "Vampire", 0)
        );
        SetTileLabel->setText(QApplication::translate("ToolsWindow", "Set Tile", 0));
        AddActorLabel->setText(QApplication::translate("ToolsWindow", "Add Actor", 0));
        Mode->setTitle(QApplication::translate("ToolsWindow", "Mode", 0));
        ModeTiles->setText(QApplication::translate("ToolsWindow", "Set Tiles", 0));
        ModeActors->setText(QApplication::translate("ToolsWindow", "Add Actors", 0));
        ModeNone->setText(QApplication::translate("ToolsWindow", "None", 0));
        GroupLabel->setText(QApplication::translate("ToolsWindow", "Group", 0));
        ActorFactoryLabel->setText(QApplication::translate("ToolsWindow", "Actor Factory Information", 0));
        SpawnFrequencyLabel->setText(QApplication::translate("ToolsWindow", "Spawn Frequency", 0));
        MicrosecondsLabel->setText(QApplication::translate("ToolsWindow", "(Microseconds)", 0));
        TriggerTypeLabel->setText(QApplication::translate("ToolsWindow", "Trigger Type", 0));
        TriggerSelector->clear();
        TriggerSelector->insertItems(0, QStringList()
         << QApplication::translate("ToolsWindow", "Latch", 0)
         << QApplication::translate("ToolsWindow", "Switch", 0)
         << QApplication::translate("ToolsWindow", "Press", 0)
        );
        NumToKeepAliveLabel->setText(QApplication::translate("ToolsWindow", "Number To Keep Alive", 0));
        NumToSpawnLabel->setText(QApplication::translate("ToolsWindow", "Number To Spawn", 0));
        AddToFactory->setText(QApplication::translate("ToolsWindow", "Add To Factory", 0));
        SensitivityLabel->setText(QApplication::translate("ToolsWindow", "Trigger Sensitivity", 0));
        TriggerSensitivity->clear();
        TriggerSensitivity->insertItems(0, QStringList()
         << QApplication::translate("ToolsWindow", "All", 0)
         << QApplication::translate("ToolsWindow", "Tile", 0)
         << QApplication::translate("ToolsWindow", "Player", 0)
         << QApplication::translate("ToolsWindow", "Block", 0)
         << QApplication::translate("ToolsWindow", "Enemy", 0)
         << QApplication::translate("ToolsWindow", "Spell", 0)
         << QApplication::translate("ToolsWindow", "Sword", 0)
         << QApplication::translate("ToolsWindow", "Trigger", 0)
        );
        SidesLabel->setText(QApplication::translate("ToolsWindow", "Sides", 0));
        TopLabel->setText(QApplication::translate("ToolsWindow", "Top", 0));
        RightLabel->setText(QApplication::translate("ToolsWindow", "Right", 0));
        LeftLabel->setText(QApplication::translate("ToolsWindow", "Left", 0));
        BottomLabel->setText(QApplication::translate("ToolsWindow", "Bottom", 0));
        menuOptions->setTitle(QApplication::translate("ToolsWindow", "Options", 0));
    } // retranslateUi

};

namespace Ui {
    class ToolsWindow: public Ui_ToolsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWINDOW_H
