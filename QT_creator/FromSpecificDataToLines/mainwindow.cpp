#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCustomPlot* customPlot = new QCustomPlot;//创建图表绘制的对象
    setCentralWidget(customPlot);//将绘制的图表放在中央

    setupQuadraticDemo(customPlot);//创建二次曲线的图表示例
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupQuadraticDemo(QCustomPlot *customPlot)
{
    QVector<double> x(101), y(101);//创建QVector容器存放xy
    for (int i = 0; i < 101; ++i) {
        x[i] = i / 50.0 - 1; // -1 到 1
        y[i] = x[i] * x[i];
    }

    customPlot->addGraph(); // 添加一个曲线图QGraph
    customPlot->graph(0)->setData(x, y); // 为曲线图添加数据
    customPlot->graph(0)->setName(QString::fromLocal8Bit("customplot_quadratic_demo")); // 设置曲线图的名字
    customPlot->xAxis->setLabel("x"); // 设置x和y轴的标签
    customPlot->yAxis->setLabel("y");
    customPlot->xAxis->setRange(-1, 1); // 设置x轴的范围为(-1,1)
    customPlot->yAxis->setRange(0, 1);
    //customPlot->xAxis2->setRange(-2,-1);
    customPlot->legend->setVisible(true); // 显示图例
}
