cmake_minimum_required(VERSION 3.5)
project(hmi)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)    # let CMake run uic on .ui files
set(CMAKE_AUTORCC ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(dronehive_interfaces REQUIRED)

# Qt dependencies
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui Charts Xml)

# UI + resources
set(UI_FILES
  ui/mainwindow.ui
  ui/new_box_pupup.ui
  ui/box_search_timeout_dialog.ui
  ui/update_system_dialog.ui
)
qt5_add_resources(QT_RESOURCES resources/resources.qrc)

# Sources and headers
set(SOURCES
  src/main.cpp
  src/mainwindow.cpp
  src/box.cpp
  src/drone.cpp
  src/new_box_dialog.cpp
  src/backend_manager.cpp
  src/box_timeout_dialog.cpp
  src/warehouseframe.cpp
  src/ColorListWidget.cpp
)

set(HEADERS
  include/mainwindow.h
  include/box.h
  include/drone.h
  include/new_box_dialog.h
  include/box_timeout_dialog.h
  include/update_system_dialog.h
  include/backend_manager.h
  include/helper.h
  include/warehouseframe.h
  include/ColorListWidget.h
)

# Create the executable (only once!)
add_executable(frontend_node
  ${SOURCES}
  ${HEADERS}
  ${UI_FILES}
  ${QT_RESOURCES}
)

target_include_directories(frontend_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)


install(TARGETS frontend_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY resources/
  DESTINATION share/${PROJECT_NAME}/resources
)

# ROS 2 deps
ament_target_dependencies(frontend_node
  rclcpp
  std_msgs
  dronehive_interfaces
)

# Qt linking
target_link_libraries(frontend_node
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
  Qt5::Charts
  Qt5::Xml
)

# Tests (optional)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
