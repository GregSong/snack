include system.mk

ALL: TOOLS LIBS

TOOLS:
	cd ${SNACK_TOOLS};make;

LIBS:
	cd ${SNACK_LIB};make LIB;


clean:
	cd $(SNACK_TOOLS);$(MAKE);
	cd $(SNACK_LIB);$(MAKE);

install:
	cd $(SNACK_TOOLS);$(MAKE) install;
	cd $(SNACK_LIB);$(MAKE) install;

