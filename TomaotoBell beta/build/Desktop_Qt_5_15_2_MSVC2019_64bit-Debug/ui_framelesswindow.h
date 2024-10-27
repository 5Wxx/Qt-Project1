/********************************************************************************
** Form generated from reading UI file 'framelesswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMELESSWINDOW_H
#define UI_FRAMELESSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "eventcolorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_framelessWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *datalo;
    QVBoxLayout *ctrllo;
    QSpacerItem *verticalSpacer_2;
    eventColorButton *closebutton;

    void setupUi(QMainWindow *framelessWindow)
    {
        if (framelessWindow->objectName().isEmpty())
            framelessWindow->setObjectName(QString::fromUtf8("framelessWindow"));
        framelessWindow->resize(318, 125);
        centralwidget = new QWidget(framelessWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 0, 0, 0);
        datalo = new QVBoxLayout();
        datalo->setObjectName(QString::fromUtf8("datalo"));
        datalo->setContentsMargins(-1, -1, -1, 0);

        horizontalLayout->addLayout(datalo);

        ctrllo = new QVBoxLayout();
        ctrllo->setObjectName(QString::fromUtf8("ctrllo"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Minimum);

        ctrllo->addItem(verticalSpacer_2);

        closebutton = new eventColorButton(centralwidget);
        closebutton->setObjectName(QString::fromUtf8("closebutton"));

        ctrllo->addWidget(closebutton);

        ctrllo->setStretch(0, 3);
        ctrllo->setStretch(1, 1);

        horizontalLayout->addLayout(ctrllo);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 1);
        framelessWindow->setCentralWidget(centralwidget);

        retranslateUi(framelessWindow);

        QMetaObject::connectSlotsByName(framelessWindow);
    } // setupUi

    void retranslateUi(QMainWindow *framelessWindow)
    {
        framelessWindow->setWindowTitle(QCoreApplication::translate("framelessWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class framelessWindow: public Ui_framelessWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMELESSWINDOW_H
