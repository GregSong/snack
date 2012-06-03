#######################################
#   Please DO NOT change this file
#######################################

#Make
MAKE = make
# Compiler setting
CC = gcc
CXX = g++
INCLUDE_FLAGS = 
CFLAGS = $(CC_DEBUG)

.SUFFIXS:
.SUFFIXS: .cc
.cc.o:
	$(CC) -c $(CFLAGS) -o $@ $<

# Linkder setting
LINK = g++
LDFLAGS = 

SHARED_LDFLAGS = -shared

SRC = case_base.cc \
      case_mgr.cc

OBJ = $(subst .cc,.o, $(SRC))

TARGET = RC
TARGET_LIB = RC.so 

######################################
# Generate CASEOBJ and Relevant target
######################################
CASESRC = cases/sample/sample.cc cases/co/co.cc cases/co/coroutine.cc

CASEOBJ = $(subst .cc,.o, $(CASESRC))

ALL: $(OBJ) main.o
	cd cases/sample;$(MAKE);cd ..;
	cd cases/co;$(MAKE);cd ..;
	cd cases/co;$(MAKE);cd ..;
	$(LINK) $(LDFLAGS) $(OBJ) main.o $(CASEOBJ) -o $(TARGET)

LIB: $(OBJ)
	$(LINK) $(SHARED_LDFLAGS) $(OBJ) -o $(TARGET_LIB)

CLEAN:
	rm -f $(OBJ) main.o
	rm -f $(TARGET)
	rm -f $(TARGET_LIB)
	cd cases/sample;$(MAKE) CLEAN;cd ..;
	cd cases/co;$(MAKE) CLEAN;cd ..;
	cd cases/co;$(MAKE) CLEAN;cd ..;

