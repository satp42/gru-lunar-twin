# Use official ROS 2 Humble base image
FROM ros:humble

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV ROS_DISTRO=humble

# Install additional development tools and Gazebo
RUN apt-get update && apt-get install -y \
    python3-colcon-common-extensions \
    python3-rosdep \
    python3-vcstool \
    git \
    vim \
    wget \
    curl \
    # Install Gazebo + ROS integration (official method)
    ros-${ROS_DISTRO}-ros-gz \
    # Additional development tools
    build-essential \
    cmake \
    python3-pip \
    # Gazebo development packages for building plugins
    libgz-sim6-dev \
    libgz-cmake2-dev \
    libgz-transport11-dev \
    libgz-msgs8-dev \
    && rm -rf /var/lib/apt/lists/*

# Create workspace directory
WORKDIR /workspace

# Initialize rosdep
RUN rosdep update

# Source ROS 2 setup in bashrc
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc

# Source workspace setup if available
RUN echo "source /workspace/install/setup.bash 2>/dev/null || true" >> ~/.bashrc

# Set the default command
CMD ["/bin/bash"] 