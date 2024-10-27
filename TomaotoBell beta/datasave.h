#ifndef DATASAVE_H
#define DATASAVE_H

#include <QString>
#include <QMap>
#include <QFile>
#include <QTextStream>

class DataSave
{
public:
    DataSave(const QString &filePath);
    QMap<QString, QString> readData();
    bool writeData(const QMap<QString, QString> &data);

private:
    QString filePath;
};

#endif // DATASAVE_H
