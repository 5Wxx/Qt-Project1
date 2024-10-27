#ifndef FRAMELESSWINDOW_H
#define FRAMELESSWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QPainter>
#include <qt_windows.h>
#include <Windowsx.h>
#include "contentwidget.h"
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
namespace Ui {
class framelessWindow;
}

class framelessWindow : public QMainWindow
{
    Q_OBJECT

public:


    explicit framelessWindow(QWidget *parent = nullptr);
    void addMain(contentWidget *mainWidget);
    void mousePressEvent(QMouseEvent*event) override;
    void mouseMoveEvent(QMouseEvent*event) override;
    void mouseReleaseEvent(QMouseEvent*event) override;
    void paintEvent(QPaintEvent * event) override;
    void saveCurrentPosition();
    void closeapp();
    ~framelessWindow();

private:
    QMenu *trayMenu;//托盘菜单
    QSystemTrayIcon *tray;//托盘图标添加成员
    QAction *quitAction;
    bool isPressed;
    QPoint curPos;
    Ui::framelessWindow *ui;
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // FRAMELESSWINDOW_H
