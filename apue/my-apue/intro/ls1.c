#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "myapue.h"

int
main(int argc, char *argv[])
{
	DIR *dp;/* dirent.h */
	struct dirent *dirp;/* dirent.h */

	if (argc != 2)
		err_quit("usage: ls directory_name");

	if ((dp = opendir(argv[1])) == NULL)/* dirent.h */
		err_sys("can't open %s", argv[1]);
	while ((dirp = readdir(dp)) != NULL)/* dirent.h */
		printf("%s\n", dirp->d_name);/* stdio.h */

	closedir(dp);/* dirent.h */
	exit(0);/* stdlib.h */
}
