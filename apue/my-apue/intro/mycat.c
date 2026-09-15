/* 
   图 1-4
*/

#include "myapue.h"    /* err_sys, err_quit，通常内部已包含常用系统头文件 */
#include <unistd.h>    /* read, write, STDIN_FILENO, STDOUT_FILENO */
#include <stdlib.h>    /* exit */

#define BUFFSIZE 4096

int
main(void)
{
	int n;
	char buf[BUFFSIZE];
	
	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if(write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
	
	if(n < 0)
		err_sys("read error");

	exit(0);
}
