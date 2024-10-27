/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_settingdialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *bmusicbutton;
    QLabel *bmusiclabel;
    QLabel *musiclabel;
    QPushButton *musicbutton;
    QComboBox *bmusicBox;

    void setupUi(QDialog *settingdialog)
    {
        if (settingdialog->objectName().isEmpty())
            settingdialog->setObjectName(QString::fromUtf8("settingdialog"));
        settingdialog->resize(215, 132);
        gridLayout = new QGridLayout(settingdialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bmusicbutton = new QPushButton(settingdialog);
        bmusicbutton->setObjectName(QString::fromUtf8("bmusicbutton"));
        bmusicbutton->setCursor(QCursor(Qt::PointingHandCursor));
        bmusicbutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"}"));

        gridLayout->addWidget(bmusicbutton, 1, 2, 1, 1);

        bmusiclabel = new QLabel(settingdialog);
        bmusiclabel->setObjectName(QString::fromUtf8("bmusiclabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(14);
        bmusiclabel->setFont(font);

        gridLayout->addWidget(bmusiclabel, 1, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        musiclabel = new QLabel(settingdialog);
        musiclabel->setObjectName(QString::fromUtf8("musiclabel"));
        musiclabel->setFont(font);

        gridLayout->addWidget(musiclabel, 0, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        musicbutton = new QPushButton(settingdialog);
        musicbutton->setObjectName(QString::fromUtf8("musicbutton"));
        musicbutton->setCursor(QCursor(Qt::PointingHandCursor));
        musicbutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"}"));

        gridLayout->addWidget(musicbutton, 0, 2, 1, 1);

        bmusicBox = new QComboBox(settingdialog);
        bmusicBox->setObjectName(QString::fromUtf8("bmusicBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift Light"));
        font1.setPointSize(10);
        bmusicBox->setFont(font1);
        bmusicBox->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(bmusicBox, 1, 1, 1, 1);


        retranslateUi(settingdialog);

        QMetaObject::connectSlotsByName(settingdialog);
    } // setupUi

    void retranslateUi(QDialog *settingdialog)
    {
        settingdialog->setWindowTitle(QCoreApplication::translate("settingdialog", "Dialog", nullptr));
        bmusicbutton->setText(QString());
        bmusiclabel->setText(QCoreApplication::translate("settingdialog", "\347\231\275\345\231\252\351\237\263", nullptr));
        musiclabel->setText(QCoreApplication::translate("settingdialog", "\350\275\273\351\237\263\344\271\220", nullptr));
        musicbutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class settingdialog: public Ui_settingdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
