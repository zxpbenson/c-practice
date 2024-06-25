# patsubst 替换文件后缀
# $(patsubst 原模式,目标模式,文件列表)
SRC_F=hello.c
PRE_F=$(patsubst %.c,%.i,$(SRC_F))
COL_F=$(patsubst %.i,%.s,$(PRE_F))
OBJ_F=$(patsubst %.s,%.o,$(COL_F))
TGT_F=$(patsubst %.o,%,$(OBJ_F))

show :
	@echo $(SRC_F)
	@echo $(PRE_F)
	@echo $(COL_F)
	@echo $(OBJ_F)
	@echo $(TGT_F)

clean :
	rm -f $(PRE_F)
	rm -f $(COL_F)
	rm -f $(OBJ_F)
	rm -f $(TGT_F)

#预处理
$(PRE_F) : $(SRC_F)
	$(CC) -E $^ -o $@

#生成汇编文件
$(COL_F) : $(PRE_F)
	$(CC) -S $^ -o $@

#汇编
$(OBJ_F) : $(COL_F)
	$(CC) -c $^ -o $@

#链接
$(TGT_F) : $(OBJ_F)
	$(CC) $^ -o $@

compile : $(TGT_F)

run : compile
	./$(TGT_F)


