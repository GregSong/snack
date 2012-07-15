SNACK_BASE ?= undefine

ifeq (undefine, ${SNACK_BASE})
	$(error Please set SNACK_BASE to the snack dir)
endif

include ${SNACK_BASE}/make_sys/system.mk

INCLUDE_FLAGS = -I${INCLUDE_BASE} -I${INCLUDE_CASE} -I${INCLUDE_COROUTINE} -I../ -I${INCLUDE_PATTERN} -I${INCLUDE_TIME}
LDFLAGS = -L${SNACK_CASE} -L${SNACK_COROUTINE} -L${SNACK_BIN} ${LIBS} 


SRC = main.cc

OBJ = $(subst .cc,.o, $(SRC))

LIBS = ${LIBCOROUTINE}  ${LIBCASE} ${LIBOPTION} ${LIBTIME}

TARGET = time
TARGET_LIB = 

ALL: $(OBJ) 
	$(LINK) $(OBJ) -o $(TARGET) $(LDFLAGS) 

clean:
	rm -f *.o
	rm -f $(TARGET)

include ${SNACK_BASE}/make_sys/target.mk
