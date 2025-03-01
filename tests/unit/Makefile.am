#
# Copyright (c) 2018-2023, Amazon.com, Inc. or its affiliates. All rights reserved.
#
# See LICENSE.txt for license information
#

# Please remember to update .gitignore in this directory.

if ENABLE_UNIT_TESTS
AM_CPPFLAGS = -I$(top_srcdir)/include
AM_CPPFLAGS += -isystem $(abs_top_srcdir)/3rd-party/nccl/$(DEVICE_INTERFACE)/include
AM_CPPFLAGS += -isystem $(abs_top_srcdir)/3rd-party/uthash/include
LDADD = $(top_builddir)/src/libinternal_net_plugin.la
noinst_HEADERS = test-common.h

noinst_PROGRAMS = \
	deque \
	freelist \
	msgbuff \
	scheduler \
	idpool \
	ep_addr_list \
	mr

if WANT_PLATFORM_AWS
noinst_PROGRAMS += aws_platform_mapper
endif

if !ENABLE_NEURON
if WANT_PLATFORM_AWS
  AM_LDFLAGS = $(CUDA_LDFLAGS)
  AM_CPPFLAGS += $(CUDA_CPPFLAGS)
  LDADD += $(CUDA_LIBS)
  noinst_PROGRAMS += region_based_tuner
  region_based_tuner_SOURCES = region_based_tuner.c
  region_based_tuner_LDADD = $(top_builddir)/src/libinternal_tuner_plugin.la
endif
endif

idpool_SOURCES = idpool.c
deque_SOURCES = deque.c
freelist_SOURCES = freelist.c
msgbuff_SOURCES = msgbuff.c
scheduler_SOURCES = scheduler.c
ep_addr_list_SOURCES = ep_addr_list.c
mr_SOURCES = mr.c
aws_platform_mapper_SOURCES = aws_platform_mapper.c

TESTS = $(noinst_PROGRAMS)
endif
