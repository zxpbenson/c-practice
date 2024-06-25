#include <stdio.h>
#include <stdlib.h>
#include "myapue.h"

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
