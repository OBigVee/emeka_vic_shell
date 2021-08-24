#include "shell.h"

/**
 * shell - creates a simple shell
 * Return: void
 */

void shell(void)
{
	char *line;
	char **args;
	int status = 1;

	do {
		printf("shell>$");

		line = read_line();
		args = split_line(line);
		getcwd(args[0], 2);
		status = execve(args[0], args, NULL);
		if (status == -1)
		{
			perror("Error");
		}

	} while (status);
}

/**
 * read_line - read line from input
 * Return: line read
 */

char *read_line(void)
{
	char *line = "";
	size_t *n;

	n = malloc(3);
	getline(&line, n, stdin);
	return (line);
}

/**
 * split_line - tokenize line into words
 * @line: line to tokenize
 * Return: words
 */

char **split_line(char *line)
{
	int index = 0;
	char **words = malloc(sizeof(char *) * 256); 

	char *word = strtok(line, " \n");

	while (word != NULL)
	{
		words[index] = strdup(word);
		word = strtok(NULL, " ");
		index++;
	}
	return (words);
}
