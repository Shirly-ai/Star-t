#include "datareader.h"
DataReader::DataReader(const QString &filePath):file(filePath){
    file.open(QIODevice::ReadOnly);
}
DataReader::~DataReader(){
    file.close();
}


qreal DataReader::getValueX(){
    qreal data;
    QTextStream in(&file);
    if(!file.isOpen()){
        qDebug()<<"The file is not open.";
    }
    file.seek(0);//将当前访问位置设置为0
    QString line;
    bool ok;
    line=in.readLine();
    //出现“\\s+”分割字符串 跳过空字符串
    //QRegularExpression正则表达式类 \\s+代表所有空白字符
    QStringList numberStrs = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    if (numberStrs.size()<=LinePosition){
        return -1;
    }
    //at()返回位置为LinePosition的项
    //将分割出来的str转化为double值 ok指向的内容为1才可以转化
    data=numberStrs.at(LinePosition).toDouble(&ok);
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
    QTextStream in(&file);
    if(!file.isOpen()){
        qDebug()<<"The file is not open.";
    }
    file.seek(0);
    QString line;
    bool ok;
    in.readLine();
    line = in.readLine();
    QStringList numberStrs = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    if (numberStrs.size()<=LinePosition){
        return -1;
    }
    data=numberStrs.at(LinePosition).toDouble(&ok);
    if (ok) {
        return data;
    } else {
        qDebug() << "Error";
        return -1;
    }
}
int DataReader::getPosition(){
    return LinePosition;
}
