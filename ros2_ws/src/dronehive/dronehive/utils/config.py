from dronehive_interfaces.msg import PositionMessage
from rclpy.logging import get_logger as rclpy_logger

from dataclasses import dataclass, field
from pathlib import Path
import json
import os

HOME: Path = Path.home()
CONFIG_PATH = Path(os.getenv("XDG_CONFIG_HOME", f"{HOME}/.config"))

DRONEHIVE_SHARE_DIR = HOME / ".local" / "share" / "dronehive"
DRONEHIVE_CONFIG_DIR = CONFIG_PATH / "dronehive"
DRONEHIVE_DIRS = [
	DRONEHIVE_SHARE_DIR,
	DRONEHIVE_CONFIG_DIR
]

@dataclass
class Config:
	box_id: str = ""
	drone_id: str = ""
	initialised: bool = False
	landing_position: PositionMessage = field(default_factory=PositionMessage)
	linked_box_ids: list[str] = field(default_factory=list)

	@staticmethod
	def load() -> 'Config':
		json_path = DRONEHIVE_CONFIG_DIR / "config.json"
		rclpy_logger("Config").info(f"Loading configuration from {json_path}")

		if json_path.exists():
			with open(json_path, 'r') as f:
				data = json.load(f)
				rclpy_logger("Config").debug(f"Configuration loaded: {data}")
				return Config(
					box_id = data.get("box_id", ""),
					drone_id = data.get("drone_id", ""),
					initialised = data.get("initialised", False),
					landing_position = PositionMessage(**data.get("lending_position", {})),
					linked_box_ids = data.get("linked_box_ids", [])
				)

		conf = Config()
		conf.save()
		# Placeholder for loading configuration from a file or environment
		# For now, return a default Config object
		return Config()

	def save(self) -> None:
		json_path = DRONEHIVE_CONFIG_DIR / "config.json"
		with open(json_path, 'w') as f:
			f.write(self._to_json())

	def _to_json(self) -> str:
		return json.dumps({
			"box_id": self.box_id,
			"drone_id": self.drone_id,
			"initialised": self.initialised,
			"lending_position": {
				"lat": self.landing_position.lat,
				"lon": self.landing_position.lon,
				"elv": self.landing_position.elv
			},
			"linked_box_ids": self.linked_box_ids
		}, indent=4)


