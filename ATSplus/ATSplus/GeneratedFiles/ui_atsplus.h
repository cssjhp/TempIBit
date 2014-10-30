/********************************************************************************
** Form generated from reading UI file 'atsplus.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATSPLUS_H
#define UI_ATSPLUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATSplusClass
{
public:
    QAction *actionLogin;
    QAction *actionAcuity_Test;
    QAction *actionCover_Test;
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionSettings;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ATSplusClass)
    {
        if (ATSplusClass->objectName().isEmpty())
            ATSplusClass->setObjectName(QStringLiteral("ATSplusClass"));
        ATSplusClass->resize(514, 132);
        actionLogin = new QAction(ATSplusClass);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ATSplus/Resources/Login Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLogin->setIcon(icon);
        actionAcuity_Test = new QAction(ATSplusClass);
        actionAcuity_Test->setObjectName(QStringLiteral("actionAcuity_Test"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ATSplus/Resources/acurityTest1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAcuity_Test->setIcon(icon1);
        actionCover_Test = new QAction(ATSplusClass);
        actionCover_Test->setObjectName(QStringLiteral("actionCover_Test"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ATSplus/Resources/coverTest.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCover_Test->setIcon(icon2);
        actionExit = new QAction(ATSplusClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ATSplus/Resources/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionHelp = new QAction(ATSplusClass);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/ATSplus/Resources/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon4);
        actionSettings = new QAction(ATSplusClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/ATSplus/Resources/Setting-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon5);
        centralWidget = new QWidget(ATSplusClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ATSplusClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ATSplusClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 514, 21));
        menuBar->setNativeMenuBar(false);
        ATSplusClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ATSplusClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(48, 48));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ATSplusClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ATSplusClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ATSplusClass->setStatusBar(statusBar);

        mainToolBar->addAction(actionLogin);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAcuity_Test);
        mainToolBar->addAction(actionCover_Test);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSettings);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExit);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionHelp);

        retranslateUi(ATSplusClass);

        QMetaObject::connectSlotsByName(ATSplusClass);
    } // setupUi

    void retranslateUi(QMainWindow *ATSplusClass)
    {
        ATSplusClass->setWindowTitle(QApplication::translate("ATSplusClass", "ATSplus", 0));
        actionLogin->setText(QApplication::translate("ATSplusClass", "Login", 0));
#ifndef QT_NO_TOOLTIP
        actionLogin->setToolTip(QApplication::translate("ATSplusClass", "Login", 0));
#endif // QT_NO_TOOLTIP
        actionLogin->setShortcut(QApplication::translate("ATSplusClass", "Shift+L", 0));
        actionAcuity_Test->setText(QApplication::translate("ATSplusClass", "Acuity Test", 0));
#ifndef QT_NO_TOOLTIP
        actionAcuity_Test->setToolTip(QApplication::translate("ATSplusClass", "Visual Acuity Test", 0));
#endif // QT_NO_TOOLTIP
        actionCover_Test->setText(QApplication::translate("ATSplusClass", "Cover Test", 0));
#ifndef QT_NO_TOOLTIP
        actionCover_Test->setToolTip(QApplication::translate("ATSplusClass", "Cover Test", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("ATSplusClass", "Exit", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("ATSplusClass", "Exit", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("ATSplusClass", "Ctrl+X", 0));
        actionHelp->setText(QApplication::translate("ATSplusClass", "Help", 0));
#ifndef QT_NO_TOOLTIP
        actionHelp->setToolTip(QApplication::translate("ATSplusClass", "Help", 0));
#endif // QT_NO_TOOLTIP
        actionHelp->setShortcut(QApplication::translate("ATSplusClass", "Ctrl+H", 0));
        actionSettings->setText(QApplication::translate("ATSplusClass", "Settings", 0));
#ifndef QT_NO_TOOLTIP
        actionSettings->setToolTip(QApplication::translate("ATSplusClass", "Settings", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ATSplusClass: public Ui_ATSplusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATSPLUS_H
