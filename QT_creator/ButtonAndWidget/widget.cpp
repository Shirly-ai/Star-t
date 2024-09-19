#include "widget.h"
#include "./ui_widget.h"
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个按钮
    QPushButton *btn=new QPushButton;
    //btn->show();//show()默认以顶层窗口弹出窗口控件（重新开了一个窗口弹出）
    //让btn对象依附在Widget窗口中
    btn->setParent(this);
    //显示文本
    btn->setText("第一个按钮");

    //创建第二个按钮 按照控件大小建立窗口
    QPushButton *btn2=new QPushButton("第二个按钮",this);

    //移动btn2按钮
    btn2->move(100,100);

    //按钮重置大小
    btn2->resize(100,50);

    //重置窗口大小
    resize(600,400);

    //设置固定窗口大小 用户无法自己拖拽放缩
    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("第一个窗口");

    //点击第二个按钮 关闭窗口
    //参数1 信号的发送者 参数2 发送的信号（函数的地址） 参数3 信号接收者 参数4 信号处理
    //信号:signal 槽函数：slot(s)
    connect(btn2,&QPushButton::clicked,this,&QWidget::close);//
}

Widget::~Widget()
{
    delete ui;
}
