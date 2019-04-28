#pragma once

#include "stopwatchtimer.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_resetButton_clicked();

private:
    Ui::MainWindow *m_ui = nullptr;
    StopWatchTimer *m_stopWatchTimer = nullptr;
};
