**Goal**: Design a simple ROS2 program to control a turtle in TurtleSim. The program should use protobuf for communication and have a simple control interface to send movement commands to the turtle.

---

Given ROS2’s turtlesim package, I am essentially replacing its teleop node and keeping the turtlesim node.
The topic/turtle1/cmd_vel is used to instruct the turtle to move through Twist messages (linear/angular: xyz).

Hence the pipeline should look something like this:
Input ->Teleop app-> protobuf message -> control_node -> Twist -> cmd_vel -> turtlesim node

---

# Structure:
donnieROS2turtlesim/
	CMakeLists.txt
    DOC.md
	include/donnieROS2turtlesim/
	package.xml
	src/
		teleop.cpp
		control_node.cpp
	proto/
		turtle.proto

