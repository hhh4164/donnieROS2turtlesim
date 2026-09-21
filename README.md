# donnieROS2turtlesim: 

<p> Controls ROS2's turtlesim using input commands in the command line serialized through protocol buffers, and published over a topic to a control node that translates them into movement for turtlesim. </p>

## Prerequisites
* ROS2 Humble installed https://docs.ros.org/en/humble/Installation.html 
* turtlesim package (sudo apt install ros-humble-turtlesim)
* Protobuf https://protobuf.dev/installation/ 
## Setup
Clone repo into your workspace's src/
```
cd ros2_ws/src
git clone https://github.com/hhh4164/donnieROS2turtlesim
```
## Build
```
cd ros2_ws
colcon build --packages-select donnieros2turtlesim
source install/setup.bash
```
Note:
- Build must be rerun when any code is changed
- New terminals need the source install to run again for ros2 run to find the package

## Run
You will need 3 terminals, each first sourced with 
```
source /opt/ros/humble/setup.bash
source ~/ros2_ws/install/setup.bash
```
Terminal 1: turtlesim 
``` 
ros2 run turtlesim turtlesim_node
```
Terminal 2: control node
```
ros2 run donnieros2turtlesim control
```
Terminal 3: teleop node
```
ros2 run donnieros2turtlesim teleop
```
<p>
Click into terminal 3 and type letter + enter: <br>
w: move forward <br>
s: move backward<br>
a: turn left<br>
d: turn right<br>
q: quit<br>
Other inputs are ignored </p>

## File Structure:
```
donnieros2turtlesim
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