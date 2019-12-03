#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "headers.h"

char ** parse_args(char *line) {
    char ** arr = malloc(sizeof(char*) * 5);
    int counter = 0;

    while (line != NULL) {
        char* str = strsep(&line, " ");
        arr[counter] = malloc(strlen(str));
        arr[counter] = str;
        counter++;
    }
    arr[counter] = NULL;
    return arr;
}

int main() {
    char input[100];
    while (1) {
        for (int i = 0; i < 100; i++) {
            if (input[i] == '\n') input[i] = '\0';
        }
        printf("%s", input);
        if (!strcmp(fgets(input, 100, stdin), "exit")) break;
    }
    printf("OUTSIDEexit");
}
