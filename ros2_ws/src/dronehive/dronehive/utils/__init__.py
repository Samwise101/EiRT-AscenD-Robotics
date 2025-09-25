from .topics import *
from .config import Config, DRONEHIVE_DIRS
from .initialiser import Initialiser

def dronehive_initialise() -> Config:
	print("Initializing the package with constants:")
	for dir in DRONEHIVE_DIRS:
		# Ensure each directory exists
		dir.mkdir(parents=True, exist_ok=True)

	conf: Config = Config.load()
	return conf

def dronehive_deinitialise() -> None:
	config: Config = Config.load()
	if config.initialised:
		config.initialised = False
		dronehive_update_config(config)

def dronehive_update_config(config: Config) -> None:
	config.save()

