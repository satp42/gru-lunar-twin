from setuptools import setup

package_name = 'fleet_core'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Fleet Team',
    maintainer_email='dev@example.com',
    description='Fleet core node',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'fleet_node = fleet_core.fleet_node:main',
            'power_manager = fleet_core.power_manager:main',
        ],
    },
) 