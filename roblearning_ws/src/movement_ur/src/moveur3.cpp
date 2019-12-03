// This program publishes randomly-generated velocity
// messages for turtlesim.
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>  // For geometry_msgs::Twist
#include <stdlib.h> // For rand() and RAND_MAX
#include <trajectory_msgs/JointTrajectory.h>
#include <std_msgs/Int32.h>
int main(int argc, char **argv)
{
 ros::init(argc, argv, "topic_publisher");
 ros::NodeHandle nh;
 //ros::Rate loop_rate(1);
 //ros::Publisher r_arm_comand_publisher = nh.advertise<trajectory_msgs::JointTrajectory>("/arm_controller/command", 1000);
 ros::Publisher pub = nh.advertise<std_msgs::Int32>("counter", 1000);

 ros::Rate rate(30);
 std_msgs::Int32 count;
 // Create a JointTrajectory with all positions set to zero, and command the arm.
  while(ros::ok())
 {
  /*// Create a message to send.
  trajectory_msgs::JointTrajectory msg;

  // Fill the names of the joints to be controlled.
  msg.joint_names.clear();
  msg.joint_names.push_back("shoulder_pan_joint");
  msg.joint_names.push_back("shoulder_lift_joint");
  msg.joint_names.push_back("elbow_joint");
  msg.joint_names.push_back("wrist_1_joint");
  msg.joint_names.push_back("wrist_2_joint");
  msg.joint_names.push_back("wrist_3_joint");
  // Create one point in the trajectory.
  msg.points.resize(1);
  // Resize the vector to the same length as the joint names.
  // Values are initialized to 0.
  msg.points[0].positions.resize(msg.joint_names.size(), 0);
  // How long to take getting to the point (floating point seconds).
  msg.points[0].time_from_start = ros::Duration(0.001);

  ROS_INFO_STREAM ("Sending command:\n" << msg);
  r_arm_comand_publisher.publish(msg);
  */
  //ros::spinOnce();
  pub.publish(count);
  ros::spinOnce();
  rate.sleep();
  ++count.data;
 }

 ROS_INFO_STREAM("***** SHUTTING DOWN ********\n");
 return 0;
}
