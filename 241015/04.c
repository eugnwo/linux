#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void parent_handle(int);

int main() {
	pid_t pid;
	struct sigaction act;
	act.sa_handler = parent_handle;
	sigfillset(&(act.sa_mask));
	sigaction(SIGCHLD, &act, NULL);
	
	pid = fork();

	if(pid == 0) {
		printf("[childe] set!\n");
		kill(getppid(), SIGCHLD);
		printf("[parent] bye\n");
	}
	sleep(2);
}

void parent_handle(int signum) {
	printf("signum : %d\n", signum);
	printf("[parent] bye!\n");
}
