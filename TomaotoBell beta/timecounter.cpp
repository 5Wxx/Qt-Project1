#include "TimeCounter.h"

TimeCounter::TimeCounter(int seconds, QObject *parent)
    : QObject(parent), m_seconds(seconds), m_timer(new QTimer(this)) {
    connect(m_timer, &QTimer::timeout, this, &TimeCounter::onTimeout);
}

void TimeCounter::resetdata(int seconds)
{
    m_seconds = seconds;
}

void TimeCounter::start() {
    m_timer->start(1000);

}

void TimeCounter::stop()
{
    m_timer->stop();
}

void TimeCounter::onTimeout() {
    emit changeTimeLabel();
    if (--m_seconds == 0) {
        m_timer->stop();
        emit finished();
    }
}
