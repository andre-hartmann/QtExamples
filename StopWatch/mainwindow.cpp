#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_stopWatchTimer(new StopWatchTimer)
{
    m_ui->setupUi(this);

    connect(m_stopWatchTimer, &StopWatchTimer::elapsedTime,
            this, [this](const QString &text) {
        m_ui->timer_label->setText(text);
    });
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::on_startButton_clicked()
{
    if (m_stopWatchTimer->isActive()) {
        m_stopWatchTimer->stop();
        m_ui->startButton->setText("Start");
    } else {
        m_stopWatchTimer->start();
        m_ui->startButton->setText("Stop");
    }
}

void MainWindow::on_resetButton_clicked()
{
    m_stopWatchTimer->reset();
}
