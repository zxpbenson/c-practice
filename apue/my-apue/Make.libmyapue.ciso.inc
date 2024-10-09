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

# 原版本中每个子目录都有这一行相同的内容，我就把这一行提取到一个公共文件中了

%: %.c $(LIBMYAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

