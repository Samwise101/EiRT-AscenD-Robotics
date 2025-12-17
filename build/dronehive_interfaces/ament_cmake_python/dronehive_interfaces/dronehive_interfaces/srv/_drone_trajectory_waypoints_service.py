# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dronehive_interfaces:srv/DroneTrajectoryWaypointsService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DroneTrajectoryWaypointsService_Request(type):
    """Metaclass of message 'DroneTrajectoryWaypointsService_Request'."""

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
                'dronehive_interfaces.srv.DroneTrajectoryWaypointsService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__drone_trajectory_waypoints_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__drone_trajectory_waypoints_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__drone_trajectory_waypoints_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__drone_trajectory_waypoints_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__drone_trajectory_waypoints_service__request

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


class DroneTrajectoryWaypointsService_Request(metaclass=Metaclass_DroneTrajectoryWaypointsService_Request):
    """Message class 'DroneTrajectoryWaypointsService_Request'."""

    __slots__ = [
        '_drone_id',
        '_waypoints',
    ]

    _fields_and_field_types = {
        'drone_id': 'string',
        'waypoints': 'sequence<dronehive_interfaces/PositionMessage>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['dronehive_interfaces', 'msg'], 'PositionMessage')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.drone_id = kwargs.get('drone_id', str())
        self.waypoints = kwargs.get('waypoints', [])

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
        if self.waypoints != other.waypoints:
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
    def waypoints(self):
        """Message field 'waypoints'."""
        return self._waypoints

    @waypoints.setter
    def waypoints(self, value):
        if __debug__:
            from dronehive_interfaces.msg import PositionMessage
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, PositionMessage) for v in value) and
                 True), \
                "The 'waypoints' field must be a set or sequence and each value of type 'PositionMessage'"
        self._waypoints = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_DroneTrajectoryWaypointsService_Response(type):
    """Metaclass of message 'DroneTrajectoryWaypointsService_Response'."""

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
                'dronehive_interfaces.srv.DroneTrajectoryWaypointsService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__drone_trajectory_waypoints_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__drone_trajectory_waypoints_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__drone_trajectory_waypoints_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__drone_trajectory_waypoints_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__drone_trajectory_waypoints_service__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DroneTrajectoryWaypointsService_Response(metaclass=Metaclass_DroneTrajectoryWaypointsService_Response):
    """Message class 'DroneTrajectoryWaypointsService_Response'."""

    __slots__ = [
        '_ack',
    ]

    _fields_and_field_types = {
        'ack': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ack = kwargs.get('ack', bool())

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
        if self.ack != other.ack:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ack(self):
        """Message field 'ack'."""
        return self._ack

    @ack.setter
    def ack(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'ack' field must be of type 'bool'"
        self._ack = value


class Metaclass_DroneTrajectoryWaypointsService(type):
    """Metaclass of service 'DroneTrajectoryWaypointsService'."""

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
                'dronehive_interfaces.srv.DroneTrajectoryWaypointsService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__drone_trajectory_waypoints_service

            from dronehive_interfaces.srv import _drone_trajectory_waypoints_service
            if _drone_trajectory_waypoints_service.Metaclass_DroneTrajectoryWaypointsService_Request._TYPE_SUPPORT is None:
                _drone_trajectory_waypoints_service.Metaclass_DroneTrajectoryWaypointsService_Request.__import_type_support__()
            if _drone_trajectory_waypoints_service.Metaclass_DroneTrajectoryWaypointsService_Response._TYPE_SUPPORT is None:
                _drone_trajectory_waypoints_service.Metaclass_DroneTrajectoryWaypointsService_Response.__import_type_support__()


class DroneTrajectoryWaypointsService(metaclass=Metaclass_DroneTrajectoryWaypointsService):
    from dronehive_interfaces.srv._drone_trajectory_waypoints_service import DroneTrajectoryWaypointsService_Request as Request
    from dronehive_interfaces.srv._drone_trajectory_waypoints_service import DroneTrajectoryWaypointsService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
