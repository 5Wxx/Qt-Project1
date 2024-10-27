#include "settingdialog.h"
#include "ui_settingdialog.h"
#include "datasave.h"
#include <windows.h>
#include <QStandardPaths>
#include <QDir>
#include <QFileInfo>
#include <QListView>
#include <QComboBox>
#include <QDesktopServices>



settingdialog::settingdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::settingdialog)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QString appPath = QCoreApplication::applicationFilePath();
    QFileInfo fileInfo(appPath);
    parentPath = fileInfo.dir().absolutePath();
    AppConfigPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+ "/TomatoBell.txt";
    QDir dir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)); if (!dir.exists()) { if (!dir.mkpath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation))) { qDebug() << "failed to create directory!";}};
    dataManager=new DataSave(AppConfigPath);
    configdata = dataManager->readData();
    ui->setupUi(this);

    ui->musicbutton->setIconSize(QSize(24,24));
    ui->bmusicbutton->setIcon(QIcon(":/MaterialSymbolsCheckCircleRounded.svg"));
    ui->bmusicbutton->setIconSize(QSize(24,24));
    ui->filebutton->setIconSize(QSize(24,24));
    ui->filebutton->setIcon(QIcon(":/BiFolder2.svg"));
    ui->filebutton->setIconSize(QSize(24,24));
    ui->filebutton2->setIcon(QIcon(":/BiFolder2.svg"));
    ui->filebutton2->setIconSize(QSize(24,24));
    ui->worktBox->setValue(configdata["workt"].toInt());
    ui->sleeptBox->setValue(configdata["sleept"].toInt());

    connect(ui->musicbutton,&QPushButton::clicked,[this](){
        musicctrl();
    });
    connect(ui->bmusicbutton,&QPushButton::clicked,[this](){
        bmusicctrl();
    });
    connect(ui->filebutton,&QPushButton::clicked,[this](){
        QString musicPath = QDir(parentPath).filePath("music");
        QDesktopServices::openUrl(QUrl::fromLocalFile(musicPath));
    });
    connect(ui->filebutton2,&QPushButton::clicked,[this](){
        QString bmusicPath = QDir(parentPath).filePath("bmusic");
        QDesktopServices::openUrl(QUrl::fromLocalFile(bmusicPath));
    });
}

void settingdialog::musicctrl()
{
    if(soundPlayer2->state() == QMediaPlayer::PlayingState){
        soundPlayer2->pause();
        ui->musicbutton->setIcon(QIcon(":/MaterialSymbolsCheckCircleOutlineRounded.svg"));
        configdata["music"] = "0";
    }else{
        soundPlayer2->play();
        ui->musicbutton->setIcon(QIcon(":/MaterialSymbolsCheckCircleRounded.svg"));
        configdata["music"] = "1";
    }
    if (!dataManager->writeData(configdata)) {
        qDebug() << "unable to save musicdata!";
    } else {
        qDebug() << "succss to save musicdata!";
    }
}
void settingdialog::bmusicctrl()
{
    if(soundPlayer->state() == QMediaPlayer::PlayingState){
        soundPlayer->pause();
        ui->bmusicbutton->setIcon(QIcon(":/MaterialSymbolsCheckCircleOutlineRounded.svg"));
        configdata["bmusic"] = "0";
    }else{
        soundPlayer->play();
        ui->bmusicbutton->setIcon(QIcon(":/MaterialSymbolsCheckCircleRounded.svg"));
        configdata["bmusic"] = "1";
    }
    if (!dataManager->writeData(configdata)) {
        qDebug() << "unable to save musicdata!";
    } else {
        qDebug() << "succss to save musicdata!";
    }
}
void settingdialog::initializeBackgroundMusic()
{
    if (!configdata.contains("bmusic")) {
        configdata["bmusic"] = "0";
        configdata["music"] = "0";
        configdata["bmusicVolume"]="30";
        configdata["musicVolume"]="20";
        configdata["workt"]="25";
        configdata["sleept"]="5";
    }
    //������ʼ��
    bmusicVolume=configdata["bmusicVolume"].toInt();
    musicVolume=configdata["musicVolume"].toInt();
    ui->bmusicSlider->setValue(bmusicVolume);
    ui->musicSlider->setValue(musicVolume);
    connect(ui->bmusicSlider, &QSlider::valueChanged,[=](int value){
        soundPlayer->setVolume(value);
        configdata["bmusicVolume"]=QString::number(value);
        dataManager->writeData(configdata);
    });
    connect(ui->musicSlider, &QSlider::valueChanged,[=](int value){
        soundPlayer2->setVolume(value);
        configdata["musicVolume"]=QString::number(value);
        dataManager->writeData(configdata);
    });
    // ���������б�
    musicList = new QMediaPlaylist(this);

    // ��������ļ����б�ȷ��·����ȷ
    initialBMusicComboBox(musicList);
    // musicList->addMedia(QUrl("qrc:/music/rain.mp3"))

    // �������ֲ�����
    soundPlayer = new QMediaPlayer(this);

    // ���������б�
    soundPlayer->setPlaylist(musicList);
    musicList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    if (configdata.contains("bmusicindex")){
        musicList->setCurrentIndex(configdata["bmusicindex"].toInt());
    }
    soundPlayer->setVolume(bmusicVolume);
    if (configdata["bmusic"]=="1"){
        soundPlayer->play();
        ui->bmusicbutton->setIcon(QIcon(":/MaterialSymbolsCheckCircleRounded.svg"));
    }else{
        ui->bmusicbutton->setIcon(QIcon(":/MaterialSymbolsCheckCircleOutlineRounded.svg"));
    }

    if (!dataManager->writeData(configdata)) {
        qDebug() << "unable to save musicdata!";
    } else {
        qDebug() << "succss to save musicdata!";
    }
}

void settingdialog::initialBMusicComboBox(QMediaPlaylist *bmusiclist)
{
    // qDebug() << "Current executable path:" << parentPath;
    QString bmusicPath = QDir(parentPath).filePath("bmusic");
    QDir bmusicDir(bmusicPath);
    QFileInfoList fileInfoList = bmusicDir.entryInfoList(QStringList() << "*.mp3", QDir::Files);
    foreach (const QFileInfo &fileInfo , fileInfoList) {
        ui->bmusicBox->addItem(fileInfo.fileName());
    };

    foreach (const QFileInfo &fileInfo, fileInfoList) {
        QUrl mediaUrl = QUrl::fromLocalFile(fileInfo.filePath());
        musicList->addMedia(mediaUrl);
    };
    if (configdata.contains("bmusicindex")){
        ui->bmusicBox->setCurrentIndex(configdata["bmusicindex"].toInt());
    }
    connect(ui->bmusicBox,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int musicindex){
        musicList->setCurrentIndex(musicindex);
        updateConfigData("bmusicindex",QString::number(musicindex));
    });
}

void settingdialog::initializeMusic()
{
    // ���������б�
    musicList2 = new QMediaPlaylist(this);



    // ��������ļ����б�ȷ��·����ȷ
    QString musicPath = QDir(parentPath).filePath("music");
    QDir musicDir(musicPath);
    QFileInfoList fileInfoList = musicDir.entryInfoList(QStringList() << "*.mp3"<< "*.wav", QDir::Files);
    ui->songNumLabel->setText(QString::number(fileInfoList.length())+u8"��");
    foreach (const QFileInfo &fileInfo, fileInfoList) {
        QUrl mediaUrl = QUrl::fromLocalFile(fileInfo.filePath());
        musicList2->addMedia(mediaUrl);
    };


    // �������ֲ�����
    soundPlayer2 = new QMediaPlayer(this);
    // ���������б�
    soundPlayer2->setPlaylist(musicList2);
    // ���ò���ģʽΪѭ������
    musicList2->setPlaybackMode(QMediaPlaylist::Random);
    soundPlayer2->setVolume(musicVolume);

    // ��������
    if (configdata["music"]=="1"){
        soundPlayer2->play();
        ui->musicbutton->setIcon(QIcon(":/MaterialSymbolsCheckCircleRounded.svg"));
    }else{
        ui->musicbutton->setIcon(QIcon(":/MaterialSymbolsCheckCircleOutlineRounded.svg"));
    }
}

void settingdialog::setTime(int Workt,int Sleept)
{
    updateConfigData("workt",QString::number(Workt));
    updateConfigData("sleept",QString::number(Sleept));
    emit resetTime();
}

void settingdialog::updateConfigData(const QString &key, const QString &value)
{
    configdata[key] = value;
    dataManager->writeData(configdata);
}




void settingdialog::closeEvent(QCloseEvent *event){
    if (ui->sleeptBox->value()!=configdata["sleept"].toInt()||ui->worktBox->value()!=configdata["workt"].toInt()){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Tip");
        msgBox.setText(u8"   �����飬���޸���ʱ�䣬  \n   ȷ��ҪӦ����  ");
        msgBox.setWindowFlags(windowFlags()|Qt::WindowStaysOnTopHint);
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);

        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Yes:
            setTime(ui->worktBox->value(), ui->sleeptBox->value());
            event->accept(); // ���ܹر��¼�
            this->hide();
        default:
            ui->sleeptBox->setValue(configdata["sleept"].toInt());
            ui->worktBox->setValue(configdata["workt"].toInt());
            event->ignore(); // ���Թر��¼������رմ���
        }
    }else {
        event->accept(); // ���û���޸�ʱ�䣬ֱ�ӽ��ܹر��¼�
    };
}

settingdialog::~settingdialog()
{
    delete musicList;
    delete musicList2;
    delete soundPlayer;
    delete soundPlayer2;
    delete dataManager;
    delete ui;
}
