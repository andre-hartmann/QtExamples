#pragma once

#include <QElapsedTimer>
#include <QTimer>

class StopWatchTimer : public QObject
{
    Q_OBJECT
public:
    StopWatchTimer(QObject *parent = nullptr);

    void start();
    void stop();
    void reset();

    bool isActive();

private slots:
    void emitElapsedTime();

signals:
    void elapsedTime(const QString &time);

private:
    qint64 m_lastRunMillis = 0;
    QElapsedTimer m_currentMillis;
    QTimer m_refreshTimer;
};
