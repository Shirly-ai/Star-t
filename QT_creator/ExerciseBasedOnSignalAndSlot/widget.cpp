#include "widget.h"
#include "ui_widget.h"

//Teacher类 Student类
//下课后 老师触发“饿了”信号 学生响应信号请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->te=new Teacher(this);//指定父亲 放在对象树上 不用管理释放
    //创建一个学生对象
    this->st=new Student(this);
    //老师饿了学生请客的连接
    connect(te,&Teacher::hungry,st,&Student::treat);
    //调用下课函数
    classIsOver();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::classIsOver()
{
    //下课函数 触发老师饿了的信号
    emit te->hungry();
}
