#include <stdio.h>
#include <string.h>
#include <errno.h>

void my_perror(const char *message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
}

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        my_perror("fopen");
    }

    fclose(f);
}