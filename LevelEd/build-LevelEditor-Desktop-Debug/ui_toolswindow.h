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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolsWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ToolsWindow)
    {
        if (ToolsWindow->objectName().isEmpty())
            ToolsWindow->setObjectName(QString::fromUtf8("ToolsWindow"));
        ToolsWindow->resize(400, 300);
        menuBar = new QMenuBar(ToolsWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ToolsWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ToolsWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ToolsWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(ToolsWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ToolsWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ToolsWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ToolsWindow->setStatusBar(statusBar);

        retranslateUi(ToolsWindow);

        QMetaObject::connectSlotsByName(ToolsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ToolsWindow)
    {
        ToolsWindow->setWindowTitle(QApplication::translate("ToolsWindow", "ToolsWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ToolsWindow: public Ui_ToolsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWINDOW_H
