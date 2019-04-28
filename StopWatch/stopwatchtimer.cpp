#include "stopwatchtimer.h"

#include <QTime>

StopWatchTimer::StopWatchTimer(QObject *parent) :
    QObject(parent)
{
    connect(&m_refreshTimer, &QTimer::timeout,
            this, &StopWatchTimer::emitElapsedTime);
}

void StopWatchTimer::start()
{
    m_currentMillis.restart();
    m_refreshTimer.start();
}

void StopWatchTimer::stop()
{
    m_lastRunMillis += m_currentMillis.elapsed();
    m_refreshTimer.stop();
}

void StopWatchTimer::reset()
{
    m_currentMillis.restart();
    m_lastRunMillis = 0;
    emitElapsedTime();
}

bool StopWatchTimer::isActive()
{
    return m_refreshTimer.isActive();
}

void StopWatchTimer::emitElapsedTime()
{
    qint64 elapsed = m_lastRunMillis + m_currentMillis.elapsed();
    const QTime t = QTime::fromMSecsSinceStartOfDay(int(elapsed));
    emit elapsedTime(t.toString("mm:ss:zzz"));
}
