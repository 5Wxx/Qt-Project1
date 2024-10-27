#include "contentwidget.h"
#include "ui_contentwidget.h"
#include "eventcolorbutton.h"
#include "settingdialog.h"
#include <QDebug>
#include <QThread>
#include <QDialog>
#include <QDesktopWidget>
contentWidget::contentWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::contentWidget)
{
    //调试用
    // workt=1;
    // sleept=1;

    ui->setupUi(this);
    ui->settingbutton->initializePixmaps(":/CarbonSettingsEdit.svg",":/CarbonSettingsEdit (1).svg",":/CarbonSettingsEdit (2).svg");
    ui->playbutton->initializePixmaps(":/IconoirPlay.svg",":/IconoirPlay (2).svg",":/IconoirPlay (1).svg");
    ui->stopbutton->initializePixmaps(":/IonPauseOutline.svg",":/IonPauseOutline (2).svg",":/IonPauseOutline (1).svg");
    ui->restartbutton->initializePixmaps(":/MaterialSymbolsRestartAltRounded.svg",":/MaterialSymbolsRestartAltRounded (1).svg",":/MaterialSymbolsRestartAltRounded (2).svg");

    sdialog = new settingdialog(this);
    sdialog->initializeBackgroundMusic();
    sdialog->initializeMusic();

    //设置
    connect(ui->settingbutton,&eventColorButton::clicked,[=](){
        sdialog->setWindowTitle("setting");
        sdialog->setModal(true);
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width() - sdialog->width()) / 2;
        int y = (screenGeometry.height() - sdialog->height()) / 2;
        sdialog->move(x,y);
        sdialog->exec();
    });

    workt=sdialog->configdata["workt"].toInt();
    sleept=sdialog->configdata["sleept"].toInt();
    connect(sdialog,&settingdialog::resetTime,this,&contentWidget::resetTc);

    tc=new TimeCounter(workt*60);

    connect(tc,&TimeCounter::changeTimeLabel,[this](){
        ui->label->setText(tc->getRemainingTime());
    });

    connect(tc,&TimeCounter::finished,[this](){
        ui->label->setText(tc->getRemainingTime());
        changeWorktimeSignal();
        transound->play();  //播放
        transound->setLoops(1);
        if(isworktime){
            group++;
            ui->grouplabel->setText("Group "+QString::number(group));
            tc->resetdata(workt*60);
            ui->label->setStyleSheet("QLabel{color: rgb(232, 74, 74);}");
        }else{
            tc->resetdata(sleept*60);
            ui->label->setStyleSheet("QLabel{color: rgb(100,214,143);}");
        }
        tc->start();
    });


    //开始
    connect(ui->playbutton,&eventColorButton::clicked,[this](){
        tc->start();
        playbuttonHide();
        ui->grouplabel->setText("Group "+QString::number(group));
    });
    //暂停
    connect(ui->stopbutton,&eventColorButton::clicked,[this](){
        tc->stop();
        playbuttonShow();
    });
    //重启
    connect(ui->restartbutton,&eventColorButton::clicked,this, &contentWidget::resetTc);
    playbuttonShow();
}

void contentWidget::playbuttonHide()
{
    ui->playbutton->hide();
    ui->stopbutton->show();
}

void contentWidget::playbuttonShow()
{
    ui->stopbutton->hide();
    ui->playbutton->show();
}

void contentWidget::changeWorktimeSignal()
{
    isworktime=!isworktime;
}

void contentWidget::resetTc()
{
    workt=sdialog->configdata["workt"].toInt();
    sleept=sdialog->configdata["sleept"].toInt();
    tc->resetdata(workt*60);
    ui->label->setText(tc->getRemainingTime());
    tc->stop();
    playbuttonShow();
    ui->label->setStyleSheet("QLabel{color: rgb(232, 74, 74);}");
    isworktime=true;
    group=1;
    ui->grouplabel->setText("Group "+QString::number(group));
}


contentWidget::~contentWidget()
{
    delete sdialog;
    delete transound;
    delete tc;
    delete ui;
}


