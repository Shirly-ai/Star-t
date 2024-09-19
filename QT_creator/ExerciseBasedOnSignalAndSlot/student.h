#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    void treat();//public slots
signals:
//早期版本QT 必须写到public slots 高级版本可以写到public或者全局下
//返回值是void 需要声明也需要实现
//可以有参数 可以重载
};

#endif // STUDENT_H
 
