#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QWidget>
#include <QSound>
#include "timecounter.h"
#include "settingdialog.h"
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui {
class contentWidget;
}
QT_END_NAMESPACE

class contentWidget : public QWidget
{
    Q_OBJECT

public:
    TimeCounter *tc;
    contentWidget(QWidget *parent = nullptr);
    void playbuttonHide();
    void playbuttonShow();
    void changeWorktimeSignal();
    ~contentWidget();

private:
    settingdialog *sdialog;
    QSound *transound=new QSound(":/music/tip.wav",this);
    bool isworktime = true;
    int group=1;
    int workt=25;
    int sleept=5;
    Ui::contentWidget *ui;
private slots:
    void resetTc();
};
#endif // CONTENTWIDGET_H
