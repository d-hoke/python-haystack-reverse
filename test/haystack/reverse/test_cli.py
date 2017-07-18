from __future__ import print_function

import logging
import unittest
import sys
try:
    from unittest import mock
except ImportError:
    import mock

from haystack.reverse import cli
from haystack.reverse import config

log = logging.getLogger("test_reverse_cli")


class TestReverseBasic(unittest.TestCase):

    def setUp(self):
        self.dumpname = 'dmp://./test/dumps/minidump/cmd.dmp'
        config.remove_cache_folder(self.dumpname)

    def tearDown(self):
        config.remove_cache_folder(self.dumpname)

    def test_reverse(self):
        testargs = ["haystack-reverse", self.dumpname]
        with mock.patch.object(sys, 'argv', testargs):
            # no exception
            cli.reverse()
            # test cache/headers_values.py
            # test cache/graph.gexf
            # test cache/graph.heaps.gexf
            # test cache/*.strings

    def test_reverse_hex(self):
        testargs = ["haystack-reverse-hex", self.dumpname, '0x543f60']
        # TODO, make a hexdump like output ?
        with mock.patch.object(sys, 'argv', testargs):
            cli.reverse_hex()
            # output is
            # b'USERPROFILE=C:\\Documents and Settings\\UserName\x00\x00'

    def test_reverse_parent(self):
        testargs = ["haystack-reverse-parents", self.dumpname, '0x543f60']
        with mock.patch.object(sys, 'argv', testargs):
            cli.reverse_parents()
            # not exception

    def test_reverse_show(self):
        testargs = ["haystack-reverse-show", self.dumpname, '0x543f60']
        with mock.patch.object(sys, 'argv', testargs):
            cli.reverse_show()
            # not exception


if __name__ == '__main__':
    logging.basicConfig(level=logging.INFO)
    unittest.main(verbosity=2)
