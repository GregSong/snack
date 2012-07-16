SNACK_BASE ?= undefine

ifeq (undefine, ${SNACK_BASE})
	$(error Please set SNACK_BASE to the snack dir)
endif

include ${SNACK_BASE}/make_sys/system.mk
include ${SNACK_BASE}/make_sys/target.mk

INCLUDE_FLAGS = -I${INCLUDE_BASE} -I${SNACK_PATTERN} -I${INCLUDE_LOGGER}


HEADERS = log_impl.h snack_log.h
SRC = log_impl.cc

OBJ = $(subst .cc,.o, $(SRC))

TARGET = logger
TARGET_LIB = liblogger.so

ALL: LIB

LIB: $(HEADERS) $(SRC) $(OBJ) 
	$(LINK) $(SHARED_LDFLAGS) $(OBJ) -o $(TARGET_LIB)

clean:
	rm -f *.o
	rm -f $(TARGET)

install:ALL
	rm -f $(SNACK_BASE)/bin/liblogger.so
	cp liblogger.so $(SNACK_BASE)/bin

