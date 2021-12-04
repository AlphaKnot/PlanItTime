/********************************************************************************
** Form generated from reading UI file 'uiscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UISCREEN_H
#define UI_UISCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIScreen
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UIScreen)
    {
        if (UIScreen->objectName().isEmpty())
            UIScreen->setObjectName(QString::fromUtf8("UIScreen"));
        UIScreen->resize(800, 600);
        centralwidget = new QWidget(UIScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        UIScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UIScreen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        UIScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(UIScreen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UIScreen->setStatusBar(statusbar);

        retranslateUi(UIScreen);

        QMetaObject::connectSlotsByName(UIScreen);
    } // setupUi

    void retranslateUi(QMainWindow *UIScreen)
    {
        UIScreen->setWindowTitle(QCoreApplication::translate("UIScreen", "UIScreen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UIScreen: public Ui_UIScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UISCREEN_H
