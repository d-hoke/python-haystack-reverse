# -*- coding: utf-8 -*-
#
# TARGET arch is: ['-target', 'linux-i386']
# WORD_SIZE is: 4
# POINTER_SIZE is: 4
# LONGDOUBLE_SIZE is: 12
#
import ctypes




class struct_Node(ctypes.Structure):
    _pack_ = True # source:False
    _fields_ = [
    ('val1', ctypes.c_uint32),
    ('ptr2', ctypes.POINTER(None)),
     ]

__all__ = ['struct_Node']
