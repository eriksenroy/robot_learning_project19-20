#include "ros/ros.h"
#include "sensor_msgs/JointState.h"

void PositionCallback(const sensor_msgs::JointState::ConstPtr& msg) {
  double x = msg->position[0];
  double y = msg->position[2];

  ROS_INFO("joint1: %2.2f, joint2: %2.2f" ,x,y);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "position_monitor");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("joint_states" , 10, PositionCallback);
  ros::spin();
  return 0;
}
