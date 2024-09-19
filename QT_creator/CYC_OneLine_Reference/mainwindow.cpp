// mainwindow.cpp
#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent,const QString &filePath)
    : QMainWindow(parent),reader(filePath)
{
    resize(1000, 600);//重新定义窗口大小
    button = new QPushButton("点我~", this);//QPushButton(const QString &text, QWidget *parent = nullptr)
    button->setGeometry(50, 50, 100, 30);//设置控件位置and矩形大小
    //将计数器与绘图的开始连在一起了
    connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    chart = new QChart();//管理图表系列、图例and轴
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    chart->addAxis(axisX,Qt::AlignBottom);//位置：底部
    chart->addAxis(axisY,Qt::AlignLeft);
    axisX->setRange(0, POINTSNUMBER);//POINTSNUMBER=200
    axisX->setTickCount(POINTSNUMBER/10);//指定刻度线的数量
    axisY->setRange(-1, 4);
    axisY->setTickCount(1.0);//一并设置小数点
    axisX->setLabelFormat("%.0f");//坐标数据类型设置
    chart->setTheme(QChart::ChartThemeLight);//图表主题:背景主题：亮—暗
    series = new QSplineSeries();//平滑曲线
    chartView = new QChartView(chart);//display
    //将计数器的timeout与读点绘图连接
    connect(&timer, &QTimer::timeout, this, &MainWindow::timeoutHandler);
    //每个33ms传一个timeout的信号
    timer.setInterval(33);//设置计时间隔 读取数据的时间间隔
}
MainWindow::~MainWindow(){}
void MainWindow::onButtonClicked()
{
    QString filePath = "data.txt";
    DataReader reader(filePath);
    drawLineChart();//
    timer.start();//鼠标点击开始计时
}

void MainWindow::drawLineChart()
{
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    axisX->setLabelFormat("%.0f");
    axisX->setTickCount(POINTSNUMBER/10);
    chart->setTitle("MOVING LINE");
    chart->legend()->setVisible(false);//设置图例不可见 标注线格式的点叫图例
    chartView->setRenderHint(QPainter::Antialiasing);//？是否启用某提示
    setCentralWidget(chartView);
    //chart与chartview的关系与区别
    //QChartView: QChartView是一个可以显示图表的独立小部件。图表需要显示在该部件上。
    //QChart：QChart类管理图表系列、图例和轴的图形表示。各种类型图需要显示在图表上
}
void MainWindow::timeoutHandler(){
    qreal xData,yData;//double
    xData=reader.getValueX();
    yData=reader.getValueY();
    //数据读完了
    if (xData==-1 || yData==-1){
        timer.stop();
    }
    else{
        series->append(xData, yData);//将数据点画入图
        int index=reader.getPosition();
        if( index > POINTSNUMBER){
            axisX->setRange(index-POINTSNUMBER,index);
            axisX->setLabelFormat("%.0f");
            axisX->setTickCount(POINTSNUMBER/10);
        }
    }
}
