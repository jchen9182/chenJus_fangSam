# SHELL
by Justin Chen and Samuel Fang

### Features:
	- Can execute commands given to the shell (cd works!)
	- Can read several commands using ;

### Extra Features:
	- Prints working directory

### Attempted:
	- 

### Bugs:
	- Spacing errors
	
### Files & Function Headers:
	run.c
  	- Contains all functions
		-char ** parse_args(char *line)
			-
		-char ** semicolon_split(char *line)
			-
		-void print_head()
			-
		-char * remove_newline(char *line)
			-
		-void execute(char **args)
			-
		-void cd(char **args)
			-
		-void redirect(char **args)
			-
		-void run(char **args)
  			-
	main.c
  	- Runs the shell
