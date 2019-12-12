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

char ** semicolon_split(char *line) {
    char ** arr = malloc(sizeof(char*) * 10);
    int counter = 0;
    if (strchr(line, *";") == NULL) {
        char* str = strsep(&line, ";");
        arr[counter] = malloc(strlen(str));
        arr[counter] = str;
        counter++; 
    }
    else {
        while (line != NULL) {
            if (counter == 0){
                char* str = strsep(&line, ";");
                char* newstr = malloc(strlen(str) - 1);
                arr[counter] = malloc(strlen(str) - 1);
                for (int i = 0; i < (strlen(str) - 1); i++) {
                    newstr[i] = str[i];
                }
                arr[counter] = newstr;
                counter++;
            }
            else {
                if (strchr(line, *";") == NULL) {
                    char* str = strsep(&line, ";");
                    char* newstr = malloc(strlen(str) - 1);
                    arr[counter] = malloc(strlen(str) - 1);
                    for (int i = 0; i < (strlen(str) - 1); i++) {
                        newstr[i] = str[i + 1];
                    }
                    arr[counter] = newstr;
                    counter++;
                }
                else {
                    char* str = strsep(&line, ";");
                    char* newstr = malloc(strlen(str) - 2);
                    arr[counter] = malloc(strlen(str) - 2);
                    for (int i = 0; i < (strlen(str) - 2); i++) {
                        newstr[i] = str[i + 1];
                    }
                    arr[counter] = newstr;
                    counter++;
                }
            }
        }
    }
    arr[counter] = NULL;
    return arr;
}

void print_head() {
    char wd[100];
    printf("%s$ ", getcwd(wd, 100));
}

char * remove_newline(char *line) {
    for (int i = 0; i < 100; i++) {
        if (line[i] == '\n') line[i] = '\0';
    }
}

void execute(char **args) {
    if (execvp(args[0], args) < 0 && strcmp(args[0], "cd")) {
        printf("execvp() error: %s\n",strerror(errno));
    }
    exit(0);
}

void cd(char **args) {
    if (!strcmp(args[0], "cd")) {
        if (chdir(args[1]) < 0) {
            printf("chdir() error: %s\n",strerror(errno));
        }
    }
}

void run(char **args) {
    int pid = fork();
    if (pid < 0) printf("fork() error: %s\n",strerror(errno));

    if (pid > 0) {
        cd(args);
        wait(0);
    }

    if (pid == 0) {
        execute(args);
    }
}