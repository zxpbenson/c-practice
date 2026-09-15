#include "myapue.h"
#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* getuid, getgid */
#include <sys/types.h> /* uid_t, gid_t（可选，通常 unistd.h 间接包含 */

int 
main(void)
{
	printf("uid = %d, gid = %d", getuid(), getgid());
	exit(0);
}
