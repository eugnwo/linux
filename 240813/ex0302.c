#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
 int filedes;
 //char pathname[] = "temp.txt";
		  /* "temp0.txt" 상대경로 */
 if((filedes = open("temp0.txt", O_CREAT | O_RDWR, 0644)) == - 1) {
  printf("file open error!\n");
  exit(1);
 }

 close(filedes);
}
