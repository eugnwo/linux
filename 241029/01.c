#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define SIZE 512

int main() {
	int filedes[2];
	int msg[SIZE];
	pid_t pid;

	scanf("%d %d", &msg[0], &msg[1]);

	if(pipe(filedes) == -1) {
		printf("fail to call pipe()\n");
		exit(1);
	}
	 
	if((pid = fork()) == -1) {
		printf("fail to call fork()\n");
		exit(1);
	} 
	
	else if(pid > 0) {
		close(fd[0]);
		write(fd[1], msg, SIZE);
		sleep(3);
	}

	else {
		close(fd[1]);
		read(fd[0], msg, SIZE);
		printf("
	}
}	
