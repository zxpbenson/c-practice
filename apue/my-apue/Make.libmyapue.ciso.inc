#%: %.o
#	echo "$(CC)    $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)" && \
#	$(CC)    $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
#
#%.o: %.s
#	$(CC) -c $(CFLAGS) $^ -o $@
#	
#%.s: %.i
#	$(CC) -S $(CFLAGS) $^ -o $@
#	
#%.i: %.c $(LIBMYAPUE)
#	$(CC) -E $(CFLAGS) $^ -o $@
	
%: %.c $(LIBMYAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

