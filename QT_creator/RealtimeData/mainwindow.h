#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class QCustomPlot;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QCustomPlot *customPlot;

    void Show_Plot(QCustomPlot *customPlot);//自写

public slots:
    void Time_Update(void);//自写

private:
    Ui::MainWindow *ui;

    double num[10];  // 缓冲区
    int cnt;  // 写入的值
};

#endif // MAINWINDOW_H

