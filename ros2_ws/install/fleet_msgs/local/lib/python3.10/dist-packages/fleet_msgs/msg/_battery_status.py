# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fleet_msgs:msg/BatteryStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BatteryStatus(type):
    """Metaclass of message 'BatteryStatus'."""

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
            module = import_type_support('fleet_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fleet_msgs.msg.BatteryStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__battery_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__battery_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__battery_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__battery_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__battery_status

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BatteryStatus(metaclass=Metaclass_BatteryStatus):
    """Message class 'BatteryStatus'."""

    __slots__ = [
        '_header',
        '_unit_id',
        '_soc_percentage',
        '_voltage_v',
        '_charging',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'unit_id': 'string',
        'soc_percentage': 'double',
        'voltage_v': 'double',
        'charging': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.unit_id = kwargs.get('unit_id', str())
        self.soc_percentage = kwargs.get('soc_percentage', float())
        self.voltage_v = kwargs.get('voltage_v', float())
        self.charging = kwargs.get('charging', bool())

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
        if self.header != other.header:
            return False
        if self.unit_id != other.unit_id:
            return False
        if self.soc_percentage != other.soc_percentage:
            return False
        if self.voltage_v != other.voltage_v:
            return False
        if self.charging != other.charging:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def unit_id(self):
        """Message field 'unit_id'."""
        return self._unit_id

    @unit_id.setter
    def unit_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'unit_id' field must be of type 'str'"
        self._unit_id = value

    @builtins.property
    def soc_percentage(self):
        """Message field 'soc_percentage'."""
        return self._soc_percentage

    @soc_percentage.setter
    def soc_percentage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'soc_percentage' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'soc_percentage' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._soc_percentage = value

    @builtins.property
    def voltage_v(self):
        """Message field 'voltage_v'."""
        return self._voltage_v

    @voltage_v.setter
    def voltage_v(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'voltage_v' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'voltage_v' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._voltage_v = value

    @builtins.property
    def charging(self):
        """Message field 'charging'."""
        return self._charging

    @charging.setter
    def charging(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'charging' field must be of type 'bool'"
        self._charging = value
