/*
创建无名管道，用于父子进程间通信,在创建子进程之前创建无名管道
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = 0;
    int pipefd[2];//定义文件描述符，[0]是读端；[1]是写端。
    char c_buf[10];//缓冲区
    /*创建管道*/
    pipe(pipefd);

    /*创建子进程*/
    pid = fork();

    if(pid > 0)
    {
        /*父进程写入数据*/
        write(pipefd[1], "hello",6);
        wait(NULL);
        close(pipefd[1]);
        exit(0);
    }
    if(pid == 0)
    {
        /*子进程读取数据*/
        read(pipefd[0], c_buf, 6); 
        printf( "child read %s\n", c_buf);
        close(pipefd[0]);
        exit(0);
    }   
}
