#include "DataSave.h"
#include <QDebug>


DataSave::DataSave(const QString &filePath) : filePath(filePath) {}

QMap<QString, QString> DataSave::readData() {
    QMap<QString, QString> data;
    QFile file(filePath);
    qDebug()<<filePath;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "failed to get data.";
        return data;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("=");
        if (parts.size() == 2) {
            data[parts[0].trimmed()] = parts[1].trimmed();
        }
    }

    file.close();
    return data;
}

bool DataSave::writeData(const QMap<QString, QString> &data) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "failed to write data.";
        return false;
    }

    QTextStream out(&file);
    for (auto it = data.begin(); it != data.end(); ++it) {
        out << it.key() << "=" << it.value() << "\n";
    }

    file.close();
    return true;
}
