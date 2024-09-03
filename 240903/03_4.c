#include <stdio.h>
#include <unistd.h>

int main() {	
	char *argv[] = {"a.out", "a.txt", "b.txt", "c.txt", (char *)0};
	execvp("head", argv);
}
