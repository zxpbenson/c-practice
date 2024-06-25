#include "apue.h"

int main(int argc, char *argv[]){
  printf("%d\n", argc);
  for(int i = 0; i < argc; i++){
    printf("%s\n", argv[i]);
  }
  exit(0);
}

