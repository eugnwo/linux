#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	DIR *dirp;
	DIR *dirp2;
	int f_cnt = 0;
	int d_cnt = 0;

	struct dirent *dentry;

	if((dirp = opendir(argv[1])) == NULL) {
		exit(1);
	}
	
	while ((dentry = readdir(dirp))) {
		if (dentry -> d_ino != 0) {
			if ((dirp2 = opendir(dentry -> d_name)) == NULL) {
				f_cnt++;
			} 
			else {
				d_cnt++;
			}
		}
	}
	printf("file count = %d\n", f_cnt);
	printf("directory count = %d\n", d_cnt);
}
