#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	execlp("/usr/bin/head", "head", argv[1], argv[2], argv[3], (char *)0);
}
