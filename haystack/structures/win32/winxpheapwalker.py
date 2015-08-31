#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright (C) 2011 Loic Jaquemet loic.jaquemet+python@gmail.com
#

__author__ = "Loic Jaquemet loic.jaquemet+python@gmail.com"

import logging
import sys

import os

from haystack import model
from haystack.structures import heapwalker
from haystack.structures.win32 import winheapwalker

log = logging.getLogger('winxpheapwalker')


class WinXPHeapWalker(winheapwalker.WinHeapWalker):

    """
    Helpers functions that return pure python lists - no ctypes in here.

    Backend allocation in BlocksIndex
    FTH allocation in Heap.LocalData[n].SegmentInfo.CachedItems
    Virtual allocation
    """

    def _init_heap(self):
        self._allocs = None
        self._free_chunks = None
        self._child_heaps = None

        self._heap = self._heap_mapping.read_struct(self._heap_mapping.start, self._heap_module.HEAP)
        self._validator = self._heap_module.WinXPHeapValidator(self._memory_handler, self._heap_module_constraints, self._heap_module)
        if not self._validator.load_members(self._heap, 1):
            raise TypeError('load_members(HEAP) returned False')

        log.debug('+ Heap @%0.8x size: %d # %s',
                  self._heap_mapping.start, len(self._heap_mapping), self._heap_mapping)

        # placeholders
        self._backend_committed = None
        self._backend_free = None
        self._fth_committed = None
        self._fth_free = None
        self._valloc_committed = None
        self._valloc_free = None
        return


class WinXPHeapFinder(heapwalker.HeapFinder):
    """
    _init_heap_validation_depth = 1
    """

    def _init(self):
        """
        Return the heap configuration information
        :return: (heap_module_name, heap_class_name, heap_constraint_filename)
        """
        self._heap_validator = None
        module_name = 'haystack.structures.win32.winxpheap'
        heap_name = 'HEAP'
        constraint_filename = os.path.join(os.path.dirname(sys.modules[__name__].__file__), 'winxpheap.constraints')
        log.debug('constraint_filename :%s', constraint_filename)
        return module_name, heap_name, constraint_filename

    def _import_heap_module(self):
        """
        Load the module for this target arch
        :return: module
        """
        # replace the heapwalker version because we need to copy generated classes into the
        # normal module, for a specific target platform.
        # the win7heap module should not appears in sys.modules.
        if 64 == self._target.get_cpu_bits():
            gen_module_name = 'haystack.structures.win32.winxp_64'
        else:
            gen_module_name = 'haystack.structures.win32.winxp_32'
        log.debug('the heap module loaded is %s', gen_module_name)
        gen_heap_module = self._memory_handler.get_model().import_module(gen_module_name)
        heap_module = self._memory_handler.get_model().import_module(self._heap_module_name)
        # copy the generated module for x32 or x64 in a 'win7heap' module
        # FIXME, that is useless I think.
        model.copy_generated_classes(gen_heap_module, heap_module)
        return heap_module

    def get_heap_mappings(self):
        """return the list of _memory_handler that load as heaps"""
        heap_mappings = super(WinXPHeapFinder, self).get_heap_mappings()
        # FIXME PYDOC  cant remember why we do this.
        # we sort by Process HeapsListIndex
        #for mapping in heap_mappings:
            # why do we get the "children" segments ?
            #mapping._children = WinXPHeapWalker(
            #    self._memory_handler,
            #    self._heap_module,
            #    mapping,
            #    self._heap_module_constraints).get_heap_children_mmaps()
        heap_mappings.sort(
            key=lambda m: self._read_heap(m, m.get_marked_heap_address()).ProcessHeapsListIndex)
        return heap_mappings

    def get_heap_walker(self, heap):
        return WinXPHeapWalker(self._memory_handler, self._heap_module, heap, self._heap_module_constraints)

    def get_heap_validator(self):
        if self._heap_validator is None:
            self._heap_validator = self._heap_module.WinXPHeapValidator(self._memory_handler,
                                                   self._heap_module_constraints,
                                                   self._heap_module)
        return self._heap_validator