# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dronehive_interfaces:msg/GuiCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GuiCommand(type):
    """Metaclass of message 'GuiCommand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'SEARCH_FOR_NEW_BOX': 0,
        'REMOVE_BOX': 1,
        'REQUEST_BOX_STATUS': 2,
        'REQUEST_LANDING': 3,
        'REQUEST_RETURN_HOME': 4,
        'REQUEST_TAKEOFF': 5,
        'REQUEST_ARMING': 6,
        'PATH_UPLOAD': 7,
        'REQUEST_LOG': 8,
        'TRACK_DRONE': 9,
        'REQUEST_EXECUTE_PATH': 10,
        'REQUEST_FULL_SYSTEM_STATUS': 11,
        'REQUEST_DRONE_STATUS': 12,
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
                'dronehive_interfaces.msg.GuiCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gui_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gui_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gui_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gui_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gui_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'SEARCH_FOR_NEW_BOX': cls.__constants['SEARCH_FOR_NEW_BOX'],
            'REMOVE_BOX': cls.__constants['REMOVE_BOX'],
            'REQUEST_BOX_STATUS': cls.__constants['REQUEST_BOX_STATUS'],
            'REQUEST_LANDING': cls.__constants['REQUEST_LANDING'],
            'REQUEST_RETURN_HOME': cls.__constants['REQUEST_RETURN_HOME'],
            'REQUEST_TAKEOFF': cls.__constants['REQUEST_TAKEOFF'],
            'REQUEST_ARMING': cls.__constants['REQUEST_ARMING'],
            'PATH_UPLOAD': cls.__constants['PATH_UPLOAD'],
            'REQUEST_LOG': cls.__constants['REQUEST_LOG'],
            'TRACK_DRONE': cls.__constants['TRACK_DRONE'],
            'REQUEST_EXECUTE_PATH': cls.__constants['REQUEST_EXECUTE_PATH'],
            'REQUEST_FULL_SYSTEM_STATUS': cls.__constants['REQUEST_FULL_SYSTEM_STATUS'],
            'REQUEST_DRONE_STATUS': cls.__constants['REQUEST_DRONE_STATUS'],
        }

    @property
    def SEARCH_FOR_NEW_BOX(self):
        """Message constant 'SEARCH_FOR_NEW_BOX'."""
        return Metaclass_GuiCommand.__constants['SEARCH_FOR_NEW_BOX']

    @property
    def REMOVE_BOX(self):
        """Message constant 'REMOVE_BOX'."""
        return Metaclass_GuiCommand.__constants['REMOVE_BOX']

    @property
    def REQUEST_BOX_STATUS(self):
        """Message constant 'REQUEST_BOX_STATUS'."""
        return Metaclass_GuiCommand.__constants['REQUEST_BOX_STATUS']

    @property
    def REQUEST_LANDING(self):
        """Message constant 'REQUEST_LANDING'."""
        return Metaclass_GuiCommand.__constants['REQUEST_LANDING']

    @property
    def REQUEST_RETURN_HOME(self):
        """Message constant 'REQUEST_RETURN_HOME'."""
        return Metaclass_GuiCommand.__constants['REQUEST_RETURN_HOME']

    @property
    def REQUEST_TAKEOFF(self):
        """Message constant 'REQUEST_TAKEOFF'."""
        return Metaclass_GuiCommand.__constants['REQUEST_TAKEOFF']

    @property
    def REQUEST_ARMING(self):
        """Message constant 'REQUEST_ARMING'."""
        return Metaclass_GuiCommand.__constants['REQUEST_ARMING']

    @property
    def PATH_UPLOAD(self):
        """Message constant 'PATH_UPLOAD'."""
        return Metaclass_GuiCommand.__constants['PATH_UPLOAD']

    @property
    def REQUEST_LOG(self):
        """Message constant 'REQUEST_LOG'."""
        return Metaclass_GuiCommand.__constants['REQUEST_LOG']

    @property
    def TRACK_DRONE(self):
        """Message constant 'TRACK_DRONE'."""
        return Metaclass_GuiCommand.__constants['TRACK_DRONE']

    @property
    def REQUEST_EXECUTE_PATH(self):
        """Message constant 'REQUEST_EXECUTE_PATH'."""
        return Metaclass_GuiCommand.__constants['REQUEST_EXECUTE_PATH']

    @property
    def REQUEST_FULL_SYSTEM_STATUS(self):
        """Message constant 'REQUEST_FULL_SYSTEM_STATUS'."""
        return Metaclass_GuiCommand.__constants['REQUEST_FULL_SYSTEM_STATUS']

    @property
    def REQUEST_DRONE_STATUS(self):
        """Message constant 'REQUEST_DRONE_STATUS'."""
        return Metaclass_GuiCommand.__constants['REQUEST_DRONE_STATUS']


class GuiCommand(metaclass=Metaclass_GuiCommand):
    """
    Message class 'GuiCommand'.

    Constants:
      SEARCH_FOR_NEW_BOX
      REMOVE_BOX
      REQUEST_BOX_STATUS
      REQUEST_LANDING
      REQUEST_RETURN_HOME
      REQUEST_TAKEOFF
      REQUEST_ARMING
      PATH_UPLOAD
      REQUEST_LOG
      TRACK_DRONE
      REQUEST_EXECUTE_PATH
      REQUEST_FULL_SYSTEM_STATUS
      REQUEST_DRONE_STATUS
    """

    __slots__ = [
        '_command',
        '_confirm',
        '_box_id',
    ]

    _fields_and_field_types = {
        'command': 'uint8',
        'confirm': 'boolean',
        'box_id': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.command = kwargs.get('command', int())
        self.confirm = kwargs.get('confirm', bool())
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
        if self.command != other.command:
            return False
        if self.confirm != other.confirm:
            return False
        if self.box_id != other.box_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def command(self):
        """Message field 'command'."""
        return self._command

    @command.setter
    def command(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'command' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'command' field must be an unsigned integer in [0, 255]"
        self._command = value

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
