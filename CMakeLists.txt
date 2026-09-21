cmake_minimum_required(VERSION 3.8)
project(donnieros2turtlesim)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(Protobuf REQUIRED)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS proto/turtle.proto)

add_executable(teleop src/teleop.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(teleop PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${Protobuf_INCLUDE_DIRS})
target_link_libraries(teleop ${Protobuf_LIBRARIES})
ament_target_dependencies(teleop rclcpp std_msgs)

add_executable(control src/control.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(control PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${Protobuf_INCLUDE_DIRS})
target_link_libraries(control ${Protobuf_LIBRARIES})
ament_target_dependencies(control rclcpp std_msgs geometry_msgs)

install(TARGETS
  teleop
  control
  DESTINATION lib/${PROJECT_NAME})

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

ament_package()
