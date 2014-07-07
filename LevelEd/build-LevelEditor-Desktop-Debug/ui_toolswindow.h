/********************************************************************************
** Form generated from reading UI file 'toolswindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSWINDOW_H
#define UI_TOOLSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

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
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuOptions;

    void setupUi(QMainWindow *ToolsWindow)
    {
        if (ToolsWindow->objectName().isEmpty())
            ToolsWindow->setObjectName(QString::fromUtf8("ToolsWindow"));
        ToolsWindow->resize(191, 652);
        actionSave = new QAction(ToolsWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralWidget = new QWidget(ToolsWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TileSelector = new QComboBox(centralWidget);
        TileSelector->setObjectName(QString::fromUtf8("TileSelector"));
        TileSelector->setGeometry(QRect(10, 20, 171, 27));
        ActorSelector = new QComboBox(centralWidget);
        ActorSelector->setObjectName(QString::fromUtf8("ActorSelector"));
        ActorSelector->setGeometry(QRect(10, 70, 171, 27));
        SetTileLabel = new QLabel(centralWidget);
        SetTileLabel->setObjectName(QString::fromUtf8("SetTileLabel"));
        SetTileLabel->setGeometry(QRect(10, 0, 67, 17));
        AddActorLabel = new QLabel(centralWidget);
        AddActorLabel->setObjectName(QString::fromUtf8("AddActorLabel"));
        AddActorLabel->setGeometry(QRect(10, 50, 67, 17));
        Mode = new QGroupBox(centralWidget);
        Mode->setObjectName(QString::fromUtf8("Mode"));
        Mode->setGeometry(QRect(10, 100, 161, 111));
        ModeTiles = new QRadioButton(Mode);
        ModeTiles->setObjectName(QString::fromUtf8("ModeTiles"));
        ModeTiles->setGeometry(QRect(0, 50, 117, 22));
        ModeActors = new QRadioButton(Mode);
        ModeActors->setObjectName(QString::fromUtf8("ModeActors"));
        ModeActors->setGeometry(QRect(0, 80, 117, 22));
        ModeNone = new QRadioButton(Mode);
        ModeNone->setObjectName(QString::fromUtf8("ModeNone"));
        ModeNone->setGeometry(QRect(0, 20, 117, 22));
        ModeNone->setChecked(true);
        Group = new QSpinBox(centralWidget);
        Group->setObjectName(QString::fromUtf8("Group"));
        Group->setGeometry(QRect(10, 300, 171, 27));
        Group->setMaximum(99999);
        GroupLabel = new QLabel(centralWidget);
        GroupLabel->setObjectName(QString::fromUtf8("GroupLabel"));
        GroupLabel->setGeometry(QRect(10, 280, 67, 17));
        ActorFactoryLabel = new QLabel(centralWidget);
        ActorFactoryLabel->setObjectName(QString::fromUtf8("ActorFactoryLabel"));
        ActorFactoryLabel->setGeometry(QRect(10, 220, 181, 16));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 210, 191, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        SpawnFrequencyLabel = new QLabel(centralWidget);
        SpawnFrequencyLabel->setObjectName(QString::fromUtf8("SpawnFrequencyLabel"));
        SpawnFrequencyLabel->setGeometry(QRect(10, 520, 121, 16));
        Frequency = new QSpinBox(centralWidget);
        Frequency->setObjectName(QString::fromUtf8("Frequency"));
        Frequency->setGeometry(QRect(10, 560, 171, 27));
        Frequency->setMaximum(999999);
        MicrosecondsLabel = new QLabel(centralWidget);
        MicrosecondsLabel->setObjectName(QString::fromUtf8("MicrosecondsLabel"));
        MicrosecondsLabel->setGeometry(QRect(10, 540, 111, 17));
        TriggerTypeLabel = new QLabel(centralWidget);
        TriggerTypeLabel->setObjectName(QString::fromUtf8("TriggerTypeLabel"));
        TriggerTypeLabel->setGeometry(QRect(10, 340, 121, 17));
        TriggerSelector = new QComboBox(centralWidget);
        TriggerSelector->setObjectName(QString::fromUtf8("TriggerSelector"));
        TriggerSelector->setGeometry(QRect(10, 360, 171, 27));
        NumToKeepAliveLabel = new QLabel(centralWidget);
        NumToKeepAliveLabel->setObjectName(QString::fromUtf8("NumToKeepAliveLabel"));
        NumToKeepAliveLabel->setGeometry(QRect(10, 400, 151, 17));
        NumToKeepAlive = new QSpinBox(centralWidget);
        NumToKeepAlive->setObjectName(QString::fromUtf8("NumToKeepAlive"));
        NumToKeepAlive->setGeometry(QRect(10, 420, 171, 27));
        NumToKeepAlive->setMaximum(99999);
        NumToSpawnLabel = new QLabel(centralWidget);
        NumToSpawnLabel->setObjectName(QString::fromUtf8("NumToSpawnLabel"));
        NumToSpawnLabel->setGeometry(QRect(10, 460, 131, 17));
        NumToSpawn = new QSpinBox(centralWidget);
        NumToSpawn->setObjectName(QString::fromUtf8("NumToSpawn"));
        NumToSpawn->setGeometry(QRect(10, 480, 171, 27));
        NumToSpawn->setMaximum(99999);
        AddToFactory = new QCheckBox(centralWidget);
        AddToFactory->setObjectName(QString::fromUtf8("AddToFactory"));
        AddToFactory->setGeometry(QRect(0, 250, 131, 22));
        ToolsWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(ToolsWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ToolsWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ToolsWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ToolsWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(ToolsWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 191, 25));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        ToolsWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionSave);

        retranslateUi(ToolsWindow);

        QMetaObject::connectSlotsByName(ToolsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ToolsWindow)
    {
        ToolsWindow->setWindowTitle(QApplication::translate("ToolsWindow", "ToolsWindow", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("ToolsWindow", "save", 0, QApplication::UnicodeUTF8));
        TileSelector->clear();
        TileSelector->insertItems(0, QStringList()
         << QApplication::translate("ToolsWindow", "Wood", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "Stone", 0, QApplication::UnicodeUTF8)
        );
        ActorSelector->clear();
        ActorSelector->insertItems(0, QStringList()
         << QApplication::translate("ToolsWindow", "ActorFactory", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "Player", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "EnemyFollower", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "StoneWallBottom", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "StoneWallSide", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "StoneWallCorner", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "Treasure", 0, QApplication::UnicodeUTF8)
        );
        SetTileLabel->setText(QApplication::translate("ToolsWindow", "Set Tile", 0, QApplication::UnicodeUTF8));
        AddActorLabel->setText(QApplication::translate("ToolsWindow", "Add Actor", 0, QApplication::UnicodeUTF8));
        Mode->setTitle(QApplication::translate("ToolsWindow", "Mode", 0, QApplication::UnicodeUTF8));
        ModeTiles->setText(QApplication::translate("ToolsWindow", "Set Tiles", 0, QApplication::UnicodeUTF8));
        ModeActors->setText(QApplication::translate("ToolsWindow", "Add Actors", 0, QApplication::UnicodeUTF8));
        ModeNone->setText(QApplication::translate("ToolsWindow", "None", 0, QApplication::UnicodeUTF8));
        GroupLabel->setText(QApplication::translate("ToolsWindow", "Group", 0, QApplication::UnicodeUTF8));
        ActorFactoryLabel->setText(QApplication::translate("ToolsWindow", "Actor Factory Information", 0, QApplication::UnicodeUTF8));
        SpawnFrequencyLabel->setText(QApplication::translate("ToolsWindow", "Spawn Frequency", 0, QApplication::UnicodeUTF8));
        MicrosecondsLabel->setText(QApplication::translate("ToolsWindow", "(Microseconds)", 0, QApplication::UnicodeUTF8));
        TriggerTypeLabel->setText(QApplication::translate("ToolsWindow", "Trigger Type", 0, QApplication::UnicodeUTF8));
        TriggerSelector->clear();
        TriggerSelector->insertItems(0, QStringList()
         << QApplication::translate("ToolsWindow", "Latch", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "Switch", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "Press", 0, QApplication::UnicodeUTF8)
        );
        NumToKeepAliveLabel->setText(QApplication::translate("ToolsWindow", "Number To Keep Alive", 0, QApplication::UnicodeUTF8));
        NumToSpawnLabel->setText(QApplication::translate("ToolsWindow", "Number To Spawn", 0, QApplication::UnicodeUTF8));
        AddToFactory->setText(QApplication::translate("ToolsWindow", "Add To Factory", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("ToolsWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ToolsWindow: public Ui_ToolsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWINDOW_H