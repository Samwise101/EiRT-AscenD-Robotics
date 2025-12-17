# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dronehive_interfaces:srv/AddRemoveDroneService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AddRemoveDroneService_Request(type):
    """Metaclass of message 'AddRemoveDroneService_Request'."""

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
                'dronehive_interfaces.srv.AddRemoveDroneService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__add_remove_drone_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__add_remove_drone_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__add_remove_drone_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__add_remove_drone_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__add_remove_drone_service__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AddRemoveDroneService_Request(metaclass=Metaclass_AddRemoveDroneService_Request):
    """Message class 'AddRemoveDroneService_Request'."""

    __slots__ = [
        '_drone_id',
        '_box_id',
    ]

    _fields_and_field_types = {
        'drone_id': 'string',
        'box_id': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.drone_id = kwargs.get('drone_id', str())
        self.box_id = kwargs.get('box_id', str())

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
        if self.box_id != other.box_id:
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


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_AddRemoveDroneService_Response(type):
    """Metaclass of message 'AddRemoveDroneService_Response'."""

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
                'dronehive_interfaces.srv.AddRemoveDroneService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__add_remove_drone_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__add_remove_drone_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__add_remove_drone_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__add_remove_drone_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__add_remove_drone_service__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AddRemoveDroneService_Response(metaclass=Metaclass_AddRemoveDroneService_Response):
    """Message class 'AddRemoveDroneService_Response'."""

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


class Metaclass_AddRemoveDroneService(type):
    """Metaclass of service 'AddRemoveDroneService'."""

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
                'dronehive_interfaces.srv.AddRemoveDroneService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__add_remove_drone_service

            from dronehive_interfaces.srv import _add_remove_drone_service
            if _add_remove_drone_service.Metaclass_AddRemoveDroneService_Request._TYPE_SUPPORT is None:
                _add_remove_drone_service.Metaclass_AddRemoveDroneService_Request.__import_type_support__()
            if _add_remove_drone_service.Metaclass_AddRemoveDroneService_Response._TYPE_SUPPORT is None:
                _add_remove_drone_service.Metaclass_AddRemoveDroneService_Response.__import_type_support__()


class AddRemoveDroneService(metaclass=Metaclass_AddRemoveDroneService):
    from dronehive_interfaces.srv._add_remove_drone_service import AddRemoveDroneService_Request as Request
    from dronehive_interfaces.srv._add_remove_drone_service import AddRemoveDroneService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
