#!/bin/tcsh -f

# Get all case source files
set casesrc = (`find cases -name "main.cc" -prune -o -name "*.cc" -print`)

echo "#######################################" >! makefile
echo "#   Please DO NOT change this file" >> makefile
echo "#######################################" >> makefile
echo "" >> makefile
echo "#Make" >> makefile
echo "MAKE = make" >> makefile
echo "# Compiler setting" >> makefile
echo "CC = gcc" >> makefile
echo "CXX = g++" >> makefile
echo "INCLUDE_FLAGS = " >> makefile
echo 'CFLAGS = $(CC_DEBUG)' >> makefile
echo "" >> makefile
echo ".SUFFIXS:" >> makefile
echo ".SUFFIXS: .cc" >> makefile
echo ".cc.o:" >> makefile
echo '\t$(CC) -c $(CFLAGS) -o $@ $<' >> makefile
echo "" >> makefile
echo "# Linkder setting" >> makefile
echo "LINK = g++" >> makefile
echo "LDFLAGS = ">> makefile
echo "" >> makefile
echo "SHARED_LDFLAGS = -shared" >> makefile
echo "" >> makefile
echo 'SRC = case_base.cc \\' >> makefile
echo "      case_mgr.cc" >> makefile
echo "" >> makefile
echo 'OBJ = $(subst .cc,.o, $(SRC))' >> makefile
echo "" >> makefile
echo "TARGET = RC" >> makefile
echo "TARGET_LIB = RC.so ">> makefile
echo "">> makefile
echo "######################################" >> makefile
echo "# Generate CASEOBJ and Relevant target" >> makefile 
echo "######################################" >> makefile
echo "CASESRC = $casesrc" >> makefile
echo "" >> makefile 
echo 'CASEOBJ = $(subst .cc,.o, $(CASESRC))' >> makefile
echo "" >> makefile
echo 'ALL: $(OBJ) main.o' >> makefile

foreach s ( $casesrc )
    echo '\tcd '`dirname $s`';$(MAKE);cd ..;' >> makefile
end
echo '\t$(LINK) $(LDFLAGS) $(OBJ) main.o $(CASEOBJ) -o $(TARGET)' >> makefile 
echo "" >> makefile
echo 'LIB: $(OBJ)' >> makefile
echo '\t$(LINK) $(SHARED_LDFLAGS) $(OBJ) -o $(TARGET_LIB)' >> makefile
echo "" >> makefile
echo "CLEAN:" >> makefile
echo '\trm -f $(OBJ) main.o' >> makefile
echo '\trm -f $(TARGET)' >> makefile
echo '\trm -f $(TARGET_LIB)' >> makefile
foreach s ( $casesrc )
    echo '\tcd '`dirname $s`';$(MAKE) CLEAN;cd ..;'>> makefile 
end
echo "" >> makefile

