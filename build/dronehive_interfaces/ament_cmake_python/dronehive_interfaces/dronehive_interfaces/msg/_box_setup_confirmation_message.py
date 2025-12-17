# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dronehive_interfaces:msg/BoxSetupConfirmationMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BoxSetupConfirmationMessage(type):
    """Metaclass of message 'BoxSetupConfirmationMessage'."""

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
                'dronehive_interfaces.msg.BoxSetupConfirmationMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__box_setup_confirmation_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__box_setup_confirmation_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__box_setup_confirmation_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__box_setup_confirmation_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__box_setup_confirmation_message

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


class BoxSetupConfirmationMessage(metaclass=Metaclass_BoxSetupConfirmationMessage):
    """Message class 'BoxSetupConfirmationMessage'."""

    __slots__ = [
        '_confirm',
        '_box_id',
        '_landing_pos',
    ]

    _fields_and_field_types = {
        'confirm': 'boolean',
        'box_id': 'string',
        'landing_pos': 'dronehive_interfaces/PositionMessage',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['dronehive_interfaces', 'msg'], 'PositionMessage'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.confirm = kwargs.get('confirm', bool())
        self.box_id = kwargs.get('box_id', str())
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
        if self.confirm != other.confirm:
            return False
        if self.box_id != other.box_id:
            return False
        if self.landing_pos != other.landing_pos:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def confirm(self):
        """Message field 'confirm'."""
        return self._confirm

    @confirm.setter
    def confirm(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'confirm' field must be of type 'bool'"
        self._confirm = value

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
