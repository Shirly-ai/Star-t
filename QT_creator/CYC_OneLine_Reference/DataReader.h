#ifndef DATAREADER_H
#define DATAREADER_H
#define POINTSNUMBER 200
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QRegularExpression>
class DataReader{
public:
    DataReader(const QString &filePath);
    ~DataReader();
    qreal getValueX();
    qreal getValueY();
    int getPosition();
private:
    QFile file;
    int LinePosition=0;
};

#endif // DATAREADER_H
