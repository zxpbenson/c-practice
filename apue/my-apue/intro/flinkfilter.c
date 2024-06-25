#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 4096

int
main(void)
{
  int c;
  char buf[BUFFSIZE];
  int index = 0;
  int o_index = 0;
  
  while((c = getc(stdin)) != EOF){
    if(c == '\n' || index == BUFFSIZE){
      o_index = 0;
      while(o_index < index){
        putc(buf[o_index++], stdout);
      }
      putc('_', stdout);
      putc('m', stdout);
      putc('a', stdout);
      putc('r', stdout);
      putc('k', stdout);
      putc('\n', stdout);
      fflush(stdout);
      index = 0;
      continue;
    }
    buf[index++] = c;
  }
  
  if(ferror(stdin))
    perror("intput error\n");
  
  exit(0);
}
