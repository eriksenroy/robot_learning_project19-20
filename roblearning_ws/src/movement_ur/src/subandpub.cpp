#include <ros/ros.h>
#include "sensor_msgs/JointState.h"
#include <std_msgs/Float64.h>
#include <trajectory_msgs/JointTrajectory.h>
double i = 0;
class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub_ = n_.advertise<trajectory_msgs::JointTrajectory>("/arm_controller/command", 1);

    //Topic you want to subscribe
    sub_ = n_.subscribe("/joint_states", 1, &SubscribeAndPublish::callback, this);
  }

  void callback(const sensor_msgs::JointState::ConstPtr& input)
  {
    trajectory_msgs::JointTrajectory output;
    // Fill the names of the joints to be controlled.
    i = i+0.0001;
    double x0 = input->position[0] +i;
    double x1 = input->position[1] -i;
    double x2 = input->position[2] ;
    double x3 = input->position[3] ;
    double x4 = input->position[4];
    double x5 = input->position[5];
    ROS_INFO("joint1: %2.2f, joint2: %2.2f,joint1: %2.2f, joint2: %2.2f,joint1: %2.2f, joint2: %2.2f",x0,x1,x2,x3,x4,x5);
    output.joint_names.clear();
    output.joint_names.push_back("shoulder_pan_joint");
    output.joint_names.push_back("shoulder_lift_joint");
    output.joint_names.push_back("elbow_joint");
    output.joint_names.push_back("wrist_1_joint");
    output.joint_names.push_back("wrist_2_joint");
    output.joint_names.push_back("wrist_3_joint");
    output.points.resize(1);
    int index = 0;
    output.points[index].positions.resize(6);
    output.points[index].positions[0] = x0;
    output.points[index].positions[1] = x1;
    output.points[index].positions[2] = x2;
    output.points[index].positions[3] = x3;
    output.points[index].positions[4] = x4;
    output.points[index].positions[5] = x5;
    /*output.points[0].positions.resize(output.joint_names.size(), 0);
    output.points[0].positions[1].(x1);
    output.points[0].positions[2].(x2);
    output.points[0].positions[3].(x3);
    output.points[0].positions[4].(x4);
    output.points[0].positions[5].(x5);*/

    output.points[0].time_from_start = ros::Duration(2);
    ROS_INFO_STREAM ("Sending command:\n" << output);
    pub_.publish(output);
  }

private:
  ros::NodeHandle n_;
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "subscribe_and_publish");
  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}
