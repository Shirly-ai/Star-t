#include "mainwindow.h"
#include "chartprocess.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    resize(1000,600);
    button = new QPushButton("点我",this);
    // button->move(50,50);
    // button->resize(100,30);
    button->setGeometry(50,50,100,30);//位置和大小
    connect(button,&QPushButton::clicked,this,&MainWindow::onButtonClicked);

}

MainWindow::~MainWindow()
{
}

void MainWindow::setWidget(QWidget *newWidget){//窗口
    container=newWidget;
}
void MainWindow::setScroll(QScrollArea *newScroll){//滚动视图 可以鼠标滚轮滑动页面
    scrollArea=newScroll;//！！！
}
void MainWindow::setLayout(QVBoxLayout *newlayout){//布局
    layout=newlayout;
}
void MainWindow::onButtonClicked()
{
    container->setFixedSize(1000, 1000);
    container->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);//
    layout->setSizeConstraint(QLayout::SetFixedSize);//布局大小
    scrollArea->setWidget(container);//！！！滚动视图 可以鼠标滚轮滑动页面
    chart1=new ChartProcess(nullptr,"data.txt","Graph1");
    layout->addWidget(chart1->chartView);//series->chart(依靠chartview来display)->整个控件布局在layout布局上
    chart1->startThread();
    chart2=new ChartProcess(nullptr,"data1.txt","Graph2");
    layout->addWidget(chart2->chartView);
    chart2->startThread();
    chart3=new ChartProcess(nullptr,"data.txt","Graph3");
    layout->addWidget(chart3->chartView);
    chart3->startThread();
    chart4=new ChartProcess(nullptr,"data1.txt","Graph4");
    layout->addWidget(chart4->chartView);
    chart4->startThread();
    chart5=new ChartProcess(nullptr,"data.txt","Graph5");
    layout->addWidget(chart5->chartView);
    chart5->startThread();
    chart6=new ChartProcess(nullptr,"data.txt","Graph6");
    layout->addWidget(chart6->chartView);
    chart6->startThread();
    chart7=new ChartProcess(nullptr,"data1.txt","Graph7");
    layout->addWidget(chart7->chartView);
    chart7->startThread();
    chart8=new ChartProcess(nullptr,"data.txt","Graph8");
    layout->addWidget(chart8->chartView);
    chart8->startThread();
    scrollArea->setWidgetResizable(true);//！！！
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);//垂直
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//水平
    setCentralWidget(scrollArea);
}
