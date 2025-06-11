# Use official ROS 2 Humble base image
FROM ros:humble

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV ROS_DISTRO=humble

# Install additional development tools
RUN apt-get update && apt-get install -y \
    python3-colcon-common-extensions \
    python3-rosdep \
    python3-vcstool \
    git \
    vim \
    wget \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Create workspace directory
WORKDIR /workspace

# Initialize rosdep
RUN rosdep update

# Source ROS 2 setup in bashrc
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc

# Set the default command
CMD ["/bin/bash"] 