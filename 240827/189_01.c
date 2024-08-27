#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	int n;

	scanf("%d", &n);

	pid_t pid;

	pid = fork();

	int sum;

	if (pid > 0) {
		sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += i;
		}
		printf("sum's result = %d\n", sum);
	} else if (pid == 0) {
		sum = 1;
		for (int i = 1; i <= n; i++) {
			sum *= i;
		}
		printf("mul's result = %d\n", sum);
	} else {
		printf("error\n");
	}
}
