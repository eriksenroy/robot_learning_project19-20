# robot_learning_project19-20

# First time installing
## Open terminal:<br/>
  cd<br/>
  git clone https://github.com/eriksenroy/robot_learning_project19-20.git<br/>
  cd /robot_learning_project19-20/roblearning_ws<br/>
  catkin clean<br/>
  catkin build<br/>
  source devel/setup.bash<br/>
  
  
## To start simulation
  roslaunch ur_gazebo ur3.launch<br/>
  
## To check with the incremental movement node<br/>
  While the gazebo simulation is running, open another terminal window<br/>
  cd /robot_learning_project19-20/roblearning_ws<br/>
  source devel/setup.bash<br/>
  rosrun movement_ur subandpub<br/>
  
  


# If there is an warning that say that the JointTrajectory controller is not there<br/>
  sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'<br/>
  sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654<br/>
  sudo apt-get update<br/>
  rosdep update<br/>
  echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc<br/>
  sudo apt-get install ros-melodic-ros-control ros-melodic-ros-controllers<br/>
  sudo apt-get install ros-melodic-gazebo-ros-pkgs ros-melodic-gazebo-ros-control<br/>



