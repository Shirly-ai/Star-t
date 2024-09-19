#ifndef MYCHARTVIEW_H
#define MYCHARTVIEW_H

#include <QWidget>
#include <QPoint>
#include <QChartView>

class Mychartview : public QChartView
{
    Q_OBJECT
public:
    explicit Mychartview(QWidget *parent = nullptr);

signals:
    void mouseMovePoint(QPoint point);//用来给MainWindow发送信号

protected:
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件
};

#endif // MYCHARTVIEW_H
