#Make
MAKE = make
# Compiler setting
CC = gcc
CXX = g++
INCLUDE_FLAGS = -I../..
CFLAGS = $(CC_DEBUG) $(INCLUDE_FLAGS)

.SUFFIXS:
.SUFFIXS: .cc
.cc.o:
	$(CC) -c $(CFLAGS) -o $@ $<

# Linkder setting
LINK = g++
LDFLAGS = 

SHARED_LDFLAGS = -shared

SRC = sample.cc 

OBJ = $(subst .cc,.o, $(SRC))

TARGET = sample
TARGET_LIB = 

ALL: $(OBJ)

EXE: $(OBJ) main.o ../../case_base.o ../../case_mgr.o
	$(LINK) $(LDFLAGS) $(OBJ) ../../case_base.o ../../case_mgr.o main.o -o $(TARGET)

CLEAN:
	rm -f *.o
	rm -f $(TARGET)
