#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "headers.h"
#include <ctype.h>

int main() {
    char input[100];
    char **args;
    char **splitargs;

    while (1) {
        print_head();

        fgets(input, 100, stdin);
        remove_newline(input);

        splitargs = semicolon_split(input);
        int i = 0;

        while (splitargs[i] != NULL) {
            args = parse_args(splitargs[i++]);

            if (!strcmp(args[0], "exit")) exit(0);
            run(args);
        }
    }
}
