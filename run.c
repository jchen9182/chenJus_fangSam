#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "headers.h"
#include <ctype.h>

char ** parse_args(char *line) {
    char ** arr = malloc(sizeof(char*) * 10);
    int counter = 0;

    while (line != NULL) {
        line = take_out(line);
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

    while (line != NULL) {
        char* str = strsep(&line, ";");
        arr[counter] = malloc(strlen(str));

        arr[counter] = take_out(str);
        counter++;
    }
    arr[counter] = NULL;
    return arr;
}

char * take_out(char line[]) {
    int i = 0;
    int num = 0;
    for (i = 0; line[i] != 0; i++){
        if (isspace(line[i])){
            num++;
        }
        else{
            break;
        }
    }
    char* newstr = malloc(strlen(line) - num);
    for (int i = 0; i < (strlen(line) - num); i++) {
        newstr[i] = line[i + num];
    }
    num = 0;
    for (i = strlen(newstr) - 1; line[i] != 0; i--){
        if (isspace(newstr[i])){
            num++;
        }
        else{
            break;
        }
    }
    char* newstr2 = malloc(strlen(newstr) - num);
    for (int i = 0; i < (strlen(newstr) - num); i++) {
        newstr2[i] = newstr[i];
    }
    return newstr2;

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
