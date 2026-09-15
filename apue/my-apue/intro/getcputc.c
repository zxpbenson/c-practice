#include "myapue.h"    /* err_sys */
#include <stdio.h>     /* getc, putc, stdin, stdout, EOF, ferror */
#include <stdlib.h>    /* exit */

int
main(void)
{
	int c;
	while((c = getc(stdin)) != EOF)
		if(putc(c, stdout) == EOF)
			err_sys("output error");
	
	if(ferror(stdin))
		err_sys("intput error");
	
	exit(0);
}
