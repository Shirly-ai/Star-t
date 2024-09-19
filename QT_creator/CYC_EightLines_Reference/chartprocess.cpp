#include "chartprocess.h"
ChartProcess::ChartProcess(QObject *parent,const QString filePath,const QString newname):QObject(parent){
    Path=filePath;
    chart = new QChart();
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    widget=new QWidget;
    chartView=new QChartView();
    chartView->setChart(chart);//图表视图拥有新图表 将chart与chartview关联
    chartView->setFixedSize(1000,300);
    //感觉可以不用（chart）
    series = new QSplineSeries(chart);//画在chart上 将chart与series关联
    thread = new QThread();
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);
    chart->setTheme(QChart::ChartThemeLight);
    chart->legend()->setVisible(false);//设置图例为不可见
    chart->setTitle(newname);
    axisX->setRange(0, POINTSNUMBER);//设置坐标轴范围
    axisX->setTickCount(POINTSNUMBER/10);
    axisX->setLabelFormat("%.0f");
    axisY->setRange(-1, 4);
    axisY->setTickCount(1.0);
    //QPainter::Antialiasing告诉绘图引擎应该在可能的情况下进行边的反锯齿绘制
    //打开反走样属性
    chartView->setRenderHint(QPainter::Antialiasing);
    chart->addSeries(series);//添加系列到chart上
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    dataReader = new DataReader(nullptr,Path);
    //在datareader.cpp中有显性发射信号
    connect(dataReader, &DataReader::sendSeries, this, &ChartProcess::slotUpdate);
    dataReader->moveToThread(thread);//将事件与线程相关联

}
ChartProcess::~ChartProcess(){
    thread->quit();//图表处理结束 线程结束
}
void ChartProcess::startThread(){
    thread->start();
    dataReader->StartInit();//自定义信号 且没有emit触发？？
}
void ChartProcess::slotUpdate(QVector<qreal> data)
{
    qreal x,y;
    int Position;
    x=data[0];//
    y=data[1];//
    Position=data[2];//data是包含x y Position三个数值的数组
    if(x==STOPVALUE || y==STOPVALUE){
        thread->quit();
    }
    else{
        series->append(x,y);
        if (Position>POINTSNUMBER){
            axisX->setRange(Position-POINTSNUMBER,Position);
            axisX->setLabelFormat("%.0f");
            axisX->setTickCount(POINTSNUMBER/10);
        }
    }
}

