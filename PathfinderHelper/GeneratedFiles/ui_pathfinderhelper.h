﻿/********************************************************************************
** Form generated from reading UI file 'pathfinderhelper.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHFINDERHELPER_H
#define UI_PATHFINDERHELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PathfinderHelperClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QRadioButton *radioButton;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PathfinderHelperClass)
    {
        if (PathfinderHelperClass->objectName().isEmpty())
            PathfinderHelperClass->setObjectName(QStringLiteral("PathfinderHelperClass"));
        PathfinderHelperClass->resize(805, 553);
        centralWidget = new QWidget(PathfinderHelperClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout->addWidget(radioButton);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        PathfinderHelperClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PathfinderHelperClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 805, 21));
        PathfinderHelperClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PathfinderHelperClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PathfinderHelperClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PathfinderHelperClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PathfinderHelperClass->setStatusBar(statusBar);

        retranslateUi(PathfinderHelperClass);

        QMetaObject::connectSlotsByName(PathfinderHelperClass);
    } // setupUi

    void retranslateUi(QMainWindow *PathfinderHelperClass)
    {
        PathfinderHelperClass->setWindowTitle(QApplication::translate("PathfinderHelperClass", "PathfinderHelper", 0));
        label->setText(QApplication::translate("PathfinderHelperClass", "TextLabel", 0));
        radioButton->setText(QApplication::translate("PathfinderHelperClass", "RadioButton", 0));
    } // retranslateUi

};

namespace Ui {
    class PathfinderHelperClass: public Ui_PathfinderHelperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHFINDERHELPER_H
