#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

int num = 0;

int main() {
	static struct sigaction act;
	
	void int_handle(int);

	act.sa_handler = int_handle;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, NULL);

	while(1) {
		printf("i'm sleepy..\n");
		sleep(1);
		if(num >= 1) exit(0);
	}
}

void int_handle(int signum) {
	int filedes;
	if((filedes = open("a.txt", O_CREAT | O_RDWR, 0644)) == -1) {
		printf("error!\n");
		exit(1);
	}
	char buffer[] = "FINISH";
	write(filedes, buffer, sizeof(buffer));
	close(filedes);
	num++;
	//	printf("SIGINT:%d\n", signum);
	//	printf("int handle called %d times\n", ++num);
}
