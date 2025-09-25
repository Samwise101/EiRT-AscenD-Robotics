from dronehive_interfaces.msg import PositionMessage

from dataclasses import dataclass
from pathlib import Path
import json

HOME: Path = Path.home()

DRONEHIVE_SHARE_DIR = HOME / ".local" / "share" / "dronehive"
DRONEHIVE_CONFIG_DIR = HOME / ".config" / "dronehive"
DRONEHIVE_DIRS = [
	DRONEHIVE_SHARE_DIR,
	DRONEHIVE_CONFIG_DIR
]

@dataclass
class Config:
	box_id: str = ""
	drone_id: str = ""
	initialised: bool = False
	lending_position: PositionMessage = PositionMessage()

	@staticmethod
	def load() -> 'Config':
		json_path = DRONEHIVE_CONFIG_DIR / "config.json"
		if json_path.exists():
			with open(json_path, 'r') as f:
				data = json.load(f)
				return Config(
					box_id = data.get("box_id", ""),
					drone_id = data.get("drone_id", ""),
					initialised = data.get("initialised", False),
					lending_position = PositionMessage(**data.get("lending_position", {}))
				)

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
				"lat": self.lending_position.lat,
				"lon": self.lending_position.lon,
				"elv": self.lending_position.elv
			}
		}, indent=4)


