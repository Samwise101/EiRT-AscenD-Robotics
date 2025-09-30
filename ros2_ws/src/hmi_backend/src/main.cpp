// backend_heartbeat.cpp (rclcpp)
#include <iostream>
#include "app.h"

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);

  App app{};

  app.appRun();

  rclcpp::shutdown();
  return 0;
}
