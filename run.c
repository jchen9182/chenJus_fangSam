#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "headers.h"

char ** parse_args(char *line) {
    char ** arr = malloc(sizeof(char*) * 10);
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
    char **args;
    int status;
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        for (int i = 0; i < 100; i++) {
            if (input[i] == '\n') input[i] = '\0';
        }
        if (!strcmp(input, "exit")) break;
        args = parse_args(input);
        int pid = fork();
        if (pid < 0){
            printf("error %s\n",strerror(errno));
        }
        if (pid == 0){
            printf("WAIT");
            wait(&status);
        }
    }
}
