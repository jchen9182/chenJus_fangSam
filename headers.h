char ** parse_args(char *line);
char ** semicolon_split(char *line);
char * take_out(char line[]);
void print_head();
char * remove_newline(char *line);
void execute(char **args);
void cd(char **args);
void redirect(char **args);
void run(char **args);
