DIRS = lib intro

all :
	for i in $(DIRS); do \
		(cd $$i && echo "making $$i" && $(MAKE)) || exit 1; \
	done

clean : 
	for i in $(DIRS); do \
		(cd $$i && echo "cleanning $$i" && $(MAKE) clean) || exit 1; \
	done

echo_sdt_v :
	@echo "MAKE = $(MAKE)"; \
	echo "COMPILE.c = $(COMPILE.c)"; \
	echo "COMPILE.C = $(COMPILE.C)"; \
	echo "LINK.c = $(LINK.c)"; \
	echo "LINK.C = $(LINK.C)"; \
	echo "CC = $(CC)"; \
	echo "GCC = $(GCC)"; \
	echo "LDFLAGS = $(LDFLAGS)"; \
	echo "LDDIR = $(LDDIR)"; \
	echo "LDLIBS = $(LDLIBS)"; \
	echo "CFLAGS = $(CFLAGS)"; \
	echo "RANLIB = $(RANLIB)"; \
	echo "AR = $(AR)"; \
	echo "AWK = $(AWK)"; \

