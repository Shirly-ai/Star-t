#include "widget.h"

#include <QApplication>//一个应用程序类的头文件

int main(int argc, char *argv[])//argc:命令行变量的数量，argv:命令行变量的数组
{
    QApplication a(argc, argv);//a:应用程序对象（有且仅有一个）
    Widget w;//窗口对象 Qwidget实例化出了Widget
    w.show();//窗口对象默认不显示，调用show()显示窗口
    return a.exec();//让应用程序对象进入消息循环，一直在捕捉用户消息，使窗口不会一闪而过；代码阻塞到这行
}
