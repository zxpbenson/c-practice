#include <stdio.h>    /* fprintf, stderr, perror */
#include <string.h>   /* strerror */
#include <errno.h>    /* errno, EACCES, ENOENT */
#include <stdlib.h>   /* exit */

int
main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES : %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}
