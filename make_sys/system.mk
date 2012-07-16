##################################################
#
#	This file contains very thing about compiler 
#	and linker
#
##################################################

SNACK_TOOLS = ${SNACK_BASE}/tools
SNACK_LIB = ${SNACK_BASE}/lib
SNACK_CASE = ${SNACK_TOOLS}/runc
SNACK_COROUTINE = ${SNACK_LIB}/coroutine
SNACK_OPTION = ${SNACK_LIB}/option
SNACK_BIN = ${SNACK_BASE}/bin
SNACK_PATTERN = ${SNACK_LIB}/pattern
SNACK_TIME = ${SNACK_LIB}/time
SNACK_LOGGER = ${SNACK_LIB}/log

#Make
MAKE = make
# Compiler setting
CC = gcc
CXX = g++
INCLUDE_CASE = ${SNACK_TOOLS}/runc
INCLUDE_BASE = ${SNACK_BASE}/include
INCLUDE_COROUTINE = ${SNACK_LIB}/coroutine
INCLUDE_TIME = ${SNACK_TIME}
INCLUDE_PATTERN = ${SNACK_PATTERN}
INCLUDE_LOGGER = ${SNACK_LOGGER}
CFLAGS = $(CC_DEBUG) $(INCLUDE_FLAGS) ${SHARED_FLAGS}

.SUFFIXS:
.SUFFIXS: .cc
.cc.o:
	$(CXX) -c $(CFLAGS) -o $@ $<

# Linkder setting
LINK = g++
LDFLAGS = 

SHARED_LDFLAGS = -shared

#LINK option
LIBCOROUTINE = -lcoroutine
LIBCASE      = -lRC
LIBOPTION    = -loption
LIBTIME      = -ltime
LIBLOGGER    = -llogger
