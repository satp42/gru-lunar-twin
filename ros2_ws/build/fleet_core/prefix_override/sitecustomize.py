import sys
if sys.prefix == '/opt/homebrew/opt/python@3.13/Frameworks/Python.framework/Versions/3.13':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/Users/satwikpanigrahi/Desktop/gru-lunar-twin/ros2_ws/install/fleet_core'
