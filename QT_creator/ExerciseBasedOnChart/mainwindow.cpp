#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValueAxis>
#include <QLineSeries>
#include <QPointF>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chart_init();

    connect(ui->graphicsView,SIGNAL(mouseMovePoint(QPoint)),this,SLOT(do_mousemoveevent(QPoint)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chart_init(){
    //第一步设置标题和坐标轴
    //设置标题
    chart_1=new QChart;
    chart_1->setTitle("y=sin(0.1x)");
    ui->graphicsView->setChart(chart_1);
    //设置x轴
    QValueAxis *axis_x =new QValueAxis;
    axis_x->setTitleText("值");
    axis_x->setRange(0,10);//设置值域
    chart_1->addAxis(axis_x,Qt::AlignBottom);//沿底边显示
    //设置y轴
    QValueAxis *axis_y =new QValueAxis;
    axis_y->setTitleText("值");
    axis_y->setRange(0,10);//设置值域
    chart_1->addAxis(axis_y,Qt::AlignLeft);//沿底边显示

    //第二步增加数据
    QLineSeries *line =new QLineSeries;
    line->setName("曲线");
    chart_1->addSeries(line);

    line->attachAxis(axis_x);//绑定x轴
    line->attachAxis(axis_y);//绑定y轴
}

void MainWindow::do_mousemoveevent(QPoint point){
    QPointF pt=chart_1->mapToValue(point);
    QString str=QString::asprintf("Chart x=%.1f,Y=%.2f",pt.x(),pt.y());
    ui->label->setText(str);
}
