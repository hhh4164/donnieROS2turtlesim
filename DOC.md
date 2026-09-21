**Goal**: Design a simple ROS2 program to control a turtle in TurtleSim. The program should use protobuf for communication and have a simple control interface to send movement commands to the turtle.

---

Given ROS2’s turtlesim package, I am essentially replacing its teleop node and keeping the turtlesim node.
The topic/turtle1/cmd_vel is used to instruct the turtle to move through Twist messages (linear/angular: xyz).

Hence the pipeline should look something like this:
Input ->Teleop node-> protobuf message -> control_node -> Twist -> cmd_vel -> turtlesim node

**Teleop**: Reads input, formats it into protobuf, sends it to control node
>Send to control node via topic for one way data flow
**Control**: Reads protobuf, formats it into Twist, sends to cmd_vel for turtlesim
>In this way, control can read any teleop program and format it for turtlesim (as long as it uses the same protobuf)

---

# Structure:
```
├── CMakeLists.txt
├── DOC.md
├── LICENSE
├── include
│   └── donnieROS2turtlesim
├── package.xml
├── proto
│   └── turtle.proto
└── src
    ├── control.cpp
    └── teleop.cpp
```