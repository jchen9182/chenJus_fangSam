#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "headers.h"

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
        args = parse_args(input);
        if (!strcmp(input, "exit")) break;
        int pid = fork();
        if (pid < 0){
            printf("error: %s\n",strerror(errno));
        }
        if (pid > 0){
            wait(&status);
        }
        if (pid == 0){
            if (execvp(args[0], args) < 0){
                printf("error: %s\n",strerror(errno));
                break;
            }
        }
    }
}
