# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dronehive_interfaces:msg/DroneStatusMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DroneStatusMessage(type):
    """Metaclass of message 'DroneStatusMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('dronehive_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'dronehive_interfaces.msg.DroneStatusMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__drone_status_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__drone_status_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__drone_status_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__drone_status_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__drone_status_message

            from dronehive_interfaces.msg import PositionMessage
            if PositionMessage.__class__._TYPE_SUPPORT is None:
                PositionMessage.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DroneStatusMessage(metaclass=Metaclass_DroneStatusMessage):
    """Message class 'DroneStatusMessage'."""

    __slots__ = [
        '_drone_id',
        '_battery_voltage',
        '_battery_percentage',
        '_fligt_state',
        '_reached_first_waypoint',
        '_current_position',
    ]

    _fields_and_field_types = {
        'drone_id': 'string',
        'battery_voltage': 'float',
        'battery_percentage': 'float',
        'fligt_state': 'string',
        'reached_first_waypoint': 'boolean',
        'current_position': 'dronehive_interfaces/PositionMessage',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['dronehive_interfaces', 'msg'], 'PositionMessage'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.drone_id = kwargs.get('drone_id', str())
        self.battery_voltage = kwargs.get('battery_voltage', float())
        self.battery_percentage = kwargs.get('battery_percentage', float())
        self.fligt_state = kwargs.get('fligt_state', str())
        self.reached_first_waypoint = kwargs.get('reached_first_waypoint', bool())
        from dronehive_interfaces.msg import PositionMessage
        self.current_position = kwargs.get('current_position', PositionMessage())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.drone_id != other.drone_id:
            return False
        if self.battery_voltage != other.battery_voltage:
            return False
        if self.battery_percentage != other.battery_percentage:
            return False
        if self.fligt_state != other.fligt_state:
            return False
        if self.reached_first_waypoint != other.reached_first_waypoint:
            return False
        if self.current_position != other.current_position:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def drone_id(self):
        """Message field 'drone_id'."""
        return self._drone_id

    @drone_id.setter
    def drone_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'drone_id' field must be of type 'str'"
        self._drone_id = value

    @builtins.property
    def battery_voltage(self):
        """Message field 'battery_voltage'."""
        return self._battery_voltage

    @battery_voltage.setter
    def battery_voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'battery_voltage' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'battery_voltage' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._battery_voltage = value

    @builtins.property
    def battery_percentage(self):
        """Message field 'battery_percentage'."""
        return self._battery_percentage

    @battery_percentage.setter
    def battery_percentage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'battery_percentage' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'battery_percentage' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._battery_percentage = value

    @builtins.property
    def fligt_state(self):
        """Message field 'fligt_state'."""
        return self._fligt_state

    @fligt_state.setter
    def fligt_state(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'fligt_state' field must be of type 'str'"
        self._fligt_state = value

    @builtins.property
    def reached_first_waypoint(self):
        """Message field 'reached_first_waypoint'."""
        return self._reached_first_waypoint

    @reached_first_waypoint.setter
    def reached_first_waypoint(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'reached_first_waypoint' field must be of type 'bool'"
        self._reached_first_waypoint = value

    @builtins.property
    def current_position(self):
        """Message field 'current_position'."""
        return self._current_position

    @current_position.setter
    def current_position(self, value):
        if __debug__:
            from dronehive_interfaces.msg import PositionMessage
            assert \
                isinstance(value, PositionMessage), \
                "The 'current_position' field must be a sub message of type 'PositionMessage'"
        self._current_position = value
