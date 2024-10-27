#include "framelesswindow.h"
#include "ui_framelesswindow.h"
#include "datasave.h"
#include <QStandardPaths>
#include <QDir>
framelessWindow::framelessWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::framelessWindow)
{
    tray= new QSystemTrayIcon(this);//��ʼ�����̶���tray
    tray->setIcon(QIcon(":/StreamlineEmojisTomato.svg"));//�趨����ͼ�꣬���������Զ����pngͼƬ·��
    tray->setToolTip("TomatoBell"); //��ʾ����
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
    if(event->button()==Qt::LeftButton) //�������������
    {
        isPressed=true;
        curPos=event->pos();    //��¼��ǰ�ĵ������
    }
}

void framelessWindow::mouseMoveEvent(QMouseEvent*event)
{
    if(isPressed) //�������������
    {
        this->move(event->pos()-curPos+this->pos());    //�����ƶ�
    }
}

//����ͷ�
void framelessWindow::mouseReleaseEvent(QMouseEvent*event)
{
    isPressed=false;
}
void framelessWindow::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);// ����һ��QPainter����ָ�������豸Ϊthis������ǰ����
    painter.setRenderHint(QPainter::Antialiasing);  // ���û���ѡ��Ϊ����ݣ�ʹ���Ƶ�ͼ�α�Ե����ƽ��
    painter.setBrush(QBrush(QColor(240,240,240,200))); //���û�ˢ��ɫ,����Ϊ��ɫ
                      painter.setPen(Qt::transparent);// ���û�����ɫΪ͸�����������Ʊ߿���
        QRect rect = this->rect();// ��ȡ��ǰ���ڵľ�������
        painter.drawRoundedRect(rect, 5, 5);  // ����һ������Բ�ǵľ��δ��ڣ�Բ�ǰ뾶Ϊ15px������Ѵ������ó������Σ�Բ�ǰ뾶��󣬾ͻ���һ��Բ��

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
    //�ر�app
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
