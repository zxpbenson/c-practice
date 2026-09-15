/* 
   图 1-10
*/

#include "myapue.h"    /* 自定义头文件：MAXLINE、err_sys、err_ret 等 */
#include <stdio.h>     /* printf, fgets, stdin, NULL */
#include <string.h>    /* strlen */
#include <unistd.h>    /* fork, execlp, pid_t */
#include <sys/wait.h>  /* waitpid */
#include <stdlib.h>    /* exit */

static void  sig_int(int); /* our ignal-watching function */

int
main(void)
{
	char buf[MAXLINE]; /* from myapue.h */
	pid_t pid;
	int status;
	
	if(signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal error");

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

void sig_int(int signo)
{
	printf("interrupt \n%% ");
}
