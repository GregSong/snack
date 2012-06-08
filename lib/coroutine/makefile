SNACK_BASE ?= undefine

ifeq (undefine, ${SNACK_BASE})
	$(error Please set SNACK_BASE to the snack dir)
endif

include ${SNACK_BASE}/make_sys/system.mk

INCLUDE_FLAGS = -I${INCLUDE_BASE}


SRC = coroutine_impl.cc

OBJ = $(subst .cc,.o, $(SRC))

TARGET = coroutine
TARGET_LIB = libcoroutine.so

ALL: LIB

LIB: $(OBJ) 
	$(LINK) $(SHARED_LDFLAGS) $(OBJ) -o $(TARGET_LIB)

clean:
	rm -f *.o
	rm -f $(TARGET)

install:
	rm -f $(SNACK_BASE)/bin/libcoroutine.so
	cp libcoroutine.so $(SNACK_BASE)/bin

