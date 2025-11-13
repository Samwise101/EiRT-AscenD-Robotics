from .topics import *
from .config import Config, DRONEHIVE_DIRS
from .initialiser import Initialiser
from .client_manager import ServiceClientManager
from .utm import *
from .dynamixel_controller import XL430Controller

from typing import Optional
from rclpy.logging import get_logger as rclpy_logger

from dataclasses import dataclass
from enum import Enum

from dronehive_interfaces.msg import PositionMessage

def dronehive_initialise() -> Config:
	print("Initializing the package with constants:")
	for dir in DRONEHIVE_DIRS:
		# Ensure each directory exists
		dir.mkdir(parents=True, exist_ok=True)

	conf: Config = Config.load()
	return conf

def dronehive_deinitialise(config: Optional[Config] = None) -> None:
	if config is None:
		config = Config.load()

	if config.initialised:
		config.initialised = False
		config.drone_id = ""
		config.linked_box_ids = set()

		config.save()

def dronehive_update_config(config: Config) -> None:
	config.save()

class BoxStatusEnum(Enum):
	UNKNOWN = "UNKNOWN"
	INITIALISING = "INITIALISING"
	OCCUPIED = "OCCUPIED"
	EMPTY = "EMPTY"

@dataclass
class BoxStatus:
	box_id: str
	drone_id: str
	position: PositionMessage
	status: BoxStatusEnum = BoxStatusEnum.UNKNOWN

