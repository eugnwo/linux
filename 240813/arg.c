#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fdin;
    ssize_t nread;
    char buffer[1024];

    char out[1024] = {0};
    int idx = 0;

    int cnt = 0;

    if(argc < 2) {
        return -1;
    }

    if ((fdin = open(argv[1], O_RDONLY)) == -1) {
        printf("file open error!\n");
        exit(1);
    }

    while ((nread = read(fdin, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < nread; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
               out[idx++] = buffer[i] -= 32;
             } else {
               out[idx++] = buffer[i];
             }
        }
    }

    close(fdin);
    printf("after str : %s", out);

    return 0;
}
