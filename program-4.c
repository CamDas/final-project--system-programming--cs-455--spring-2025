#include <stdio.h>
#include <stdlib.h>

int initialized = 1;
int uninitialized;

int main() {

    char *str = malloc(1024 * sizeof(char));

    printf("End of program text address: %p\n", (void*)&main);

    printf("End of initialized data segment address: %p\n", (void*)&initialized);

    printf("End of uninitialized data segment address: %p\n", (void*)&uninitialized);

    free(str);

    return 0;
}
