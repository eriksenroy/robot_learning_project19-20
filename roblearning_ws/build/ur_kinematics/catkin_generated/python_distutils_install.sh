#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/roy/roblearning_ws/src/ur3_robot/ur_kinematics"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/roy/roblearning_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/roy/roblearning_ws/install/lib/python2.7/dist-packages:/home/roy/roblearning_ws/build/ur_kinematics/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/roy/roblearning_ws/build/ur_kinematics" \
    "/usr/bin/python2" \
    "/home/roy/roblearning_ws/src/ur3_robot/ur_kinematics/setup.py" \
    build --build-base "/home/roy/roblearning_ws/build/ur_kinematics" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/roy/roblearning_ws/install" --install-scripts="/home/roy/roblearning_ws/install/bin"
