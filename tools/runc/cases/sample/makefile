SNACK_BASE ?= undefine
ifeq (undefine, ${SNACK_BASE})
	$(error Please set SNACK_BASE to the snack dir)
endif

include ${SNACK_BASE}/make_sys/system.mk
include ${SNACK_BASE}/make_sys/target.mk

INCLUDE_FLAGS = -I${INCLUDE_CASE} -I${INCLUDE_BASE} 

LDFLAGS = -L${SNACK_BIN}
LIBS = $(LIBCASE)

SRC = sample.cc 

OBJ = $(subst .cc,.o, $(SRC))

TARGET = sample
TARGET_LIB = 

ALL: $(OBJ)

EXE: $(OBJ) main.o 
	$(LINK) $(LDFLAGS) $(OBJ) main.o -o $(TARGET) $(LIBS)

CLEAN:
	rm -f *.o
	rm -f $(TARGET)
