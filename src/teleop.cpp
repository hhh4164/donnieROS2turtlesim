#include <iostream>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int8_multi_array.hpp"
#include "turtle.pb.h"

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("teleop"); //create node
    auto pub = node->create_publisher<std_msgs::msg::UInt8MultiArray>("topic1", 10);
    /*node becomes a publisher to topic1, message is in format of unsigned ints
    to send serialized protobuf message (stream of bytes) */

    char input; //take input: key -> enter -> key -> enter etc.
    std::cout << "Move (WASD): ";
    while (std::cin >> input){
        if(input == 'q' || input == 'Q') break;
        turtleproto::TurtleCommand cmd;

        if(input =='w'){ //read key, set protobuf cmd
            cmd.set_direction(turtleproto::TurtleCommand::FORWARD);
        } else if (input == 's'){
            cmd.set_direction(turtleproto::TurtleCommand::BACKWARD);
        } else if (input == 'a'){
            cmd.set_direction(turtleproto::TurtleCommand::LEFT);
        } else if (input == 'd'){
            cmd.set_direction(turtleproto::TurtleCommand::RIGHT);
        } else {
            continue;
        }

        std::string bytes; 
        cmd.SerializeToString(&bytes); //protobuf fills bytes string with binary cmd
        std_msgs::msg::UInt8MultiArray msg;
        msg.data.assign(bytes.begin(), bytes.end()); //assigns msg with bytes
        pub->publish(msg); //publish msg to topic
    }
    rclcpp::shutdown();
    return 0;
}