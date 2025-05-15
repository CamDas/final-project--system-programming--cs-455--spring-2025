#include <stdio.h>
#include <unistd.h>

int main() {

    pid_t ppid = getppid();

    FILE *fptr = fopen("filename.txt", "w"); //writes to new file the output

    fprintf(fptr, "Parent process ID: %d", ppid);

    fclose(fptr);

    return 0;
}
