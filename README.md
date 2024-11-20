# ros2-cpp-cuda

## 📖 Description
`ros2-gpu-accelerated` is a ROS 2 package designed for high-performance computation using GPU acceleration. It leverages **CUDA** and **C++** integration to optimize computational tasks within the ROS 2 framework.

This package demonstrates how to link CUDA with C++ in a ROS 2 environment, enabling efficient GPU-based processing for robotics applications.

---

## 🚀 Features
- Seamless integration of CUDA and C++ in ROS 2.
- Optimized GPU computation for high-performance tasks.
- Easy to extend and customize for other GPU-accelerated robotics projects.


Prerequisites
ROS 2 Humble or later
CUDA Toolkit (ensure proper driver installation)
C++17 or later
Build the Package
Clone the repository into your ROS 2 workspace:

## Build the Package
- cd ~/ros2_ws/src
- git clone https://github.com/igeoni/ros2-cpp-cuda.git

- cd ~/ros2_ws
- colcon build --symlink-install

- source ~/ros2_ws/install/setup.bash
