from setuptools import find_packages
from setuptools import setup

setup(
    name='fleet_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('fleet_msgs', 'fleet_msgs.*')),
)
