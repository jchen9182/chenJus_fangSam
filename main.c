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

    while (1) {
        printf("> ");

        fgets(input, 100, stdin);
        for (int i = 0; i < 100; i++) {
            if (input[i] == '\n') input[i] = '\0';
        }
        args = parse_args(input);

        if (!strcmp(input, "exit")) exit(0);

        int pid = fork();
        if (pid < 0) printf("error: %s\n",strerror(errno));

        if (pid > 0) {
            if (!strcmp(input, "cd")) {
                if (chdir(args[1]) < 0) {
                    printf("chdir() error: %s\n",strerror(errno));
                }
            }
            wait(0);
        }

        if (pid == 0) {
            if (execvp(args[0], args) < 0 && strcmp(input, "cd")) {
                printf("execvp() error: %s\n",strerror(errno));
            }
            exit(0);
        }
    }
}
