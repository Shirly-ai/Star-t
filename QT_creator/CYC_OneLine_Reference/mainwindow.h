// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "datareader.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QVector>
#include <QPointF>
#include <QFile>
#include <QTextStream>
#include <QGraphicsLineItem>
#include <QRegularExpression>
#include<QString>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QTimer>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr,const QString &filePath="data.txt");
    ~MainWindow();

private slots:
    void onButtonClicked();//

private:
    //
    QPushButton *button;
    QLineSeries *series;//线程
    QValueAxis *axisX;
    QValueAxis *axisY;
    QChart *chart;
    QChartView *chartView;
    DataReader reader;
    QTimer timer;
    void drawLineChart();
    void timeoutHandler();
};

#endif // MAINWINDOW_H
