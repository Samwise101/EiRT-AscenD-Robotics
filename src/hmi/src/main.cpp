#include <string>
#include <iostream>
#include <cmath>
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rclcpp::init(argc, argv);
    
    MainWindow w;
    w.show();
    int ret = a.exec();
    return ret;
}