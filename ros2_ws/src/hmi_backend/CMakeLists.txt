cmake_minimum_required(VERSION 3.8)
project(hmi_backend)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_compile_definitions(DRONEHIVE_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(dronehive_interfaces REQUIRED)

# Qt dependencies
find_package(Qt5 REQUIRED COMPONENTS Core)

set(SOURCES
    src/main.cpp
    src/app.cpp
)

set(HEADERS
    include/app.h
)

add_executable(backend_node
    ${SOURCES}
    ${HEADERS}
)


target_include_directories(backend_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(TARGETS backend_node
  DESTINATION lib/${PROJECT_NAME}
)



# ROS 2 deps
ament_target_dependencies(backend_node
  rclcpp
  std_msgs
  dronehive_interfaces
)

# Qt linking
target_link_libraries(backend_node
  Qt5::Core
)

# Tests (optional)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
