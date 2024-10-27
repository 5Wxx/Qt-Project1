#include "togglebutton.h"


#include <QPainter>
#include <QCursor>
#include <QDebug>
toggleButton::toggleButton(QWidget *parent)
    : QWidget{parent}
{
}

void toggleButton::mousePressEvent(QMouseEvent *event)
{
    pic.load(presspic);
    update();
    emit clicked();
}

void toggleButton::mouseReleaseEvent(QMouseEvent *event)
{
    pic.load(releasepic);
    update();
}

void toggleButton::leaveEvent(QEvent *event)
{
    pic.load(leavepic);
    setCursor(Qt::ArrowCursor);
    update();
}

void toggleButton::enterEvent(QEvent *event)
{
    pic.load(enterpic);
    setCursor(Qt::PointingHandCursor);
    update();
}

void toggleButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect = this->rect();
    int x = rect.center().x() - pic.width() / 2;
    int y = rect.center().y() - pic.height() / 2;
    QRect targetRect(x, y, pic.width(), pic.height());
    painter.drawPixmap(targetRect, pic);
}

void toggleButton::initializePixmaps(QString leavePixmapPath, QString enterPixmapPath,QString pressPixmapPath )
{
    leavepic = leavePixmapPath;
    enterpic = enterPixmapPath;
    presspic = pressPixmapPath;
    releasepic = enterPixmapPath;
    pic.load(leavepic);
    setMinimumSize(16, 16);
}
