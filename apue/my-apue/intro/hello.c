#include <stdio.h>    /* printf */
#include <unistd.h>   /* getpid */
#include <stdlib.h>   /* exit */

int main(){
    /* stdio.h                                  unistd.h */
    printf("hello world from process ID %d\n", getpid());
    exit(0);/* stdlib.h */
}
