#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    /* stdio.h                                  unistd.h */
    printf("hello world from process ID %d\n", getpid());
    exit(0);/* stdlib.h */
}
