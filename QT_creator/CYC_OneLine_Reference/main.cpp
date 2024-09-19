//main.cpp
#include "mainwindow.h"
#include <QApplication>
#include <QIcon>//可伸缩图标

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString filePath="data.txt";//数据文档
    MainWindow mainWindow(nullptr,filePath);//overloaded
    mainWindow.show();
    return app.exec();
}
