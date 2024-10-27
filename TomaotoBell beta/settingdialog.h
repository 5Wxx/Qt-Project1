

#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include "datasave.h"
#include <QStandardPaths>
#include <QDir>
#include <QCloseEvent>
#include <QMessageBox>
#include <QMediaMetaData>
namespace Ui {
class settingdialog;
}

class settingdialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingdialog(QWidget *parent = nullptr);
    void musicctrl();
    void bmusicctrl();
    void initializeBackgroundMusic();
    void initialBMusicComboBox(QMediaPlaylist *bmusiclist);
    void initializeMusic();
    void setTime(int Workt,int Sleept);
    void updateConfigData(const QString& key, const QString& value);
    QString AppConfigPath;
    QString parentPath;
    DataSave *dataManager;
    QMap<QString, QString> configdata;
    ~settingdialog();

private:
    int bmusicVolume;
    int musicVolume;
    Ui::settingdialog *ui;
    QMediaPlaylist *musicList;
    QMediaPlayer *soundPlayer;
    QMediaPlaylist *musicList2;
    QMediaPlayer *soundPlayer2;

protected:
    void closeEvent(QCloseEvent *event) override;
signals:
    void resetTime();
};

#endif // SETTINGDIALOG_H
