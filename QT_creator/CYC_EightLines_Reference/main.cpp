#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    QScrollArea *scrollArea = new QScrollArea();
    QWidget *widget = new QWidget(scrollArea);
    mainWindow.setWidget(widget);
    mainWindow.setScroll(scrollArea);
    QVBoxLayout *layout = new QVBoxLayout(widget);
    mainWindow.setLayout(layout);
    mainWindow.show();
    return app.exec();
}
