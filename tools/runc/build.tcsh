#!/bin/tcsh -f

# Get all case source files
set casesrc = (`find cases -name "main.cc" -prune -o -name "*.cc" -print`)

echo "#######################################" >! makefile
echo "#   Please DO NOT change this file" >> makefile
echo "#######################################" >> makefile
echo "SNACK_BASE ?= undefine" >> makefile
echo 'ifeq (undefine, ${SNACK_BASE})' >> makefile
echo '$(error Please set SNACK_BASE to the snack dir)' >> makefile
echo "endif"  >> makefile
echo "" >> makefile
echo 'include ${SNACK_BASE}/make_sys/system.mk' >> makefile
echo "" >> makefile
echo 'INCLUDE_FLAGS = -I${INCLUDE_BASE} -I${SNACK_PATTERN}' >> makefile
echo "" >> makefile
echo 'LIB: SHARE_FLAGS = -fpic' >> makefile 
echo "" >> makefile
echo 'SRC = case_base.cc \\' >> makefile
echo "      case_mgr.cc" >> makefile
echo "" >> makefile
echo 'OBJ = $(subst .cc,.o, $(SRC))' >> makefile
echo "" >> makefile
echo "TARGET = RC" >> makefile
echo "TARGET_LIB = libRC.so ">> makefile
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
echo "install:" >> makefile
echo '\tcp libRC.so $(SNACK_BASE)/bin' >> makefile

