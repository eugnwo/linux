#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	printf("[ex08-06.c] PPID: %d, PID: %d\n", getppid(), getpid());
}
