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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_settingdialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *musicbutton;
    QLabel *musiclabel;
    QLabel *songNumLabel;
    QPushButton *filebutton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QSlider *musicSlider;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bmusicbutton;
    QLabel *bmusiclabel;
    QComboBox *bmusicBox;
    QPushButton *filebutton2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QSlider *bmusicSlider;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpinBox *worktBox;
    QLabel *label;
    QSpinBox *sleeptBox;

    void setupUi(QDialog *settingdialog)
    {
        if (settingdialog->objectName().isEmpty())
            settingdialog->setObjectName(QString::fromUtf8("settingdialog"));
        settingdialog->resize(234, 158);
        settingdialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(settingdialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        musicbutton = new QPushButton(settingdialog);
        musicbutton->setObjectName(QString::fromUtf8("musicbutton"));
        musicbutton->setCursor(QCursor(Qt::PointingHandCursor));
        musicbutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"}"));

        horizontalLayout->addWidget(musicbutton);

        musiclabel = new QLabel(settingdialog);
        musiclabel->setObjectName(QString::fromUtf8("musiclabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(musiclabel->sizePolicy().hasHeightForWidth());
        musiclabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(11);
        musiclabel->setFont(font);

        horizontalLayout->addWidget(musiclabel);

        songNumLabel = new QLabel(settingdialog);
        songNumLabel->setObjectName(QString::fromUtf8("songNumLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(songNumLabel->sizePolicy().hasHeightForWidth());
        songNumLabel->setSizePolicy(sizePolicy1);
        songNumLabel->setFont(font);

        horizontalLayout->addWidget(songNumLabel);

        filebutton = new QPushButton(settingdialog);
        filebutton->setObjectName(QString::fromUtf8("filebutton"));
        filebutton->setCursor(QCursor(Qt::PointingHandCursor));
        filebutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(153, 153, 153, 60);\n"
"	border-radius:4px;\n"
"}"));

        horizontalLayout->addWidget(filebutton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        musicSlider = new QSlider(settingdialog);
        musicSlider->setObjectName(QString::fromUtf8("musicSlider"));
        musicSlider->setStyleSheet(QString::fromUtf8(" QSlider::groove:horizontal {\n"
"     height: 4px; \n"
"     background:rgba(135, 135, 135, 50)\n"
" }\n"
"\n"
" QSlider::handle:horizontal {\n"
"	 background:rgb(207, 68, 53);\n"
"     width: 16px;\n"
"     margin-top: -5px; \n"
"     margin-bottom:-5px;\n"
"     border-radius: 5px;\n"
" }\n"
"QSlider::sub-page:horizontal{\n"
"background:rgba(255, 85, 65, 100);\n"
"}\n"
""));
        musicSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_3->addWidget(musicSlider);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 7);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        bmusicbutton = new QPushButton(settingdialog);
        bmusicbutton->setObjectName(QString::fromUtf8("bmusicbutton"));
        bmusicbutton->setCursor(QCursor(Qt::PointingHandCursor));
        bmusicbutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"}"));

        horizontalLayout_2->addWidget(bmusicbutton);

        bmusiclabel = new QLabel(settingdialog);
        bmusiclabel->setObjectName(QString::fromUtf8("bmusiclabel"));
        bmusiclabel->setFont(font);

        horizontalLayout_2->addWidget(bmusiclabel);

        bmusicBox = new QComboBox(settingdialog);
        bmusicBox->setObjectName(QString::fromUtf8("bmusicBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bmusicBox->sizePolicy().hasHeightForWidth());
        bmusicBox->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift Light"));
        font1.setPointSize(10);
        bmusicBox->setFont(font1);
        bmusicBox->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(bmusicBox);

        filebutton2 = new QPushButton(settingdialog);
        filebutton2->setObjectName(QString::fromUtf8("filebutton2"));
        filebutton2->setCursor(QCursor(Qt::PointingHandCursor));
        filebutton2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(153, 153, 153, 60);\n"
"	border-radius:4px;\n"
"}"));

        horizontalLayout_2->addWidget(filebutton2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        bmusicSlider = new QSlider(settingdialog);
        bmusicSlider->setObjectName(QString::fromUtf8("bmusicSlider"));
        bmusicSlider->setStyleSheet(QString::fromUtf8(" QSlider::groove:horizontal {\n"
"     height: 4px; \n"
"     background:rgba(135, 135, 135, 50)\n"
" }\n"
"\n"
" QSlider::handle:horizontal {\n"
"	 background:rgb(207, 68, 53);\n"
"     width: 16px;\n"
"     margin-top: -5px; \n"
"     margin-bottom:-5px;\n"
"     border-radius: 5px;\n"
" }\n"
"QSlider::sub-page:horizontal{\n"
"background:rgba(255, 85, 65, 100);\n"
"}\n"
""));
        bmusicSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_4->addWidget(bmusicSlider);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 7);
        horizontalLayout_4->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(settingdialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_5->addWidget(label_2, 0, Qt::AlignmentFlag::AlignHCenter);

        worktBox = new QSpinBox(settingdialog);
        worktBox->setObjectName(QString::fromUtf8("worktBox"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bahnschrift"));
        font2.setPointSize(11);
        worktBox->setFont(font2);

        horizontalLayout_5->addWidget(worktBox);

        label = new QLabel(settingdialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_5->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        sleeptBox = new QSpinBox(settingdialog);
        sleeptBox->setObjectName(QString::fromUtf8("sleeptBox"));
        sleeptBox->setFont(font2);

        horizontalLayout_5->addWidget(sleeptBox);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(settingdialog);

        QMetaObject::connectSlotsByName(settingdialog);
    } // setupUi

    void retranslateUi(QDialog *settingdialog)
    {
        settingdialog->setWindowTitle(QCoreApplication::translate("settingdialog", "Dialog", nullptr));
        musicbutton->setText(QString());
        musiclabel->setText(QCoreApplication::translate("settingdialog", "\350\275\273\351\237\263\344\271\220:", nullptr));
        songNumLabel->setText(QCoreApplication::translate("settingdialog", "0\351\246\226", nullptr));
        filebutton->setText(QString());
        bmusicbutton->setText(QString());
        bmusiclabel->setText(QCoreApplication::translate("settingdialog", "\347\231\275\345\231\252\351\237\263:", nullptr));
        filebutton2->setText(QString());
        label_2->setText(QCoreApplication::translate("settingdialog", "\345\267\245\344\275\234\346\227\266\351\227\264", nullptr));
        label->setText(QCoreApplication::translate("settingdialog", "\344\274\221\346\201\257\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingdialog: public Ui_settingdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
