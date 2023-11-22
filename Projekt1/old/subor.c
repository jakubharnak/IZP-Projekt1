#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    char lines[MAX_LENGTH + 1] = {};
    while (fgets(lines, sizeof(lines), stdin) != NULL) {
        printf("%s", lines);
    }
   

    return 0;
}