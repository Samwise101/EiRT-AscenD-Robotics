from setuptools import find_packages
from setuptools import setup

setup(
    name='dronehive_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('dronehive_interfaces', 'dronehive_interfaces.*')),
)
