# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dronehive_interfaces:srv/SlaveBoxInformationService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SlaveBoxInformationService_Request(type):
    """Metaclass of message 'SlaveBoxInformationService_Request'."""

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
                'dronehive_interfaces.srv.SlaveBoxInformationService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__slave_box_information_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__slave_box_information_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__slave_box_information_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__slave_box_information_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__slave_box_information_service__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SlaveBoxInformationService_Request(metaclass=Metaclass_SlaveBoxInformationService_Request):
    """Message class 'SlaveBoxInformationService_Request'."""

    __slots__ = [
        '_box_id',
    ]

    _fields_and_field_types = {
        'box_id': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
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
        if self.box_id != other.box_id:
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


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SlaveBoxInformationService_Response(type):
    """Metaclass of message 'SlaveBoxInformationService_Response'."""

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
                'dronehive_interfaces.srv.SlaveBoxInformationService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__slave_box_information_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__slave_box_information_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__slave_box_information_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__slave_box_information_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__slave_box_information_service__response

            from dronehive_interfaces.msg import BoxStatusMessage
            if BoxStatusMessage.__class__._TYPE_SUPPORT is None:
                BoxStatusMessage.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SlaveBoxInformationService_Response(metaclass=Metaclass_SlaveBoxInformationService_Response):
    """Message class 'SlaveBoxInformationService_Response'."""

    __slots__ = [
        '_status',
    ]

    _fields_and_field_types = {
        'status': 'dronehive_interfaces/BoxStatusMessage',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['dronehive_interfaces', 'msg'], 'BoxStatusMessage'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from dronehive_interfaces.msg import BoxStatusMessage
        self.status = kwargs.get('status', BoxStatusMessage())

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
        if self.status != other.status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            from dronehive_interfaces.msg import BoxStatusMessage
            assert \
                isinstance(value, BoxStatusMessage), \
                "The 'status' field must be a sub message of type 'BoxStatusMessage'"
        self._status = value


class Metaclass_SlaveBoxInformationService(type):
    """Metaclass of service 'SlaveBoxInformationService'."""

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
                'dronehive_interfaces.srv.SlaveBoxInformationService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__slave_box_information_service

            from dronehive_interfaces.srv import _slave_box_information_service
            if _slave_box_information_service.Metaclass_SlaveBoxInformationService_Request._TYPE_SUPPORT is None:
                _slave_box_information_service.Metaclass_SlaveBoxInformationService_Request.__import_type_support__()
            if _slave_box_information_service.Metaclass_SlaveBoxInformationService_Response._TYPE_SUPPORT is None:
                _slave_box_information_service.Metaclass_SlaveBoxInformationService_Response.__import_type_support__()


class SlaveBoxInformationService(metaclass=Metaclass_SlaveBoxInformationService):
    from dronehive_interfaces.srv._slave_box_information_service import SlaveBoxInformationService_Request as Request
    from dronehive_interfaces.srv._slave_box_information_service import SlaveBoxInformationService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
