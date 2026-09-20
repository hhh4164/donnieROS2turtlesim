#include <iostream>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "turtle.pb.h"


int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    //continue creating node-> create publisher 
    char input;
    std::cout << "Move (WASD): ";
    while (std::cin >> input){
        if(input == 'q' || input == 'Q') break;
        turtleproto::TurtleCommand cmd;

        if(input =='w'){
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
    }
    std::cout << input;
    return 0;
}