# SHELL
by Justin Chen and Samuel Fang

### Features:
	- Can execute commands given to the shell (cd works!)
	- Can read several commands using ;

### Extra Features:
	- Prints working directory
	- Can remove any extra white space

### Attempted:
	- Working on |

### Bugs:
	- | and < or > cannot be used in the same line
	- Double redirect only works for the arg < arg > arg case
	
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
        	- char ** select_range(char **args, int max)
            		- creates array of args left of redirect
		- void redirect(char **args)
			- redirects
		- void run(char **args)
  			- forks and executes commands
	main.c
  	- Runs the shell
