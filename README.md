# C-SHELL
by Justin Chen and Samuel Fang

### Features:
	- Can execute commands given to the shell (cd works!)
	- Can read several commands using ;
	- Able to use redirection
	- One pipe works!!
### Extra Features:
	- Prints working directory
	- Can remove any extra white space
	- Can have more than one arg to the left of pipe
	  ex: ls -l | wc
### Attempted:
	- Catching incorrect inputs but there were too many cases to check for
### Bugs:
	- | and < or > cannot be used in the same line
	- Code only works for single pipes
	- Double redirect only works for the arg < arg > arg case
	- Code does not catch all unconventional input errors 
	  ex: ls ;; ls
	
### Files & Function Headers:
	run.c
	- Contains all functions
		- char ** parse_args(char *line)
			- separates arguments and removes white space between them
		- char ** semicolon_split(char *line)
			- separates commands and removes white space between them
		- char * take_out(char line[])
			- removes excess white space
		- void print_head()
			- prints working directory
		- char * remove_newline(char *line)
			- removes new line
		- void execute(char **args)
			- execute commands with their arguments
		- void cd(char **args)
			- executes cd
		- int * find_arrow(char **args)
			- returns array of locations of redirect arrows
		- int find_pipe(char **args)
			- finds location of pipe
		- char ** select_range(char **args, int max)
			- creates array of args left of redirect
		- void redirect(char **args)
			- redirects
		- void ppipe(char **args, int index)
			- pipes
		- void run(char **args)
			- forks and executes commands
	main.c
		- Runs the shell
