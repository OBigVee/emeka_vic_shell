#include "shell.h"

/**
 * get_line - Gets line of user input
 * Return: Pointer to buffer of user input
 */

char *get_line(void)
{
	int temp;
	char *line = NULL;
	size_t size = 0;

	temp = getline(&line, &size, stdin);
	if (temp == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		exit(0);
	}
	return (line);
}
/**
 * split_line - Splits line into args
 * @line: Line of user input
 * Return: Array of args of user input
 */
char **split_line(char *line)
{
	size_t buffer_size = TOKENS_BUFFER_SIZE;
	char **tokens = malloc(sizeof(char *) * buffer_size);
	char *token;
	int pos = 0;

	if (!tokens)
	{
		perror("Could not allocate space for tokens\n");
		exit(0);
	}
	token = strtok(line, TOKEN_DELIMITERS);
	while (token)
	{
		tokens[pos] = token;
		token = strtok(NULL, TOKEN_DELIMITERS);
		pos++;
	}
	tokens[pos] = NULL;
	return (tokens);
}

/**
 * builtins_checker - Checks for builtins
 * @args: Arguments passed from prompt
 * Return: 1 if builtins exist, 0 if they don't
 */

int builtins_checker(char **args)
{
	int i;
	builtins_t list[] = {
		{"exit", exit_shell},
		{"env", env_shell},
		{NULL, NULL}
	};

	for (i = 0; list[i].arg != NULL; i++)
	{
		if (strcmp(list[i].arg, args[0]) == 0)
			return (1);
	}
	return (0);
}

/**
 * be_sure - Will check to see whether we are dealing with a builtin or not
 * @check: Figures out what to execute
 * @args: Arguments passed from cmdline broken up
 * Return: 1 if user entered a path/builtin, 2 if user entered a binary
 */

int be_sure(char *check, char **args)
{
	int i = 0;

	if (builtins_checker(args) == 1)
		return (1);
	while (check[i] != '\0')
	{
		if (check[i] == '/')
			return (1);
		i++;
	}
	return (2);
}

/**
 * check_for_builtins - Checks for builtins
 * @args: Arguments passed from prompt
 * @line: Buffer with line of input from user
 * @env: Environment
 * Return: 1 if builtins exist, 0 if they don't
 */

int check_for_builtins(char **args, char *line, char **env)
{
	builtins_t list[] = {
		{"exit", exit_shell},
		{"env", env_shell},
		{NULL, NULL}
	};
	int i;

	for (i = 0; list[i].arg != NULL; i++)
	{
		if (strcmp(list[i].arg, args[0]) == 0)
		{
			list[i].builtin(args, line, env);
			return (1);
		}
	}
	return (0);
}
