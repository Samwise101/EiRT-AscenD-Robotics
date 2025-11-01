# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dronehive_interfaces:srv/RequestDroneLanding.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RequestDroneLanding_Request(type):
    """Metaclass of message 'RequestDroneLanding_Request'."""

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
                'dronehive_interfaces.srv.RequestDroneLanding_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__request_drone_landing__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__request_drone_landing__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__request_drone_landing__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__request_drone_landing__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__request_drone_landing__request

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


class RequestDroneLanding_Request(metaclass=Metaclass_RequestDroneLanding_Request):
    """Message class 'RequestDroneLanding_Request'."""

    __slots__ = [
        '_drone_id',
        '_drone_pos',
    ]

    _fields_and_field_types = {
        'drone_id': 'string',
        'drone_pos': 'dronehive_interfaces/PositionMessage',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['dronehive_interfaces', 'msg'], 'PositionMessage'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.drone_id = kwargs.get('drone_id', str())
        from dronehive_interfaces.msg import PositionMessage
        self.drone_pos = kwargs.get('drone_pos', PositionMessage())

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
        if self.drone_pos != other.drone_pos:
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
    def drone_pos(self):
        """Message field 'drone_pos'."""
        return self._drone_pos

    @drone_pos.setter
    def drone_pos(self, value):
        if __debug__:
            from dronehive_interfaces.msg import PositionMessage
            assert \
                isinstance(value, PositionMessage), \
                "The 'drone_pos' field must be a sub message of type 'PositionMessage'"
        self._drone_pos = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RequestDroneLanding_Response(type):
    """Metaclass of message 'RequestDroneLanding_Response'."""

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
                'dronehive_interfaces.srv.RequestDroneLanding_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__request_drone_landing__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__request_drone_landing__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__request_drone_landing__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__request_drone_landing__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__request_drone_landing__response

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


class RequestDroneLanding_Response(metaclass=Metaclass_RequestDroneLanding_Response):
    """Message class 'RequestDroneLanding_Response'."""

    __slots__ = [
        '_landing_pos',
    ]

    _fields_and_field_types = {
        'landing_pos': 'dronehive_interfaces/PositionMessage',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['dronehive_interfaces', 'msg'], 'PositionMessage'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from dronehive_interfaces.msg import PositionMessage
        self.landing_pos = kwargs.get('landing_pos', PositionMessage())

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


class Metaclass_RequestDroneLanding(type):
    """Metaclass of service 'RequestDroneLanding'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('dronehive_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'dronehive_interfaces.srv.RequestDroneLanding')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__request_drone_landing

            from dronehive_interfaces.srv import _request_drone_landing
            if _request_drone_landing.Metaclass_RequestDroneLanding_Request._TYPE_SUPPORT is None:
                _request_drone_landing.Metaclass_RequestDroneLanding_Request.__import_type_support__()
            if _request_drone_landing.Metaclass_RequestDroneLanding_Response._TYPE_SUPPORT is None:
                _request_drone_landing.Metaclass_RequestDroneLanding_Response.__import_type_support__()


class RequestDroneLanding(metaclass=Metaclass_RequestDroneLanding):
    from dronehive_interfaces.srv._request_drone_landing import RequestDroneLanding_Request as Request
    from dronehive_interfaces.srv._request_drone_landing import RequestDroneLanding_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
