#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 10

int main(int argc, char *argv[]) {
    int fd = open("README.md", O_RDWR);
    char buf[BUFFER_SIZE];

    if (fd != -1) {

        int seek = lseek(fd, (BUFFER_SIZE + 1652), SEEK_SET); //buffered from the beginning to get to the beginning of "Program 3"

        if (seek != -1) {
            ssize_t num_read = read(fd, buf, BUFFER_SIZE - 1);

            for (int i = 0; buf[i] != '\0'; i++) {
                buf[i] = toupper(buf[i]);
            }

            // Move back to the original position where we read from
            lseek(fd, -num_read, SEEK_CUR);
            ssize_t num_written = write(fd, buf, num_read);
        }
    }
    close(fd);
    return 0;
}
