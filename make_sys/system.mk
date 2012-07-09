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

#Make
MAKE = make
# Compiler setting
CC = gcc
CXX = g++
INCLUDE_CASE = ${SNACK_TOOLS}/runc
INCLUDE_BASE = ${SNACK_BASE}/include
INCLUDE_COROUTINE = ${SNACK_LIB}/coroutine
INCLUDE_PATTERN = ${SNACK_PATTERN}
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
