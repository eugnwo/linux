#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char **argv) {
	DIR *dirp;
	if((dirp = opendir(argv[1])) == NULL) {
		printf("not");
		exit(1);
	}
	printf("yes");
	closedir(dirp);
}
