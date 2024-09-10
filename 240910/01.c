#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);

	pid_t pid;
	pid = fork();
	int status, parent_sum = 1, child_sum = 0;

	if ((x >= 1 && x <= 10) || (y >= 1 && y <= 10)) {
		if (pid > 0) {
			for (int i = 1; i <= y; i++) {
				parent_sum *= x;
			}
			printf("parent: %d\n", parent_sum);
			wait(&status);
			status = status >> 8;
			printf("%d\n", parent_sum + status);
		} else if (pid == 0) {
			for (int i = x; i <= y; i++) {
				child_sum += i;
			}
			printf("child: %d\n", child_sum);
			exit(child_sum);
		} else {
			printf("err");
		}
	}
}
