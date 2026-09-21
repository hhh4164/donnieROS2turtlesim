#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int8_multi_array.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtle.pb.h"

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("control");
    auto pub = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    //node becomes ublisher to turtle1/cmd_vel, message is in format of Twist
    //node is also subscribed to topic1
    auto sub = node->create_subscription<std_msgs::msg::UInt8MultiArray>("topic1", 10, 
    [pub](auto msg){ 
        turtleproto::TurtleCommand cmd;
        std::string bytes(msg->data.begin(), msg->data.end());
        cmd.ParseFromString(bytes); //deserializes the bytes and reconstructs cmd

        geometry_msgs::msg::Twist twist; //empty twist message to be filled. defaultt 0.0 for all values
         switch(cmd.direction()){
            case turtleproto::TurtleCommand::FORWARD:
                twist.linear.x = 1.0;
                break;
            case turtleproto::TurtleCommand::BACKWARD:
                twist.linear.x = -1.0;
                break;
            case turtleproto::TurtleCommand::LEFT:
                twist.angular.z = 1.0;
                break;
            case turtleproto::TurtleCommand::RIGHT:
                twist.angular.z = -1.0;
                break;
            default:
                break;
        }
        pub->publish(twist); //publish twist message to /turtle1/cmd_vel
    });

    rclcpp::spin(node);
     /* since control node is subscribed to topic1, it needs to listen 
     at all times for messages sent through it so spin keeps the node running. */
    rclcpp::shutdown();
    
    return 0;
}