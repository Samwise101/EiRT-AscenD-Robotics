#include <string>
#include <iostream>
#include <cmath>
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rclcpp::init(argc, argv);  // ✅ Must call this before using any rclcpp nodes
    
    MainWindow w;
    w.show();
    int ret = a.exec();

    rclcpp::shutdown();
    return ret;
}