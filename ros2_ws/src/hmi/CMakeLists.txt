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

install(
  DIRECTORY presets/
  DESTINATION share/${PROJECT_NAME}/presets
)

install(
  DIRECTORY drone_configs/
  DESTINATION share/${PROJECT_NAME}/drone_configs
)


# ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)


# Qt dependencies
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui Charts)

# UI + resources
set(UI_FILES
  ui/mainwindow.ui
)
qt5_add_resources(QT_RESOURCES resources/resources.qrc)

# Sources and headers
set(SOURCES
  src/main.cpp
  src/mainwindow.cpp
)

set(HEADERS
  include/mainwindow.h
)

# Create the executable (only once!)
add_executable(${PROJECT_NAME}
  ${SOURCES}
  ${HEADERS}
  ${UI_FILES}
  ${QT_RESOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ROS 2 deps
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  std_msgs
)

# Qt linking
target_link_libraries(${PROJECT_NAME}
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
  Qt5::Charts
)

# Tests (optional)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
