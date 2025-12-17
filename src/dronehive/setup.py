from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'dronehive'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),

        # Install launch files
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),

        # Install RViz configs
        (os.path.join('share', package_name, 'rviz'), glob('rviz/*.rviz')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='fildo',
    maintainer_email='filo23@student.sdu.dk',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'box_node = dronehive.box_node:main',
            'slave_node = dronehive.slave_box_node:main',
            'dummy_confirm = dronehive.dummy:main',
            'dummy_drone = dronehive.dummy_drone:main',
            'offboard = offboard.offboard:main'
        ],
    },
)
