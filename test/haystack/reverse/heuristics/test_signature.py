#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright (C) 2011 Loic Jaquemet loic.jaquemet+python@gmail.com
#

from __future__ import print_function

import logging
import unittest

from haystack.mappings import folder

from haystack.reverse import context
from haystack.reverse.heuristics import signature, dsa, reversers, pointertypes
from test.testfiles import zeus_856_svchost_exe

log = logging.getLogger("test_reversers")


class TestTypeReverser(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.memory_handler = folder.load(zeus_856_svchost_exe.dumpname)
        cls.process_context = cls.memory_handler.get_reverse_context()
        fr = dsa.FieldReverser(cls.memory_handler)
        fr.reverse()
        tfc = dsa.TextFieldCorrection(cls.memory_handler)
        tfc.reverse()
        doublelink = reversers.DoubleLinkedListReverser(cls.memory_handler)
        doublelink.reverse()
        doublelink.rename_all_lists()
        pfr = pointertypes.PointerFieldReverser(cls.memory_handler)
        pfr.reverse()

    @classmethod
    def tearDownClass(cls):
        cls.memory_handler = None

    def test_doublelink(self):
        # we need a basic reversing first - see this UT class setUP
        address = 0xccd00
        _context = context.get_context_for_address(self.memory_handler, address)

        rev = signature.TypeReverser(self.memory_handler)
        # interesting records
        # SIG:T4i4P4P4i4z12
        # struct_bbf78 struct_a6518 struct_cca28
        # list goes from 0xccd28, 0xccd00 to 0x98268
        #_record = self._context.get_record_for_address(0xccd28)
        _record = _context.get_record_for_address(address)
        print("Before:")
        print(_record.to_string())
        self.assertEqual(_record.name, "struct_ccd00")
        rev.reverse_context(_context)
        _record = _context.get_record_for_address(address)
        print("After:")
        print(_record.to_string())
        self.assertEqual(_record.name, "mewingrazzes_ccd00")
        # TODO FIX LIST_ENTRY type
        pass


if __name__ == '__main__':
    logging.basicConfig(level=logging.INFO)
    # logging.getLogger("reversers").setLevel(logging.DEBUG)
    # logging.getLogger("reversers").setLevel(logging.DEBUG)
    # logging.getLogger("signature").setLevel(logging.DEBUG)
    # logging.getLogger("test_reversers").setLevel(logging.DEBUG)
    # logging.getLogger("structure").setLevel(logging.DEBUG)
    # logging.getLogger("dsa").setLevel(logging.DEBUG)
    # logging.getLogger("winxpheap").setLevel(logging.DEBUG)
    logging.getLogger("model").setLevel(logging.WARNING)
    unittest.main(verbosity=2)
