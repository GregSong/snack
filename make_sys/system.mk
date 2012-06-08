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
SNACK_BIN = ${SNACK_BASE}/bin

#Make
MAKE = make
# Compiler setting
CC = gcc
CXX = g++
INCLUDE_CASE = ${SNACK_TOOLS}/runc
INCLUDE_BASE = ${SNACK_BASE}/include
INCLUDE_COROUTINE = ${SNACK_LIB}/coroutine
CFLAGS = $(CC_DEBUG) $(INCLUDE_FLAGS) ${SHARED_FLAGS}

.SUFFIXS:
.SUFFIXS: .cc
.cc.o:
	$(CXX) -c $(CFLAGS) -o $@ $<

# Linkder setting
LINK = g++
LDFLAGS = 

SHARED_LDFLAGS = -shared
