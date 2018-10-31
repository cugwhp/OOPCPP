/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionNormal_Size;
    QAction *actionFit_to_Window;
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionImage_Information;
    QAction *actionDisplay_Option;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionCopy->setEnabled(false);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QStringLiteral("actionZoom_In"));
        actionZoom_In->setEnabled(false);
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QStringLiteral("actionZoom_Out"));
        actionZoom_Out->setEnabled(false);
        actionNormal_Size = new QAction(MainWindow);
        actionNormal_Size->setObjectName(QStringLiteral("actionNormal_Size"));
        actionNormal_Size->setEnabled(false);
        actionFit_to_Window = new QAction(MainWindow);
        actionFit_to_Window->setObjectName(QStringLiteral("actionFit_to_Window"));
        actionFit_to_Window->setCheckable(true);
        actionFit_to_Window->setChecked(true);
        actionFit_to_Window->setEnabled(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionSave_As->setEnabled(false);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        actionPrint->setEnabled(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionImage_Information = new QAction(MainWindow);
        actionImage_Information->setObjectName(QStringLiteral("actionImage_Information"));
        actionImage_Information->setEnabled(false);
        actionDisplay_Option = new QAction(MainWindow);
        actionDisplay_Option->setObjectName(QStringLiteral("actionDisplay_Option"));
        actionDisplay_Option->setEnabled(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuView->addAction(actionImage_Information);
        menuView->addAction(actionDisplay_Option);
        menuView->addSeparator();
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);
        menuView->addAction(actionNormal_Size);
        menuView->addAction(actionFit_to_Window);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", nullptr));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_In->setText(QApplication::translate("MainWindow", "Zoom In", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_In->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom Out", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_Out->setShortcut(QApplication::translate("MainWindow", "Ctrl+=", nullptr));
#endif // QT_NO_SHORTCUT
        actionNormal_Size->setText(QApplication::translate("MainWindow", "Normal Size", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNormal_Size->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionFit_to_Window->setText(QApplication::translate("MainWindow", "Fit to Window", nullptr));
#ifndef QT_NO_SHORTCUT
        actionFit_to_Window->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionPrint->setText(QApplication::translate("MainWindow", "Print...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionImage_Information->setText(QApplication::translate("MainWindow", "Image Information", nullptr));
#ifndef QT_NO_SHORTCUT
        actionImage_Information->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", nullptr));
#endif // QT_NO_SHORTCUT
        actionDisplay_Option->setText(QApplication::translate("MainWindow", "Display Option", nullptr));
#ifndef QT_NO_SHORTCUT
        actionDisplay_Option->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
