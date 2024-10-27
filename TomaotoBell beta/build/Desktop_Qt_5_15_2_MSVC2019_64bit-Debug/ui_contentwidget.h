/********************************************************************************
** Form generated from reading UI file 'contentwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTENTWIDGET_H
#define UI_CONTENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "eventcolorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_contentWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    eventColorButton *settingbutton;
    eventColorButton *stopbutton;
    eventColorButton *playbutton;
    eventColorButton *restartbutton;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *grouplabel;

    void setupUi(QWidget *contentWidget)
    {
        if (contentWidget->objectName().isEmpty())
            contentWidget->setObjectName(QString::fromUtf8("contentWidget"));
        contentWidget->resize(293, 124);
        contentWidget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_2 = new QHBoxLayout(contentWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 9, 0, 9);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        settingbutton = new eventColorButton(contentWidget);
        settingbutton->setObjectName(QString::fromUtf8("settingbutton"));

        verticalLayout->addWidget(settingbutton);

        stopbutton = new eventColorButton(contentWidget);
        stopbutton->setObjectName(QString::fromUtf8("stopbutton"));

        verticalLayout->addWidget(stopbutton);

        playbutton = new eventColorButton(contentWidget);
        playbutton->setObjectName(QString::fromUtf8("playbutton"));

        verticalLayout->addWidget(playbutton);

        restartbutton = new eventColorButton(contentWidget);
        restartbutton->setObjectName(QString::fromUtf8("restartbutton"));

        verticalLayout->addWidget(restartbutton);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(7, 9, -1, 9);
        label = new QLabel(contentWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(48);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: rgb(232, 74, 74);\n"
"}"));

        verticalLayout_2->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        grouplabel = new QLabel(contentWidget);
        grouplabel->setObjectName(QString::fromUtf8("grouplabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift Light"));
        font1.setPointSize(11);
        grouplabel->setFont(font1);
        grouplabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"	color: rgb(255, 85, 0);\n"
"}"));

        verticalLayout_2->addWidget(grouplabel, 0, Qt::AlignmentFlag::AlignHCenter);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);

        retranslateUi(contentWidget);

        QMetaObject::connectSlotsByName(contentWidget);
    } // setupUi

    void retranslateUi(QWidget *contentWidget)
    {
        contentWidget->setWindowTitle(QCoreApplication::translate("contentWidget", "contentWidget", nullptr));
        label->setText(QCoreApplication::translate("contentWidget", "Tomato", nullptr));
        grouplabel->setText(QCoreApplication::translate("contentWidget", "READY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class contentWidget: public Ui_contentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTENTWIDGET_H
