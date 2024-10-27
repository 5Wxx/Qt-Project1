#include "contentwidget.h"
#include "framelesswindow.h"
#include "datasave.h"
#include <QApplication>
#include <QStandardPaths>
#include <QTextCodec>
#include <QScreen>
int main(int argc, char *argv[])
{

    QApplication::setQuitOnLastWindowClosed(false);
    QString AppConfigPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+ "/TomatoBell/TomatoBell.txt";
    DataSave dataManager1(AppConfigPath);
    QMap<QString, QString> dataa = dataManager1.readData();
    if (!dataa.contains("locationX")) {
        dataa["locationX"] = "100";
        dataa["locationY"] = "100";
    }
    QApplication a(argc, argv);
    framelessWindow w;
    QScreen *screen = QApplication::primaryScreen();

    // 获取当前屏幕分辨率
    QSize screenSize = screen->size();
    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();
    int width,height;
    width=430;
    height=150;
    QString currentDirPath = QCoreApplication::applicationDirPath();
    QFile file(currentDirPath + QDir::separator() + "tomatoBellSize.txt");
    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream out(&file);
            out << "430 150";
            file.close();
        }
    }else{
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            QString line = in.readLine();
            file.close();
            QStringList numbers = line.split(' ');
            width = numbers.at(0).toInt();
            height = numbers.at(1).toInt();
        };
    };

    if (screenWidth == 2560) {
        w.resize(width, height);
    }else{
        int dpiw = width*screenWidth/2560;
        int dpih = height*screenWidth/2560;
        w.resize(dpiw,dpih);
    }


    w.setWindowFlags(w.windowFlags() | Qt::WindowStaysOnTopHint | Qt::Tool);
    a.setWindowIcon(QIcon(":/StreamlineEmojisTomato.svg"));
    contentWidget mainContent;
    w.addMain(&mainContent);
    if (dataa["locationX"].toInt()<screenWidth && dataa["locationY"].toInt()<screenHeight){
        w.move(dataa["locationX"].toInt(),dataa["locationY"].toInt());
    }else{
        w.move(100,100);
    }

    w.show();
    return a.exec();
}

