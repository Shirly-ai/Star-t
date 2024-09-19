#include "mychartview.h"

Mychartview::Mychartview(QWidget *parent)
    : QChartView{parent}
{}
void Mychartview::mouseMoveEvent(QMouseEvent *event){
    QPoint point=event->pos();
    emit mouseMovePoint(point);
    QChartView::mouseMoveEvent(event);
}
