#include "framelesswindow.h"
#include "ui_framelesswindow.h"
#include "datasave.h"
#include <QStandardPaths>
#include <QDir>
framelessWindow::framelessWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::framelessWindow)
{
    tray= new QSystemTrayIcon(this);//初始化托盘对象tray
    tray->setIcon(QIcon(":/StreamlineEmojisTomato.svg"));//设定托盘图标，引号内是自定义的png图片路径
    tray->setToolTip("TomatoBell"); //提示文字
    tray->show();

    quitAction = new QAction("exit", this);

    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    trayMenu = new QMenu(this);
    trayMenu->addAction(quitAction);
    trayMenu->setStyleSheet(QString::fromUtf8("QMenu::item {\n"
                                              "                                border:none;\n"
                                              "                                    background-color: transparent;\n"
                                              "                                padding:3px 45px 3px 15px;\n"
                                              "                                margin:2px 0px;\n"
                                              "                            }\n"
                                              "                            QMenu::icon {\n"
                                              "                                padding:0px 0px 0px 15px;\n"
                                              "                            }\n"
                                              "                            QMenu::item:selected { background-color: rgb(231,231,231); }"));
    tray->setContextMenu(trayMenu);

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint|this->windowFlags());
    ui->setupUi(this);
    ui->closebutton->initializePixmaps(":/IconamoonCloseThin.svg",":/IconamoonCloseThin (1).svg",":/IconamoonCloseThin (2).svg");
    connect(ui->closebutton,&eventColorButton::clicked,[this](){
        this->closeapp();
    });
}

void framelessWindow::addMain(contentWidget *mainWidget)
{
    ui->datalo->addWidget(mainWidget);
}

void framelessWindow::mousePressEvent(QMouseEvent*event)
{
    if(event->button()==Qt::LeftButton) //如果鼠标左键按下
    {
        isPressed=true;
        curPos=event->pos();    //记录当前的点击坐标
    }
}

void framelessWindow::mouseMoveEvent(QMouseEvent*event)
{
    if(isPressed) //如果鼠标左键按下
    {
        this->move(event->pos()-curPos+this->pos());    //窗口移动
    }
}

//鼠标释放
void framelessWindow::mouseReleaseEvent(QMouseEvent*event)
{
    isPressed=false;
}
void framelessWindow::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);// 创建一个QPainter对象并指定绘制设备为this，即当前窗口
    painter.setRenderHint(QPainter::Antialiasing);  // 设置绘制选项为反锯齿，使绘制的图形边缘更加平滑
    painter.setBrush(QBrush(QColor(240,240,240,200))); //设置画刷颜色,这里为白色
                      painter.setPen(Qt::transparent);// 设置画笔颜色为透明，即不绘制边框线
        QRect rect = this->rect();// 获取当前窗口的矩形区域
        painter.drawRoundedRect(rect, 5, 5);  // 绘制一个带有圆角的矩形窗口，圆角半径为15px，如果把窗口设置成正方形，圆角半径设大，就会变成一个圆了

}

void framelessWindow::saveCurrentPosition()
{
    QString AppConfigPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+ "/TomatoBell.txt";
    QDir dir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)); if (!dir.exists()) { if (!dir.mkpath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation))) { qDebug() << "failed to create directory!";}};
    DataSave dataManager(AppConfigPath);
    QMap<QString, QString> data = dataManager.readData();
    QPoint currentPos = this->pos();
    data["locationX"] = QString::number(currentPos.x());
    data["locationY"] = QString::number(currentPos.y());
    if (!dataManager.writeData(data)) {
        qDebug() << "unable to save pos!";
    } else {
        qDebug() << "succss to save pos!";
    }
}

void framelessWindow::closeapp()
{
    //关闭app
    saveCurrentPosition();
    qApp->quit();
}
framelessWindow::~framelessWindow()
{
    delete ui;
}

void framelessWindow::closeEvent(QCloseEvent *event)
{
    saveCurrentPosition();
}
