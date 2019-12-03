# robot_learning_project19-20

First time installing
Open terminal:
  cd
  git clone https://github.com/eriksenroy/robot_learning_project19-20.git
  cd /robot_learning_project19-20/roblearning_ws
  catkin clean
  catkin build
  source devel/setup.bash
  
  
To start simulation
  roslaunch ur_gazebo ur3.launch
  
To check with the incremental movement node
  While the gazebo simulation is running, open another terminal window
  cd /robot_learning_project19-20/roblearning_ws
  source devel/setup.bash
  rosrun movement_ur subandpub
  
  


If there is an warning that say that the JointTrajectory controller is not there
  sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
  sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
  sudo apt-get update
  rosdep update
  echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
  sudo apt-get install ros-melodic-ros-control ros-melodic-ros-controllers
  sudo apt-get install ros-melodic-gazebo-ros-pkgs ros-melodic-gazebo-ros-control



