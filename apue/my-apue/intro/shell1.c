#include "myapue.h"    /* 自定义头文件：MAXLINE、err_sys、err_ret 等 */
#include <stdio.h>     /* printf, fgets, stdin, NULL */
#include <string.h>    /* strlen */
#include <unistd.h>    /* fork, execlp, pid_t */
#include <sys/wait.h>  /* waitpid */
#include <stdlib.h>    /* exit */

int
main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
	
	printf("%% ");
	while(fgets(buf, MAXLINE, stdin) != NULL){
		if(buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;/* replace newline with null */
		
		if((pid = fork()) < 0){
			err_sys("fork error");
		}else if(pid == 0){
			execlp(buf, buf, (char *)0);
			err_ret("could not execute: %s", buf);
			exit(127);
		}
		
		/* parent */
		if((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		
		printf("%s : %d", buf, status);
		printf("%% ");
	}
	
	exit(0);
}
