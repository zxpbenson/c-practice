#include "apue.h"
//#include <stdio.h>
//#include <unistd.h>
#include <sys/wait.h>

int main(void){
  
  printf("pid = %ld\n", (long)getpid());

  char buf[MAXLINE]; //define in apue.h
  pid_t pid;
  int status;

  printf("%% ");
  while(fgets(buf, MAXLINE, stdin) != NULL){
    if(buf[strlen(buf) - 1] == '\n'){
      buf[strlen(buf) - 1] = 0;
    }
    if((pid = fork()) < 0){
      err_sys("fork error");
    }else if ( pid == 0){
      printf("sub process\n");
      //所有exec系列的函数在执行命令时所有堆栈都会新程序替代
      execlp(buf, buf, (char *)0);
      printf("after execlp %ld\n", (long)getpid());
      err_ret("couldn`t execute: %s", buf);
      printf("after err_ret %ld\n", (long)getpid());
      exit(127);
    }

    /* parent */
    if((pid = waitpid(pid, &status, 0)) < 0){
      err_sys("waitpid error");
    }
    printf("%%");
  }

  exit(0);
}

