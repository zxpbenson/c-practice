#include <stdio.h>
#include <stdarg.h>

void va_list_demo(char *format, ...){
  va_list list;
  va_start(list, format);
  
  char* ch;
  while(1){
    ch = va_arg(list, char*);
    if(strcmp(ch, "") == 0){
      printf("\n");
      break;
    }
    printf(format, ch);
  }
  
  va_end(list);
}

int main(int argc, char* argv[]){
  if(argc == 4){
    va_list_demo(argv[1], argv[2], argv[3], "");
    exit(0);
  }
  sprintf(stderr, "argment count illeage\n");
  exit(1);
}


