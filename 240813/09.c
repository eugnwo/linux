#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fdin;
    ssize_t nread;
    char buffer[1];

    char out[1024] = {0};
    int idx = 0;

    int cnt = 0;

    if ((fdin = open("07_data.txt", O_RDONLY)) == -1) {
        printf("file open error!\n");
        exit(1);
    }

    while ((nread = read(fdin, buffer, sizeof(buffer))) > 0) {
            if (buffer[0] >= 'a' && buffer[0] <= 'z') {
               out[idx++] = buffer[0] -= 32;
             } else {
               out[idx++] = buffer[0];
             }
    }

    close(fdin);
    printf("after str : %s", out);

    return 0;
}
