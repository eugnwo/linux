#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	putenv("APPLE=BANANA");
	printf("%s\n", getenv("APPLE"));

	execl("ex0811", "ex0811", (char *)0);
}
