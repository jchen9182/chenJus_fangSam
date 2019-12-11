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