#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void my_assert(int num, int line, const char *message){
               
        fprintf(stderr, "assert: assert.c:%d: my_assert: %s '(num >= 0) && (num <= 100)' failed.\n", line, message);
        exit(1);
}

int main(int argc, char *argv[]){
    int num;
    int line;
    num = atoi(argv[1]);

    if (argc < 3){
        if(!((num >= 0) && (num <= 100))){ line = __LINE__;
        my_assert(num, line, "Assertion");
        }
    printf("my_assert: num = %d\n", num);
    }
}