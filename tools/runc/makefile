#######################################
#   Please DO NOT change this file
#######################################
SNACK_BASE ?= undefine
ifeq (undefine, ${SNACK_BASE})
$(error Please set SNACK_BASE to the snack dir)
endif

include ${SNACK_BASE}/make_sys/system.mk

LIB: SHARED_FLAGS = -fpic


SRC = case_base.cc \
      case_mgr.cc

OBJ = $(subst .cc,.o, $(SRC))

TARGET = RC
TARGET_LIB = libRC.so 

######################################
# Generate CASEOBJ and Relevant target
######################################
CASESRC = cases/sample/sample.cc cases/co/co.cc cases/co/coroutine.cc

CASEOBJ = $(subst .cc,.o, $(CASESRC))

ALL: $(OBJ) main.o
	cd cases/sample;$(MAKE);cd ..;
	cd cases/co;$(MAKE);cd ..;
	cd cases/co;$(MAKE);cd ..;
	$(LINK)  $(LDFLAGS) $(OBJ) main.o $(CASEOBJ) -o $(TARGET)

LIB: $(SRC) $(OBJ)
	$(LINK)  $(SHARED_LDFLAGS) $(OBJ) -o $(TARGET_LIB)

CLEAN:
	rm -f $(OBJ) main.o
	rm -f $(TARGET)
	rm -f $(TARGET_LIB)
	cd cases/sample;$(MAKE) CLEAN;cd ..;
	cd cases/co;$(MAKE) CLEAN;cd ..;
	cd cases/co;$(MAKE) CLEAN;cd ..;

install:
	cp libRC.so $(SNACK_BASE)/bin;
