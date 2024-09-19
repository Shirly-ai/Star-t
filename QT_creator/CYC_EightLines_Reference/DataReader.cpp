#include "datareader.h"
#include <QDebug>
#include <QThread>

DataReader::DataReader(QObject *parent,const QString &filePath) : QObject(parent),file(filePath)
{
    file.open(QIODevice::ReadOnly);//打开文件
    qRegisterMetaType<QVector<qreal> >("QVector<qreal>");//注册类型
    QTextStream in(&file);//文件流“给文件的新名字”
    if(!file.isOpen()){
        qDebug()<<"The file is not open.";
    }
    file.seek(0);//指针对准的位置
    QString line;
    line=in.readLine();//读一行返回str 读完指针移至下一行
    //分割 返回包含各分割元素的list（返回的list会跳过空格）
    numberStrs1 = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    line = in.readLine();
    numberStrs2 = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    //如何触发自定义信号？
    connect(this, &DataReader::StartInit, this, &DataReader::slotStartInit);
}
DataReader::~DataReader(){
    file.close();//关闭文件
}
void DataReader::slotStartInit()//为什么要写信号和槽 不直接写到上面去
{
    timer=new QTimer();
    connect(timer, &QTimer::timeout, this, &DataReader::processData);//？
    timer->start(33);
}

qreal DataReader::getValueX(){
    qreal data;
    if (numberStrs1.size()<=LinePosition){
        return -1;
    }
    bool ok;
    //at()返回位置为LinePosition的项
    //将分割出来的str转化为double值 ok指向的内容为1才可以转化
    data=numberStrs1.at(LinePosition).toDouble(&ok);
    LinePosition++;
    if (ok) {
        return data;
    } else {
        qDebug() << "Error";
        return -1;
    }
}
qreal DataReader::getValueY(){
    qreal data;
    bool ok;
    if (numberStrs2.size()<=LinePosition){
        return -1;
    }
    data=numberStrs2.at(LinePosition).toDouble(&ok);
    if (ok) {
        return data;
    } else {
        qDebug() << "Error";
        return -1;
    }
}
void DataReader::processData()
{
    //相当于先初始化数组为0
    data.clear();//data：series中的QList
    qreal x,y;
    x=getValueX();
    y=getValueY();
    if(x==STOPVALUE||y==STOPVALUE){
        timer->stop();
    }
    data.append(x);//添进去才有data[0]data[1]data[2]
    data.append(y);//
    data.append(LinePosition);//
    emit sendSeries(data);//把含这三个数值的数组（的信号）发射出去
}
