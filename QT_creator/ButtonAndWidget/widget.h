#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>//包含头文件 Qwiget窗口类

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget//继承类
{
    Q_OBJECT//宏 允许类中使用信号和槽的机制

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
