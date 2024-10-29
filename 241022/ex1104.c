#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

#define SIZE 512

int main() {
	char *msg[] = {"apple is red", "banana is yellow", "cherry is red"};
	char buffer[SIZE];
	int filedes[2], nread, i;
	pid_t pid;

	if(pipe(filedes) == -1) {
		printf("fail to call pipe()\n");
		exit(1);
	}

	if((pid = fork()) == -1) {
		printf("fail to call fork()\n");
		exit(1);
	}

	else if (pid > 0) {
		for (i = 0; i < 3; i++) {
			strcpy(buffer, msg[i]);
			write(filedes[1], buffer, SIZE);
		}

		nread = read(filedes[0], buffer, SIZE);
		printf("[parent] %s\n", buffer);

		write(filedes[1], buffer, SIZE);
		printf("[parent] bye!\n");
	}
}
