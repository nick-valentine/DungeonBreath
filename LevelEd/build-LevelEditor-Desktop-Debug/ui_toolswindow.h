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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
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
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuOptions;

    void setupUi(QMainWindow *ToolsWindow)
    {
        if (ToolsWindow->objectName().isEmpty())
            ToolsWindow->setObjectName(QString::fromUtf8("ToolsWindow"));
        ToolsWindow->resize(178, 528);
        actionSave = new QAction(ToolsWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralWidget = new QWidget(ToolsWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TileSelector = new QComboBox(centralWidget);
        TileSelector->setObjectName(QString::fromUtf8("TileSelector"));
        TileSelector->setGeometry(QRect(10, 10, 85, 27));
        ToolsWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(ToolsWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ToolsWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ToolsWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ToolsWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(ToolsWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 178, 25));
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
        menuOptions->setTitle(QApplication::translate("ToolsWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ToolsWindow: public Ui_ToolsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWINDOW_H
