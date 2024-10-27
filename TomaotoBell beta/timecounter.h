#ifndef TIMECONTER_H
#define TIMECONTER_H

#include <QObject>
#include <QTimer>

class TimeCounter : public QObject {
    Q_OBJECT

public:
    explicit TimeCounter(int seconds, QObject *parent = nullptr);
    QString getRemainingTime() const {
        int m_minutes = m_seconds/60;
        int m_sec2 = m_seconds%60;
        QString formattedTime = QString("%1:%2")
        .arg(m_minutes, 2, 10, QChar('0'))
            .arg(m_sec2, 2, 10, QChar('0'));
        return formattedTime;
    };
    void resetdata(int seconds);
    void start();
    void stop();

private slots:
    void onTimeout();

signals:
    void changeTimeLabel(); //�ı�ʱ���ǩ
    void finished(); // ����ʱ�������ź�

private:
    QTimer *m_timer; // ��ʱ��
    int m_seconds; // ����ʱ����
};

#endif // TIMECONTER_H
