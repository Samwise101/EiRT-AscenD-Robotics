cmake_minimum_required(VERSION 3.22)
project(dronehive_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/BoxBroadcastService.srv"
  "srv/BoxStatusService.srv"
  "srv/BoxStatusSlaveUpdateService.srv"
  "srv/DroneLandingService.srv"
  "srv/DroneStatusService.srv"
  "srv/DroneTrajectoryWaypointsService.srv"
  "srv/GetConfig.srv"
  "srv/GetFlightlog.srv"
  "srv/OccupancyService.srv"
  "srv/RequestBoxStatus.srv"
  "srv/RequestBoxOpenService.srv"
  "srv/RequestDroneLanding.srv"
  "srv/RequestDroneStatus.srv"
  "srv/RequestFullSystemStatus.srv"
  "srv/RequestReturnHome.srv"
  "srv/RequestStatus.srv"
  "srv/SlaveBoxIDsService.srv"
  "srv/SlaveBoxInformationService.srv"

  "msg/BackendCommand.msg"
  "msg/BoxBroadcastMessage.msg"
  "msg/BoxFullStatus.msg"
  "msg/BoxSetupConfirmationMessage.msg"
  "msg/BoxStatusMessage.msg"
  "msg/DroneForceLandingMessage.msg"
  "msg/ExecutePathMessage.msg"
  "msg/GuiCommand.msg"
  "msg/OccupancyMessage.msg"
  "msg/PositionMessage.msg"
  "msg/SetConfigMessage.msg"
  "msg/SetPathMessage.msg"
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
