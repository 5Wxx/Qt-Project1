#include "eventcolorbutton.h"
#include <QPainter>
#include <QCursor>
#include <QDebug>
eventColorButton::eventColorButton(QWidget *parent)
    : QWidget{parent}
{
}

void eventColorButton::mousePressEvent(QMouseEvent *event)
{
    pic.load(presspic);
    update();
    emit clicked();
}

void eventColorButton::mouseReleaseEvent(QMouseEvent *event)
{
    pic.load(releasepic);
    update();
}

void eventColorButton::leaveEvent(QEvent *event)
{
    pic.load(leavepic);
    setCursor(Qt::ArrowCursor);
    update();
}

void eventColorButton::enterEvent(QEvent *event)
{
    pic.load(enterpic);
    setCursor(Qt::PointingHandCursor);
    update();
}

void eventColorButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect = this->rect();
    int x = rect.center().x() - pic.width() / 2;
    int y = rect.center().y() - pic.height() / 2;
    QRect targetRect(x, y, pic.width(), pic.height());
    painter.drawPixmap(targetRect, pic);
}

void eventColorButton::initializePixmaps(QString leavePixmapPath, QString enterPixmapPath,QString pressPixmapPath )
{
    leavepic = leavePixmapPath;
    enterpic = enterPixmapPath;
    presspic = pressPixmapPath;
    releasepic = enterPixmapPath;
    pic.load(leavepic);
    setMinimumSize(16, 16);
}
