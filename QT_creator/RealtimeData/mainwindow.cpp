#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    timer->start(1000);//时间间隔为1s
    connect(timer,SIGNAL(timeout()),this,SLOT(Time_Update()));//计数器超时时更新
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Time_Update(void)
{
    QTime t;
    t=QTime::currentTime();
    //QTime(h,m,s)//Constructs a time with hour h, minute m, seconds s.
    //secsTo(t) t-此刻时间的秒数
    //产生随机数种子，指从零点到此刻时间经历的秒数
    srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    //rand得到随机数
    cnt=rand()%50;//虚构数据
    //Show_Plot(ui->widget);//？
    Show_Plot(customPlot);
}

void MainWindow::Show_Plot(QCustomPlot *customPlot)
{
    QVector<double> key(10);//？
    QVector<double> value(10);
    QVector<double> value2(10);
    double now = QDateTime::currentDateTime();//无法将时间转换成double
    //double now= QTime::currentTime();
    //now是此刻时间
    srand(8);

    //num[10]为缓冲区
    for(int i=0; i<9; i++)
    {
        num[i] = num[i+1]; // 长江后浪推前浪：前消后加
    }
    num[9] = cnt;  // 更新的值加在后面
    for(int i=0;i<10;i++)
    {
        key[i]   = now+i;
        value[i]  = num[i];
        value2[i]  = num[i]+5;
    }
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::red));
    customPlot->graph(0)->setData(key,value);

    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(Qt::black));
    customPlot->graph(1)->setData(key,value2);


    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);//定义时间变量
    dateTicker->setDateTimeFormat("hh:mm:ss"); // yyyy-MM-dd hh:mm:ss
    customPlot->xAxis->setTicker(dateTicker);
    //customPlot->xAxis->setTickLabelRotation(30); // 设置30斜着显示

    customPlot->xAxis->setLabel("Time(s)");
    customPlot->yAxis->setLabel("uA");

    customPlot->xAxis->setRange(now, now+20);
    customPlot->yAxis->setRange(0,80);
    customPlot->replot();//更新画布
}
