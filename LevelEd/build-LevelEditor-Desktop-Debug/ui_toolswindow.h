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
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QRadioButton>
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
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuOptions;

    void setupUi(QMainWindow *ToolsWindow)
    {
        if (ToolsWindow->objectName().isEmpty())
            ToolsWindow->setObjectName(QString::fromUtf8("ToolsWindow"));
        ToolsWindow->resize(277, 528);
        actionSave = new QAction(ToolsWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralWidget = new QWidget(ToolsWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TileSelector = new QComboBox(centralWidget);
        TileSelector->setObjectName(QString::fromUtf8("TileSelector"));
        TileSelector->setGeometry(QRect(10, 50, 151, 27));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 120, 151, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 67, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 67, 17));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 160, 120, 80));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(0, 20, 117, 22));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(0, 50, 117, 22));
        ToolsWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(ToolsWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ToolsWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ToolsWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ToolsWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(ToolsWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 277, 25));
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
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ToolsWindow", "Player", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "EnemyFollower", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "StoneWallBottom", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "StoneWallSide", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "StoneWallCorner", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToolsWindow", "Treasure", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("ToolsWindow", "Set Tile", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ToolsWindow", "Add Actor", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ToolsWindow", "Mode", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("ToolsWindow", "Set Tiles", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("ToolsWindow", "Add Actors", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("ToolsWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ToolsWindow: public Ui_ToolsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWINDOW_H
