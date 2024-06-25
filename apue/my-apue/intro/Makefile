ROOT = ..
PLATFORM = $(shell $(ROOT)/systype.sh)

include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = hello ls1 mycat getcputc shell1 null testerror flinkfilter

all : $(PROGS)
	
clean:
	rm -f $(PROGS) $(TEMPFILES)

include $(ROOT)/Make.libmyapue.ciso.inc

include $(ROOT)/Make.libmyapue.inc

