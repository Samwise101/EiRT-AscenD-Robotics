# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dronehive_interfaces:msg/BoxStatusMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BoxStatusMessage(type):
    """Metaclass of message 'BoxStatusMessage'."""

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
                'dronehive_interfaces.msg.BoxStatusMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__box_status_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__box_status_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__box_status_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__box_status_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__box_status_message

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


class BoxStatusMessage(metaclass=Metaclass_BoxStatusMessage):
    """Message class 'BoxStatusMessage'."""

    __slots__ = [
        '_landing_pos',
        '_box_battery_level',
        '_box_id',
        '_drone_id',
        '_status',
    ]

    _fields_and_field_types = {
        'landing_pos': 'dronehive_interfaces/PositionMessage',
        'box_battery_level': 'double',
        'box_id': 'string',
        'drone_id': 'string',
        'status': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['dronehive_interfaces', 'msg'], 'PositionMessage'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from dronehive_interfaces.msg import PositionMessage
        self.landing_pos = kwargs.get('landing_pos', PositionMessage())
        self.box_battery_level = kwargs.get('box_battery_level', float())
        self.box_id = kwargs.get('box_id', str())
        self.drone_id = kwargs.get('drone_id', str())
        self.status = kwargs.get('status', str())

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
        if self.landing_pos != other.landing_pos:
            return False
        if self.box_battery_level != other.box_battery_level:
            return False
        if self.box_id != other.box_id:
            return False
        if self.drone_id != other.drone_id:
            return False
        if self.status != other.status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def landing_pos(self):
        """Message field 'landing_pos'."""
        return self._landing_pos

    @landing_pos.setter
    def landing_pos(self, value):
        if __debug__:
            from dronehive_interfaces.msg import PositionMessage
            assert \
                isinstance(value, PositionMessage), \
                "The 'landing_pos' field must be a sub message of type 'PositionMessage'"
        self._landing_pos = value

    @builtins.property
    def box_battery_level(self):
        """Message field 'box_battery_level'."""
        return self._box_battery_level

    @box_battery_level.setter
    def box_battery_level(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'box_battery_level' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'box_battery_level' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._box_battery_level = value

    @builtins.property
    def box_id(self):
        """Message field 'box_id'."""
        return self._box_id

    @box_id.setter
    def box_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'box_id' field must be of type 'str'"
        self._box_id = value

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
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'status' field must be of type 'str'"
        self._status = value
