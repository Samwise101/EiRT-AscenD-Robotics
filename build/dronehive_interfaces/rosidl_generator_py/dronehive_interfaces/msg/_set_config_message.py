# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dronehive_interfaces:msg/SetConfigMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetConfigMessage(type):
    """Metaclass of message 'SetConfigMessage'."""

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
                'dronehive_interfaces.msg.SetConfigMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__set_config_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__set_config_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__set_config_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__set_config_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__set_config_message

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetConfigMessage(metaclass=Metaclass_SetConfigMessage):
    """Message class 'SetConfigMessage'."""

    __slots__ = [
        '_box_id',
        '_drone_id',
        '_drone_name',
        '_drone_type',
        '_drone_setup',
    ]

    _fields_and_field_types = {
        'box_id': 'string',
        'drone_id': 'string',
        'drone_name': 'string',
        'drone_type': 'string',
        'drone_setup': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.box_id = kwargs.get('box_id', str())
        self.drone_id = kwargs.get('drone_id', str())
        self.drone_name = kwargs.get('drone_name', str())
        self.drone_type = kwargs.get('drone_type', str())
        self.drone_setup = kwargs.get('drone_setup', str())

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
        if self.box_id != other.box_id:
            return False
        if self.drone_id != other.drone_id:
            return False
        if self.drone_name != other.drone_name:
            return False
        if self.drone_type != other.drone_type:
            return False
        if self.drone_setup != other.drone_setup:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def drone_name(self):
        """Message field 'drone_name'."""
        return self._drone_name

    @drone_name.setter
    def drone_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'drone_name' field must be of type 'str'"
        self._drone_name = value

    @builtins.property
    def drone_type(self):
        """Message field 'drone_type'."""
        return self._drone_type

    @drone_type.setter
    def drone_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'drone_type' field must be of type 'str'"
        self._drone_type = value

    @builtins.property
    def drone_setup(self):
        """Message field 'drone_setup'."""
        return self._drone_setup

    @drone_setup.setter
    def drone_setup(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'drone_setup' field must be of type 'str'"
        self._drone_setup = value
